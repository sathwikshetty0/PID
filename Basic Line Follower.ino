// Arduino Line Follower Robot Code


#define enA 3//Enable1 L293 Pin enA 

#define in1 6 //Motor1  L293 Pin in1 

#define in2 7 //Motor1  L293 Pin in2

#define in3 10 //Motor2  L293 Pin in1 

#define in4 11 //Motor2  L293 Pin in2

#define enB 9 //Enable2 L293 Pin enB 

#define R_S 4//ir sensor Right

#define L_S 2 //ir sensor Left

void setup(){ 

pinMode(R_S, INPUT); 

pinMode(L_S, INPUT); 

pinMode(enA, OUTPUT); 

pinMode(in1, OUTPUT); 

pinMode(in2, OUTPUT); 

pinMode(in3, OUTPUT); 

pinMode(in4, OUTPUT); 

pinMode(enB, OUTPUT); 

delay(1000);

}

void loop(){  

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){forward();}   //if Right Sensor and Left Sensor are at White color then it will call forward function

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){turnRight();} //if Right Sensor is Black and Left Sensor is White then it will call turn Right function  

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){turnLeft();}  //if Right Sensor is White and Left Sensor is Black then it will call turn Left function

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){Stop();} //if Right Sensor and Left Sensor are at Black color then it will call Stop function

}

void forward(){  //forword
	analogWrite(enA, 50);
	analogWrite(enB, 50);

digitalWrite(in1, HIGH); //Right Motor forward Pin 

digitalWrite(in2, LOW);  //Right Motor backward Pin 

digitalWrite(in3, HIGH);  //Left Motor forward Pin 

digitalWrite(in4, LOW); //Left Motor backward Pin 

}

void turnRight(){ //turnRight
	analogWrite(enA, 50);
	analogWrite(enB, 50);

digitalWrite(in1, LOW); //Right Motor forward Pin 

digitalWrite(in2, HIGH);  //Right Motor backward Pin 

digitalWrite(in3, HIGH); //Left Motor forward Pin 

digitalWrite(in4, LOW);  //Left Motor backward Pin 
}

void turnLeft(){ //turnLeft
	analogWrite(enA, 50);
	analogWrite(enB, 50);

digitalWrite(in1, HIGH);  //Right Motor forward Pin 

digitalWrite(in2, LOW); //Right Motor backward Pin  

digitalWrite(in3, LOW);  //Left Motor forward Pin 

digitalWrite(in4, HIGH); //Left Motor backward Pin 

}

void Stop(){ //stop

	analogWrite(enA, 0);
	analogWrite(enB, 0);

digitalWrite(in1, LOW); //Right Motor forward Pin 

digitalWrite(in2, LOW); //Right Motor backward Pin 

digitalWrite(in3, LOW); //Left Motor forward Pin 

digitalWrite(in4, LOW); //Left Motor backward Pin 

}
