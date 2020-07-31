unsigned long prev;
unsigned long duration;
unsigned long reset;
int i;
int a,b;
int d;
int count;
void setup() 
{
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,INPUT);
  pinMode(3,INPUT);
  Serial.begin(9600);
  prev=micros();
  reset=
  
  count=0;
  i=0;
}
void front();
void left();
void right();
void time_1();
int set();
void front_delayed();
void loop() 
{
  a=digitalRead(4);
  b=digitalRead(3);
  i=set();
  if(i==1)
  {
   time_1();
  if((a==1)&&(b==0))
  {
    front(); 
  }
  else if((a==0)&&(b==0))
  {
    left();
  }
  else if((a==1)&&(b==1))
  {
    right();
  }
  }

  
 
}
 void front()
 {
  analogWrite(10,100);
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  analogWrite(5,100);
  digitalWrite(7,HIGH);
  digitalWrite(6,LOW);

 }

 void right()
 {
  analogWrite(10,100);
  digitalWrite(9,HIGH);
  digitalWrite(8,LOW);
  analogWrite(5,100);
  digitalWrite(7,HIGH);
  digitalWrite(6,LOW);
  
 }
 void left()
 {
      analogWrite(10,100);
      digitalWrite(9,LOW);
      digitalWrite(8,HIGH);
      analogWrite(5,100);
      digitalWrite(7,LOW);
      digitalWrite(6,HIGH);
 }
 int set()
 {
  a=digitalRead(4);
  b=digitalRead(3);
  if(duration<10000000)
  {
  if((a==1)&&(b==0))
  {
    front(); 
  }
  else if((a==0)&&(b==0))
  {
    left();
  }
  else if((a==1)&&(b==1))
  {
    right();
  }
  duration=micros()-prev;
  Serial.println(duration);
  return 0;
  }
  else
  {
    Serial.println("returning 1");
    return 1;
  }
  }
  void time_1()
  {
    if(count==0)
    {
      Serial.println("in delay");
      analogWrite(5,0);
       analogWrite(10,0);
      delay(5000);
      count=count+1;
      Serial.println(count);
    }

 }

