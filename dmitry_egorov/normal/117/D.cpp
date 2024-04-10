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

using namespace std;

long long m;

pair <long long, long long> solve (long long n, long long r, long long u, long long v)
{
  u=max(u,1ll);
  v=min(v,n);
  if (r<=0ll)
    return mp(0,0);
  if (v<u)
    return mp(0,0);
  if (n==1ll)
  {
    if (u<=1ll && v>=1ll)
      return mp((1%m),1);
    return mp(0,0);
  }
  pair <long long, long long> res=mp(0ll,0ll), tmpp;
  long long tmp;  
  if (r>((n+1ll)/2ll))
  {
    tmp=v;
    res.second=(v+1ll)/2ll;
    if (!(v&1ll))
      tmp--;
    tmp=(tmp/2ll)+1ll;
    tmp%=m;
    res.first=tmp*tmp;
                                        
    tmp=u-1ll;
    res.second-=u/2ll;
    if (tmp!=0ll)
    {
      if (!(tmp&1ll))
        tmp--;
      tmp=(tmp/2ll)+1ll;
      tmp%=m;
      res.first-=tmp*tmp;
    }
    tmpp=solve(n/2ll,r-((n+1ll)/2ll),(u+1ll)/2ll,v/2ll);
    res.second+=tmpp.second, res.first+=2ll*tmpp.first;
    res.first=((res.first%m)+m)%m;
    //cerr<<"!!!!! "<<n<<" "<<r<<" "<<u<<" "<<v<<"   "<<res.first<<" "<<res.second<<endl;
    return res;
  }
  res=solve((n+1ll)/2ll,r,(u+2ll)/2ll,(v+1ll)/2ll);
  res.first=(((res.first*2ll-res.second)%m)+m)%m;
  //cerr<<"!!!!! "<<n<<" "<<r<<" "<<u<<" "<<v<<"   "<<res.first<<" "<<res.second<<endl;
  return res;
}

int main()
{
  long long n, l, r, u, v;
  int t;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%I64d%d%I64d", &n, &t, &m);
  while (t>0)
  {
    scanf("%I64d%I64d%I64d%I64d", &l, &r, &u, &v);
    printf("%I64d\n", ((solve(n,r,u,v)).first-(solve(n,l-1ll,u,v)).first+m)%m); 
    t--;
  }
  return 0;
}