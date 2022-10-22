#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=1e5+7;
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
ll T;
ll fac[N],inv[N];
ll C(ll x,ll y){
	if(y<0||x<y)return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
	scanf("%lld",&T);
	while(T--){
		ll n,k; scanf("%lld%lld",&n,&k);
		fac[0]=1;
		rep(i,n)fac[i]=fac[i-1]*i%mod;
		inv[n]=Pow(fac[n],mod-2);
		for(ll i=n;i;i--)inv[i-1]=inv[i]*i%mod;
		ll g=1,ans=0;
		rep(i,n){
			g=g*(n-i+1)%mod;
			ll ig=Pow(g,mod-2);
			ll t=fac[i]*C(n-(i-1)*(k-1),i)%mod;
			ans=(ans+t*ig)%mod;
		}
		printf("%lld\n",(ans+1)%mod);
	}
	return 0;
}