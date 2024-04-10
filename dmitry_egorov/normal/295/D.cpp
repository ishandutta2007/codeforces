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

#define mod (1000000007)

using namespace std;

typedef long long ll;

inline ll add (ll a, ll b)
{
  ll c=a+b;
  if (c>=mod)
    c-=mod;
  return c;
}

inline ll mul (ll a, ll b)
{
  return (a*b)%mod;
}

ll D[2100][2100], D2[2100][2100], res, sum;

int main()
{
  int n, m, i, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=2; i<=m; i++)
    D[0][i]=1, D2[0][i]=1;
  for (i=1; i<n; i++)
  {
    sum=0;
    for (j=2; j<=m; j++)
      sum=add(sum,D[i-1][j]), D[i][j]=add(D[i][j-1],sum);
    for (j=2; j<=m; j++)
      D[i][j]=add(D[i][j],1), D2[i][j]=add(D[i][j],mod-D[i-1][j]);// cerr<<i<<" "<<j<<" "<<D[i][j]<<" "<<D2[i][j]<<endl;
  }
  for (i=0; i<n; i++)
    for (j=2; j<=m; j++)
      res=add(res,mul(m-j+1,mul(D[i][j],D2[n-i-1][j])));
  printf("%I64d\n", res);
  return 0;
}