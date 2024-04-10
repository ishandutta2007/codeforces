#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=4e5+7;
const ll mod=1e9+7;
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
ll fac[N],inv[N];
ll T,n;
ll C(ll x,ll y){return fac[x]*inv[y]%mod*inv[x-y]%mod;}
int main(){
	fac[0]=1;
	rep(i,N-1)fac[i]=fac[i-1]*i%mod;
	inv[N-1]=Pow(fac[N-1],mod-2);
	for(ll i=N-1;i;i--)inv[i-1]=inv[i]*i%mod;
	T=1;
	while(T--){
		scanf("%lld",&n);
		ll ans=0;
		rep0(i,n+1){
			ll x; scanf("%lld",&x);
			if(x)ans=(ans+C(x+i,x-1))%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}