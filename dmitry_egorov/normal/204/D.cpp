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

int n, k;
char s[1234567];
long long S[1234567], F[2][1234567];
long long D[1234567];
int X[1234567], B[1234567];

void cr (int v, char c)
{
  memset(X,0,sizeof(X));
  memset(B,0,sizeof(B));
  int i;
  for (i=1; i<=n; i++)
  {
    X[i]=X[i-1], B[i]=B[i-1];
    if (s[i-1]=='X')
      X[i]++;
    if (s[i-1]!='X' && s[i-1]!=c)
      B[i]++;
  }
  long long mn1=0ll, mn2=0ll;
  for (i=k; i<=n; i++)
  {
    if (B[i]==B[i-k])
      F[v][i]=(D[X[i-k]]-mn1-mn2+10ll*mod)%mod;
    if (s[i-k]=='X')
      mn1*=2ll;
    mn1+=F[v][i-k+1], mn1%=mod;
    mn2+=mod-F[v][i-k+1], mn2+=F[v][i], mn2%=mod;
  }
}

int main()
{
  int i;
  long long res=0;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d ", &n, &k);
  for (D[0]=1ll, i=1; i<1234567; i++)
    D[i]=(D[i-1]*2ll)%mod;
  gets(s), cr(0,'B');
  reverse(s,s+n), cr(1,'W');
  for (i=1; i<=n; i++)
  {
    S[i]=S[i-1];
    if (s[i-1]=='X')
      S[i]*=2ll;
    S[i]+=F[1][i], S[i]%=mod;
  }
  for (i=1; i<=n; i++)
    res+=S[i]*F[0][n-i], res%=mod;
  cout<<res<<endl;
  return 0;
}