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

using namespace std;

long long Res[510];
int D[510][510], A[510][510], P[510];

int main()
{
  int i, j, k, n, x;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      scanf("%d", &A[i][j]);
  for (i=0; i<n; i++)
    scanf("%d", &x), P[n-i-1]=x-1;
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      D[i][j]=A[P[i]][P[j]];
  for (i=0; i<n; i++)
  {                           
    for (j=0; j<n; j++)
      for (k=0; k<n; k++)
        D[j][k]=min(D[j][k],D[j][i]+D[i][k]);
    for (j=0; j<=i; j++)
      for (k=0; k<=i; k++)
        Res[i]+=D[j][k];      
  }
  for (i=0; i<n; i++)
    printf("%I64d ", Res[n-i-1]);
  printf("\n");
  return 0;
}