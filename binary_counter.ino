#define START_PIN 8
#define BITS 6
#define DELAY_TIME 500

int current = START_PIN;


void setup() 
{
  // set up the light pins
  for (int i = START_PIN; i <= (START_PIN + BITS - 1); i++)
  {
    pinMode(i, OUTPUT);
  }
}



void loop() 
{
  for (int n = 1; n < pow(2, BITS); n++)
  {
    String binary = toBinary(n);

    for (int i = BITS - 1; i >= 0; i--)
    {
      if (binary[i] == '1')
      {
        digitalWrite((START_PIN + i), HIGH);
      }
      else
      {
        digitalWrite((START_PIN + i), LOW);
      }
    }

    delay(DELAY_TIME);
  }
}



String toBinary(int n)
{
  String result = "";
  
  for (int i = BITS - 1; i >= 0; i--)
  {
    int k = n >> i;
    if ((k & 1) > 0)
    {
      result += "1";
    }
    else
    {
      result += "0";
    }
  }
  return result;
}