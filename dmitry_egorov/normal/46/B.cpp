#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

//#define M_PI 3.141592653589793238462643
//#define eps 1e-8

using namespace std;

int k, A[60], t;
char s[10], l[5][10];

int main()
{
  int i, z;
  for (i=0; i<5; i++)
    scanf("%d", &A[10+i]);
  scanf("%d", &k);
  strcpy(l[0],"S");
  strcpy(l[1],"M");
  strcpy(l[2],"L");
  strcpy(l[3],"XL");
  strcpy(l[4],"XXL");
  for (i=0; i<k; i++)
  {
    scanf(" %s", &s);
    if (strcmp(s,"S")==0)
      t=0;
    if (strcmp(s,"M")==0)
      t=1;
    if (strcmp(s,"L")==0)
      t=2;
    if (strcmp(s,"XL")==0)
      t=3;
    if (strcmp(s,"XXL")==0)
      t=4;
    if (A[10+t]>0)
    {
      A[10+t]--;
      puts(l[t]);
      continue;
    }
    for (z=1; z<1000; z++)
    {
      if (A[10+t+z]>0)
      {
        puts(l[t+z]);
        A[10+t+z]--;
        break;
      }
      if (A[10+t-z]>0)
      {
        puts(l[t-z]);
        A[10+t-z]--;
        break;
      }
    }
  }
  return 0;
}