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
#define inf ((long long)1e18)

using namespace std;

int n, m;
long long A[2000][2000], D[2000][2000], S[2000][2000], ans=-inf;       

int main()
{
  int i, j;
  //freopen(".in", "r", stdin);
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    for (j=0; j<m; j++)
      scanf("%I64d", &A[i][j]);
  for (i=0; i<n; i++)
  {
    S[i][0]=A[i][0];
    for (j=1; j<m; j++)
      S[i][j]=S[i][j-1]+A[i][j];
  }
  for (i=0; i<2000; i++)
    for (j=0; j<2000; j++)
      D[i][j]=-inf;
  for (i=m-1; i>=0; i--)
    D[0][i]=max(D[0][i+1],S[0][i]);
  for (i=1; i<n; i++)
  {
    if (i%2==1)
    {
      D[i][0]=S[i][0]+D[i-1][1];
      for (j=1; j<m; j++)
        D[i][j]=max(D[i][j-1],S[i][j]+D[i-1][j+1]);
    }
    else
    {
      for (j=m-1; j>0; j--)
        D[i][j]=max(D[i][j+1],S[i][j]+D[i-1][j-1]);
    }
  }
  /*for (i=0; i<n; i++)
  {
    for (j=0; j<m; j++)
      printf("%I64d ", D[i][j]);
    printf("\n");
  }   */
  for (i=0; i<m; i++)
    ans=max(D[n-1][i],ans);
  printf("%I64d\n", ans);
  return 0;
}