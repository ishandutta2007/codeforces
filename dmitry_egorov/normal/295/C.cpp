#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <assert.h>

#define MPI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair
#define mod (1000000007)

using namespace std;

int D[210][50][50];
bool R[210][50][50];
int C[60][60];

int main()
{
  int i, j, k, t, l, w, x, n, a=0, b=0;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &w), w/=50;
  for (i=0; i<n; i++)
    scanf("%d", &x), (x==50)?(a++):(b++);
  for (i=0; i<60; i++)
    for (C[i][0]=1, j=1; j<=i; j++)
      C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
  D[0][a][b]=1, R[0][a][b]=1;
  for (i=0; i<205; i++)
  {
    if (R[i][0][0])
    {
      printf("%d\n%d\n", i, D[i][0][0]);
      return 0;
    }
    if (i%2==0)
    {
      for (j=0; j<=a; j++)
        for (k=0; k<=b; k++)
          if (R[i][j][k])
            for (l=0; l<=j; l++)
              for (t=0; l+2*t<=w && t<=k; t++)
                if (l+t)
                  R[i+1][j-l][k-t]=1, D[i+1][j-l][k-t]=(D[i+1][j-l][k-t]+D[i][j][k]*1ll*((C[j][l]*1ll*C[k][t])%mod))%mod;
    }
    else
    {
      for (j=0; j<=a; j++)
        for (k=0; k<=b; k++)
          if (R[i][j][k])
            for (l=0; l+j<=a; l++)
              for (t=0; l+2*t<=w && t+k<=b; t++)
                if (l+t)
                  R[i+1][j+l][k+t]=1, D[i+1][j+l][k+t]=(D[i+1][j+l][k+t]+D[i][j][k]*1ll*((C[a-j][l]*1ll*C[b-k][t])%mod))%mod;
    }
  }
  printf("-1\n0\n");
  return 0;
}