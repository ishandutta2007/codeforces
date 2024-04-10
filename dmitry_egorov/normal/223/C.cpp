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

long long A[2100], C[2100], R[2100];
int n, k;

long long deg (long long v, int d)
{
  if (d==0)
    return 1ll;
  if (d&1)
    return (v*deg(v,d-1))%mod;
  return deg((v*v)%mod,d>>1);
}

void out ()
{
  for (int i=0; i<n; i++)
    printf("%I64d ", A[i]);
  printf("\n");
}

int main()
{
  int i, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &k);
  for (i=0; i<n; i++)
    scanf("%I64d", &A[i]);
  if (k==0)
  {
    out();
    return 0;
  }
  for (i=1; i<2100; i++)
    R[i]=deg(i,mod-2);
  for (i=0; i<2100; i++)
    for (C[i]=1, j=1; j<=i; j++)
      C[i]*=(k+i-j), C[i]%=mod, C[i]*=R[j], C[i]%=mod;
  for (i=n-1; i>=0; i--)
    for (j=n-1; j>i; j--)
      A[j]+=A[i]*C[j-i], A[j]%=mod;
  out();
  return 0;
}