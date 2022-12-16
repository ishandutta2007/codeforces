/* A. Clear Symmetry (127)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

/*
int maxeven(int in)
{
  return 4*((n/2)/2)*((n/2)/2);
}
int maxoddodd(int in)
{
  if((in/2)%2 == 1)
  {
    return (in/2-1)*2 + 4*(((in/2)/2+1)*((in/2)/2+1)+ ((in/2)/2)*((in/2)/2)) + 1;
  }
  else
  {
  }
}
int maxoddeven(int in)
{
  
}*/

int altFill(int number, int rbio)
{
  if(number == 0)
    return 0;
  if(number == 1)
  {
    if(rbio)
      return 0;
    else
      return 1;
  }

  if(rbio == 1)
  {
    return 2*((number-1)/2) + altFill(number-1, 0);
  }
  else
  {
    return 2*((number-1)/2+1)+altFill(number-1, 1);
  }
}

int main()
{
  int input;
  scanf("%d", &input);

  if(input == 3)
    printf("5\n");
  else
  {
    int i=0;
    int amt=0;
    while(amt < input)
    {
      ++i;
      amt = 1 + 4*((i-1)/2) + 4*altFill(i-1, 0);
    }
    printf("%d\n", i*2-1, amt);
  }

  return 0;
}