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

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair
#define mod (1000000007ll)

using namespace std;

long long D[1100][1100], F[120000], C[2100][2100];
long long Cnk[1100][1100];

long long deg (long long v, int d)
{
  if (d<=0)
    return 1ll;
  if (d==1)
    return v;
  long long tmp=deg(v,d/2);
  tmp=(tmp*tmp)%mod;
  if (d%2==1)
    tmp=(tmp*v)%mod;
  return tmp;
}

int main()
{
  long long k, cnt, ans=0;
  int n, m, i, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%I64d", &m, &n, &k);
  D[0][0]=1;
  for (i=1; i<=1000; i++)
    for (j=1; j<=i; j++)
      D[i][j]=((long long)j)*D[i-1][j]+D[i-1][j-1], D[i][j]%=mod;
  for (i=0; i<2100; i++)
  {
    C[i][0]=1;
    for (j=1; j<2100; j++)
      C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
  }
  for (i=0; i<1050; i++)
    if (k-m+i>=0)
    {
      Cnk[i][0]=1;
      for (j=1; j<1050; j++)
        if (k-m+i-j+1ll>=0ll)
          Cnk[i][j]=(((long long)(k-m+i-j+1ll))*(deg(j,mod-2)))%mod, Cnk[i][j]=(Cnk[i][j]*Cnk[i][j-1])%mod;
    }
  i=3, j=2;
  //cerr<<((((long long)(k-m+i-j+1ll))*(deg(j,mod-2)))%mod)*Cnk[i][j-1]<<endl;
  //cerr<<(deg(2,mod-2)<<endl;
  //cerr<<Cnk[3][0]<<" "<<Cnk[3][1]<<" "<<Cnk[3][2]<<endl;
  F[0]=1;
  for (i=1; i<3000; i++)
    F[i]=(F[i-1]*((long long)i))%mod;
  if (n==1)
  {
    //if (k>m)
    //  printf("0\n");
    //else
      printf("%I64d\n", deg(k,m));
    return 0;
  }
  //for (k=0; k<
  for (i=1; i<=m && i<=k; i++)
    for (j=0; j<=i; j++)
    {
      if (2*i-j>k)
        continue;
      if (j==0 && n>2)
        continue;
      cnt=(deg(j,(n-2)*m)*Cnk[m][i])%mod;
      //cerr<<cnt<<" "<<Cnk[m][i]<<endl;
      cnt=(cnt*C[i][j])%mod;
      cnt=(cnt*Cnk[m-i][i-j])%mod;
      //cerr<<cnt<<" "<<Cnk[m-i][i-j]<<endl;
      cnt=(cnt*F[i])%mod;
      cnt=(cnt*F[i])%mod;
      //cerr<<D[m][i]<<endl;
      cnt=(cnt*D[m][i])%mod;
      cnt=(cnt*D[m][i])%mod;
      //cerr<<i<<" "<<j<<" "<<cnt<<endl;
      ans=(ans+cnt)%mod;
    }
  printf("%I64d\n", ans);
  return 0;
}