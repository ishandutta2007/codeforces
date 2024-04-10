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

int N[2];
long long A[2][1100], res;

int solve (int t)
{
  int i, j;
  long long tres=((long long)1e18), sum;
  int ret=-1;
  for (i=0; i<=N[t]; i++)
  {
    for (sum=0, j=0; j<N[t]; j++)
      sum+=4ll*A[t][j]*((1ll+2ll*j)-(2ll*i))*((1ll+2ll*j)-(2ll*i));
    if (tres>sum)
      tres=sum, ret=i;
  }
  res+=tres;
  return ret;
}

int main()
{
  int x, y, i, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  for (i=0; i<2; i++)
    scanf("%d", &N[i]);
  for (i=0; i<N[0]; i++)
    for (j=0; j<N[1]; j++)
      scanf("%d", &x), A[0][i]+=x, A[1][j]+=x;
  x=solve(0), y=solve(1);
  printf("%I64d\n%d %d\n", res, x, y);
  return 0;
}