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

int A[100100], n, s, call, cnow;

int main()
{
  int i;
  scanf("%d", &n);
  for (i=0; i<n; i++)
  {
    scanf("%d", &A[i]);
    A[i]=-A[i];
    s+=A[i];
  }
  for (i=0; i<n; i++)
  {
    if (cnow+A[i]>0)
      cnow=0;
    else
    {
      cnow+=A[i];
      call=min(call,cnow);
    }
  }
  printf("%d\n", s-2*call); 
  return 0;
}