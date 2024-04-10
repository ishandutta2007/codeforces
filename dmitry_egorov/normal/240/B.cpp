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

int res=inf, A[210], D[210][210*210][2], n, a, b, s;

int main()
{
  int i, j, k, nj, nk, d;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d%d%d", &n, &a, &b);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]), s+=A[i];
  for (i=0; i<=n; i++)
    for (j=0; j<=a; j++)
      for (k=0; k<2; k++)
        D[i][j][k]=inf;
  D[1][0][0]=0, D[1][A[0]][1]=0;
  for (i=1; i<n; i++)
    for (j=0; j<=a; j++)
      for (k=0; k<2; k++)
        if (D[i][j][k]<inf)
          for (nk=0; nk<2; nk++)
          {
            (k!=nk)?(d=min(A[i-1],A[i])):(d=0);
            (nk==1)?(nj=j+A[i]):(nj=j);  
            D[i+1][nj][nk]=min(D[i+1][nj][nk],D[i][j][k]+d);
          }
  for (i=0; i<=a; i++)
    if (s-i<=b)
      res=min(res,min(D[n][i][0],D[n][i][1]));
  if (res==inf)
    res=-1;
  printf("%d\n", res);
  return 0;
}