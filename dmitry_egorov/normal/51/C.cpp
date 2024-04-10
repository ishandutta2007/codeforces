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
#define inf ((long long)1e10)

using namespace std;

long long A[300000], S[3];
bool B[300000], fl;
int n;

int main()
{
  int i, j;
  long long l, r, m;
  //freopen(".in", "r", stdin);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%I64d", &A[i]), A[i]*=2ll;
  sort(A,A+n);
  l=-1; r=inf;
  while (r-l>1ll)
  {
    m=(l+r+1ll)/(2ll);
    fl=1;
    memset(B,0,sizeof(B));
    S[0]=A[0]+m;
    for (i=0, j=1; i<n; i++)
    {
      if (S[j-1]+m<A[i] && j<=2)
        S[j]=A[i]+m, j++;
      if (j==3 && S[j-1]+m<A[i])
      {
        fl=0;
        break;
      } 
    }
    if (fl)
      r=m;
    else
      l=m;
  }
  S[0]=A[0]+r;
    for (i=0, j=1; i<n; i++)
    {
      if (S[j-1]+r<A[i] && j<=2)
        S[j]=A[i]+r, j++;
    }
  printf("%.2lf\n%.2lf %.2lf %.2lf\n", ((double)r)/2.0, ((double)S[0])/2.0, ((double)S[1])/2.0, ((double)S[2])/2.0); 
  return 0;
}