#include <stdio.h>
#include <stdlib.h>

#define LL "%I64d"

char number[60];
char nsize;
long long int tenpow[11];

void flip();
void tp();
long long int npow(int n, int pow);

int main()
{
  int n;
  scanf("%d", &n);
  tp();
  
  char c;
  scanf("%c", &c);
  int counter = 0;
  nsize = 0;
  while(true)
  {
    scanf("%c", &c);
    if(c>=48 && c<= 57)
    {
      number[nsize] = c-48;
      ++nsize;
    }
    else
      break;
  }

  flip();

//  printf("%d %d\n\n", number[0], number[1]);

  int begin = 0;
  int end = 0;
  int place=0;
  long long int sum=0;
  int innerp = 0;
  long long int total = 0;
  int maxlength = 1;
  for(int i=1;i<11;++i)
  {
    maxlength = i;
    if(tenpow[i] > n)
    {
      maxlength = i;
      break;
    }
  }

  while(true)
  {
    sum =0;
    innerp = 0;

      while(end < nsize && begin-end+1 <= maxlength) {
/*        if(number[end] == 0 && ((sum != 0 && begin != end)) )
        {
          begin = end;
          break;
        } */
        if(number[end] == 0 && sum == 0 && begin-end+1 == maxlength)
        {
          begin++;
          end = begin;
          sum = 0;
          break;
        }
        
        sum += tenpow[innerp]*number[end];
        if(sum >= n)
        {
          sum -= tenpow[innerp]*number[end];
          int oldb = begin;
          if(sum == 0)
          {
            begin++;
            end=begin;
          }
          begin = end;
          for(int i=end-1;i> oldb;--i)
          {
            if(number[i] == 0)
              begin = end = i;
            else
              break;
          }
          break;
        }
        ++innerp;
        ++end;
      }
    
    total += sum*npow(n, place);
    
    if(end >= nsize) 
      break;
    ++place;
  }

  printf(LL, total);
  printf("\n");
  
  return 0;
}

void flip()
{
  char p;
  for(int i=0;i<nsize/2;++i)
  {
    p=number[i];
    number[i] = number[nsize-1-i];
    number[nsize-1-i] = p;
  }
}

void tp()
{
  tenpow[0] = 1;
  for(int i=1;i<11;++i)
    tenpow[i] = tenpow[i-1]*10;
}

long long int npow(int n, int pow)
{
  long long int o = 1;
  for(int i=0;i<pow;++i)
    o*= n;
  return o;
}