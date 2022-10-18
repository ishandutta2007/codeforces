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

long long deg (long long v, long long d)
{
  if (d==0)
    return 1;
  if (d&1ll)
    return (v*deg(v,d-1))%mod;
  return deg((v*v)%mod,d/2);
}

long long C[110][110], CF[110][110];
long long D[11000], ND[11000];

int main()
{
  int n, k, i, j, l;
  long long m;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin>>n>>m>>k;
  for (i=0; i<110; i++)
    for (C[i][0]=1ll, j=1; j<=i; j++)
      C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
  for (i=0; i<n; i++)
    for (j=0; j<=n; j++)
      CF[i][j]=deg(C[n][j],(m+n-1ll-i)/((long long)n));
  D[0]=1ll;
  for (i=0; i<n; i++)
  {
    for (j=max(0,k-(n-i)*n); j<=k; j++)
      for (l=0; l<=n; l++)
        ND[j+l]+=CF[i][l]*D[j], ND[j+l]%=mod;
    memcpy(D,ND,sizeof(D)), memset(ND,0,sizeof(ND));
  }
  cout<<D[k]<<endl;
  return 0;
}