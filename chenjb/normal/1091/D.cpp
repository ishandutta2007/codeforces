#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <cassert>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
#define inf 998244353
long long fac[1100000],n;
long long pw(long long x,long long y)
{
    long long ret=1;
    while (y)
    {
    	if (y&1)ret=ret*x%inf;
    	x=x*x%inf;
    	y>>=1;
    }
    return ret;
}
int main()
{
    cin>>n;
    fac[0]=1;rep(i,n)fac[i]=fac[i-1]*i%inf;
    long long ans=0;
    rep(i,n)ans=(ans+inf-1ll*fac[n]*pw(fac[i],inf-2)%inf)%inf;
    ans=(ans+fac[n]*n+1)%inf;
    cout<<ans<<endl;
}