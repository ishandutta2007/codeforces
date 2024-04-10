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

int cntnl, C[3000];
long long Res[3000], NRes[3000];
long long F[110000];

bool luck (int a)
{
  int res=0ll, cnt=0;
  while (a>0)
  {
    if ((a%10)!=4 && (a%10)!=7)
      return 0;
    if ((a%10)==7)
      res+=(1<<cnt);
    a/=10, cnt++;
  }
  res+=(1<<cnt);
  C[res]++;
  return 1;
}

long long deg (long long v, int d)
{
  if (d==1)
    return v;
  long long tmp=deg((v*v)%mod,d/2);
  if (d&1)
    return (tmp*v)%mod;
  return tmp;
}

long long Cnk (int n, int k)
{
  return (F[n]*deg((F[k]*F[n-k])%mod,mod-2))%mod;
}

int main()
{
  int i, n, k, x, j;
  long long res=0ll;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &k);
  for (i=0; i<n; i++)
  {
    scanf("%d", &x);
    if (!luck(x))
      cntnl++;
  }
  for (F[0]=1ll, i=1; i<110000; i++)
    F[i]=(F[i-1]*((long long)i))%mod;
  for (Res[0]=1ll, i=0; i<2150; i++)
  {
    memset(NRes,0,sizeof(NRes));
    for (j=0; j<2150; j++)
      NRes[j]+=Res[j], NRes[j+1]+=Res[j]*((long long)C[i]);
    memcpy(Res,NRes,sizeof(Res));
    for (j=0; j<2150; j++)
      Res[j]%=mod;
  }
  for (i=max(0,k-cntnl); i<=min(2150,k); i++)
    res+=Cnk(cntnl,k-i)*Res[i], res%=mod;
  printf("%d\n", (int)res);
  return 0;
}