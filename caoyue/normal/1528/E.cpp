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
#include<bitset>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=2e6+7;
const int INF=1e9+7;
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
ll f[N],sf[N],g[N],h[N];
ll n,i2,i6;
ll C2(ll x){return x*(x+1+mod)%mod*i2%mod;}
ll C3(ll x){return x*(x+1+mod)%mod*(x+2+mod)%mod*i6%mod;}

int main(){
	i2=Pow(2,mod-2);
	i6=Pow(6,mod-2);
	scanf("%lld",&n);
	if(n==1){
		puts("5");
		return 0;
	}
	f[0]=sf[0]=1;
	rep(i,n){
		f[i]=(f[i-1]+C2(sf[i-1]))%mod;
		if(i>1)f[i]=(f[i]-C2(sf[i-2])+mod)%mod;
		sf[i]=(sf[i-1]+f[i])%mod;
	}
	ll ans=(C3(sf[n-1]))%mod;
	if(n>1)ans=(ans-C3(sf[n-2])+mod)%mod;
	ans=(ans*2ll+1)%mod;
	rep(i,n){
		g[i]=C2(sf[i-1]);
		if(i>1)g[i]=(g[i]-C2(sf[i-2])+mod)%mod;
		ans=(ans+g[i]*2ll)%mod;
		h[i+1]=(h[i+1]+g[i])%mod;
	}
	rep(i,n)h[i]=(h[i]+h[i-1])%mod;
	rep(i,n-1)ans=(ans+h[i]*g[n-i])%mod;
	printf("%lld\n",ans);
	return 0;
}