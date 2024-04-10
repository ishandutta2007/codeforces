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
const ll N=2e5+7;
const ll INF=1e9+7;
const ll mod=998244353;
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
ll n,k,ans=0,tot=0;
ll h[N],fac[N],inv[N];
ll C(ll x,ll y){return fac[x]*inv[y]%mod*inv[x-y]%mod;}

int main(){
	scanf("%lld%lld",&n,&k);
	rep(i,n)scanf("%lld",&h[i]);
	rep(i,n)tot+=(h[i]!=h[i%n+1]);
	fac[0]=1;
	rep(i,tot)fac[i]=fac[i-1]*i%mod;
	inv[tot]=Pow(fac[tot],mod-2);
	for(ll i=tot;i;i--)inv[i-1]=inv[i]*i%mod;
	ll iv2=Pow(2,mod-2);
	rep0(i,tot){
		ll v=Pow(k-2,i);
		ll u=Pow(2,tot-i-1);
		if((tot-i)%2==0)u=(u-C(tot-i,(tot-i)/2)*iv2%mod+mod)%mod;
		ans=(ans+u*v%mod*C(tot,i))%mod;
	}
	ans=ans*Pow(k,(n-tot))%mod;
	printf("%lld\n",ans);
	return 0;
}