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
#define inf ((int)1e9)

using namespace std;

int A[5000], n, t, B[5000], ans=inf;
char c;

int main()
{
  int i;
  scanf("%d", &n);
  for (i=1; i<=n; i++)
  {
    scanf(" %c", &c);
    if (c=='T')
      t++, A[i]=A[i-1]+1, B[i]=1;
    else
      A[i]=A[i-1];
  }
  for (i=n+1; i<=2*n; i++)
    A[i]=A[i-1]+B[i-n];
  for (i=0; i<n; i++)
    ans=min(ans,t-A[i+t]+A[i]);
  printf("%d\n", ans);
  return 0;
}