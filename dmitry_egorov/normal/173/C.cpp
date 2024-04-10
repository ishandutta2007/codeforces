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

int D[2][510][510][2], res=-inf;
int Sum[2][510][510];
int A[510][510];

int main()
{
  int i, j, len, n, m, fr, to;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    for (j=0; j<m; j++)
      scanf("%d", &A[i][j]);
  for (i=0; i<n; i++)
    for (j=0; j<m; j++)
    {
      Sum[0][i][j+1]=Sum[0][i][j]+A[i][j];
      //printf("0 %d %d %d\n", i, j, Sum[0][i][j+1]);
    }
  for (i=0; i<m; i++)
    for (j=0; j<n; j++)
    {
      Sum[1][i][j+1]=Sum[1][i][j]+A[j][i];
      //printf("1 %d %d %d\n", i, j, Sum[1][i][j+1]);
    }
  for (i=0; i<n; i++)
    for (j=0; j<m; j++)
      D[0][i][j][0]=A[i][j], D[0][i][j][1]=A[i][j];
  for (len=3, fr=0, to=1; len<=min(n,m); fr^=1, to^=1, len+=2)
    for (i=0; i<=n-len; i++)
      for (j=0; j<=m-len; j++)
      {
        D[to][i][j][0]=D[fr][i+2][j][1]+Sum[0][i][j+len]-Sum[0][i][j]+Sum[1][j+len-1][i+len]-Sum[1][j+len-1][i+1]+A[i+len-1][j+len-2];
        D[to][i][j][1]=D[fr][i][j+2][0]+Sum[0][i+len-1][j+len]-Sum[0][i+len-1][j]+Sum[1][j][i+len-1]-Sum[1][j][i]+A[i][j+1];
        res=max(res,D[to][i][j][0]);
      }
  printf("%d\n", res);
  return 0;
}