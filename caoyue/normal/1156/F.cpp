#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=5007;
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
ll n,nw=0,ans=0;
ll a[N],fac[N],inv[N],g[N];
ll C(ll x,ll y){
	if(y<0||y>x)return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}

int main(){
	scanf("%I64d",&n);
	rep(i,n){
		ll x; scanf("%I64d",&x);
		a[x]++;
	}
	fac[0]=1;
	rep(i,n)fac[i]=fac[i-1]*i%mod;
	inv[n]=Pow(fac[n],mod-2);
	for(ll i=n;i;i--)inv[i-1]=inv[i]*i%mod;
	g[0]=1;
	rep(i,n){
		if(a[i]>1)rep0(j,nw+1)ans=(ans+g[j]*inv[n]%mod*fac[n-j-2]%mod*a[i]%mod*(a[i]-1))%mod;
		if(a[i]){
			nw++;
			for(int j=nw;j;j--)g[j]=(g[j-1]*a[i]%mod+g[j])%mod;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}