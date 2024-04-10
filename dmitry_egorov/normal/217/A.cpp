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

int res=-1, X[110], Y[110];
bool D[110][110], u[110];

int main()
{
  int n, i, j, k;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d%d", &X[i], &Y[i]);
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      if (X[i]==X[j] || Y[i]==Y[j])
        D[i][j]=1;
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      for (k=0; k<n; k++)
        if (D[j][i] && D[i][k])
          D[j][k]=1;
  for (i=0; i<n; i++)
    if (!u[i])
    {
      res++;
      for (j=0; j<n; j++)
        if (D[i][j])
          u[j]=1;
    }
  printf("%d\n", res);
  return 0;
}