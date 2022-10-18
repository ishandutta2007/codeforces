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

int A[120][120], ans, n, P[120], D[120];

int main()
{
  int i, x, j, k;
  //freopen (".in", "r", stdin);
  scanf("%d", &n);
  for (i=0; i<n; i++)
  {
    scanf("%d", &P[i]);
    P[i]--;
  }
  for (i=0; i<n; i++)
  {
    scanf ("%d", &x);
    if (i+x<n)
    {
      A[i][i+x]=1;
      A[x+i][i]=1;
    }
    if (i-x>=0)
    {
      A[i][i-x]=1;
      A[i-x][i]=1;
    }
  }
  for (i=0; i<n; i++) 
    D[i]=i;
  for (i=0; i<n+5; i++)
  {
    for (j=0; j<n; j++)
    {
      for (k=0; k<n; k++)
      {
        if (A[j][k]==1)
          D[k]=min(D[k],D[j]);
      }
    }
  }
  //for (i=0; i<n; i++)
  //  printf("D[%d]=%d\n", i, D[i]);
  for (i=0; i<n; i++)
  {
    if (D[i]!=D[P[i]])
      ans=1;
  }
  if (ans==1)
    printf("NO");
  else
    printf("YES");
  return 0;
}