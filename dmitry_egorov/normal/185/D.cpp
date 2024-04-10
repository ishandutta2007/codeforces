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

long long k, l, r, p;

long long deg (long long v, long long d, long long mod)
{
  if (d==0ll)
    return 1ll;
  if (d&(1ll))
    return (deg(v,d-1ll,mod)*v)%mod;
  return deg((v*v)%mod,d/2ll,mod);
}

long long inv (long long v, long long mod)
{
  return deg(v,mod-2ll,mod);
}

int main()
{
  int tst;
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  for (scanf("%d", &tst); tst>0; tst--)
  {
    //cerr<<tst<<endl;
    scanf("%I64d%I64d%I64d%I64d", &k, &l, &r, &p);
    if (p==2ll)
    {
      (k%2ll==1ll)?(puts("0")):(puts("1"));
      continue;
    }
    long long res=(deg(k%p,deg(2ll,r+1ll,p-1ll),p)-1ll+p)%p;
    long long tmp=deg(k%p,deg(2ll,l,p-1ll),p);
    //cerr<<tmp<<endl;
    if (tmp==1ll)
      res=deg(2ll,r-l+1ll,p);
    else
      tmp=inv((tmp-1ll+p)%p,p), res*=tmp, res%=p;
//    cerr<<res<<endl;
    if (k%p==0)
      res=1ll;
    if (k%2ll==1ll)
      res*=inv(deg(2ll,r-l,p),p), res%=p;
    printf("%I64d\n", res);
  }
  return 0;
}