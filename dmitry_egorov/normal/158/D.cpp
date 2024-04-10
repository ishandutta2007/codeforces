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

int res=-inf, A[21000];

int main()
{
  int n, i, j, k, sum, d;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  for (d=1; d<=n; d++)
    if (n%d==0 && n/d>=3)
      for (j=0; j<d; res=max(res,sum), j++)
        for (sum=0, k=j; k<n; k+=d)
          sum+=A[k];
  printf("%d\n", res);
  return 0;
}