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

int B[400], A[400][400];

int main()
{
  int n, i, j, b, res, id, x;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      scanf("%d", &x), A[i][x-1]=j;
  for (i=0; i<n; i++)
    scanf("%d", &x), B[x-1]=i;
  for (i=0; i<n; i++)
  {
    res=inf, id=-1, b=inf;
    for (j=0; j<n; j++)
    {
      if (i==j)
        continue;
      b=min(b,B[j]);
      if (b==B[j] && res>A[i][j])
        res=A[i][j], id=j;
    }
    printf("%d ", id+1);
  }
  printf("\n");
  return 0;
}