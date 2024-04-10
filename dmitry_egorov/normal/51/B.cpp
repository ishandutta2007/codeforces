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

int A[8000], e, Prev[8000], c=-1;
char s[8000], z, y;

int main()
{
  int i, l=0;
  //freopen(".in", "r", stdin);
  while (scanf(" %c", &z)==1)
    s[l]=z, l++;
  for (i=0; i<l; i++) 
  {
    if (s[i]=='<')
    {
      if (s[i+1]=='/')
      {
        if (s[i+3]=='a')
          c=Prev[c];
      }
      else
      {
        if (s[i+2]=='a')
          Prev[e]=c, c=e, e++;
        if (s[i+2]=='d')
          A[c]++;
      }
    }
  }
  sort(A,A+e);
  for (i=0; i<e; i++)
    printf("%d ", A[i]);
  printf("\n");  
  return 0;
}