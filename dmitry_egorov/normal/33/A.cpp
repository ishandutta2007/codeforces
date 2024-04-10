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
#define inf (int)1e9

using namespace std;

int n, m, k, a[1010];

int main()
{
  int i, x, y;
  scanf("%d%d%d", &n, &m, &k);
  for (i=0; i<m; i++)
    a[i]=inf; 
  for (i=0; i<n; i++)
  {
    scanf("%d%d", &x, &y);
    a[x-1]=min(a[x-1],y);
  }
  n=0;
  for (i=0; i<m; i++)
    n+=a[i];
  printf("%d\n", min(k,n)); 
  return 0;
}