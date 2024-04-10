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
#define maxk 300

using namespace std;

int A[110000], n, m;
int Cnt[110000];
int B[maxk], e;
int F[maxk][100100];
int G[maxk][100100];

int main()
{
  int n, m, i, j, res, l, r;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
  {
    scanf("%d", &A[i]);
    if (A[i]<=n)
      Cnt[A[i]]++;
  }
  for (i=1; i<maxk; i++)
    for (j=0; j<n; j++)
      F[i][j+1]=(F[i][j]+((int)(A[j]==i)));
  for (i=maxk; i<=n; i++)
    if (Cnt[i]>=i)
    {
      B[e]=i;
      for (j=0; j<n; j++)
        G[e][j+1]=(G[e][j]+((int)(A[j]==i)));
      e++;
    }
  while (m>0)
  {
    scanf("%d%d", &l, &r), l--, m--;
    res=0;
    for (i=1; i<maxk; i++)
      if (F[i][r]-F[i][l]==i)
        res++;
    for (i=0; i<e; i++)
      if (G[i][r]-G[i][l]==B[i])
        res++;
    printf("%d\n", res);
  }
  return 0;
}