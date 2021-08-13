const int motionSensor = 2;         // signal pin of the PIR motion sensor
const int tiltSensor = 3;			// pin for the tilt sensor
const int led = 7;			      	//set up for the red led
const int led_green = 13;         	// set up for green led 

//stating the state of both the sensor
uint8_t motionState = LOW;			
uint8_t tiltState = LOW;


void setup() {  
  
  //setting up the devices as input or output
  
  
  pinMode(led,OUTPUT);
  pinMode(led_green,OUTPUT);
  
  pinMode(tiltSensor, INPUT_PULLUP);	//setting tilt sensor as input
  pinMode(motionSensor, INPUT);    //setting PIR motion sensor as input 
  
  Serial.begin(9600);        // initialize serial monitor
  
  //function which does the main job!!
  
  attachInterrupt(digitalPinToInterrupt(motionSensor), motion, HIGH);
  attachInterrupt(digitalPinToInterrupt(tiltSensor), tilt, HIGH);

}

void loop(){
  
  delay(200);
  
}

void motion(){
  motionState = !motionState;   // motionState is assigned oppositre value
  Serial.println("Motion detected!");
  digitalWrite(led_green, motionState);
  Serial.println("Green LED Blinked!(PIR motion sensor)");

}

void tilt(){
  tiltState = !tiltState;	// motionState is assigned oppositre value
  Serial.println("Tilted!");
  digitalWrite(led, tiltState);
  Serial.println("Red LED Blinked! (for tilt sensor)");
  
}
