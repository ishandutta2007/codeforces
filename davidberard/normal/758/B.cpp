#include <stdio.h>
#include <stdlib.h>

char types[4];
void setType(int pos, char type)
{
  if(types[pos] == type)
  {
  }
  else {
    for(int i=0;i<4;++i)
    {
      if(types[i] == type)
      { // swap
        char plc = types[pos];
        types[pos] = type;
        types[i] = plc;
//        printf("At %d, %c: at %d, %c\n", pos, type, i, plc);
        break;
      }
    }
  }
}

int getIndex(char c)
{
  for(int i=0;i<4;++i)
  {
    if(types[i] == c)
      return i;
  }
  return -1;
}

int main()
{
  types[0] = 'R';
  types[1] = 'G';
  types[2] = 'B';
  types[3] = 'Y';

  char c;
  int deadcount[4] = {0,0,0,0};
  int lcount = 0;
  while(true)
  {
    scanf("%c", &c);
    if(c == 'R' || c == 'B' || c == 'Y' || c == 'G' || c == '!')
    {
      if(c == '!')
      {
        deadcount[lcount%4]++;
      }
      else
        setType(lcount%4, c);
      ++lcount;
    }
    else
      break;
  }
  
  char stuff[] = "RBYG";
  //r b y g
  for(int i=0;i<4;++i)
    printf("%d ", /*stuff[i], getIndex(stuff[i]),*/ deadcount[getIndex(stuff[i])]);

  printf("\n");

  return 0;
}