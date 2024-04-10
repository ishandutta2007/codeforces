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

int main()
{
  int i, n, c=0;
  scanf("%d", &n);
  for (i=1; i<n; i++)
    c+=i, c%=n, printf("%d ", c+1);
  printf("\n");
  return 0;
}