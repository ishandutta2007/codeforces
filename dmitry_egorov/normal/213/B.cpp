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
#define mod (1000000007ll)

using namespace std;

int A[10], B[10];
long long C[110][110];
long long D[11][110];

long long calc (int n)
{
  int i, j, k;
  memset(D,0,sizeof(D));
  D[0][0]=1ll;
  for (i=0; i<10; i++)
    for (j=0; j<=n; j++)
      if (D[i][j])
        for (k=A[i]; k+j<=n; k++)
          D[i+1][k+j]+=C[k+j][k]*D[i][j], D[i+1][k+j]%=mod;
  return D[10][n];
}

int main()
{
  int res=0, n, i, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (C[0][0]=1ll, i=1; i<110; i++)
    for (C[i][0]=1ll, j=1; j<110; j++)
      C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
  for (i=0; i<10; i++)
    scanf("%d", &A[i]), B[i]=A[i];
  while (n>0)
    for (n--, i=1; i<10; i++)
      A[i]=max(0,B[i]-1), res+=calc(n), res%=mod, A[i]=B[i];
  printf("%d\n", res);
  return 0;
}