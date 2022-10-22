#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=1007;
const ll INF=1e9+7;
const ll mod=998244353;
ll a[N],f[N],fac[N],inv[N];
ll n;
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
ll C(ll x,ll y){return fac[x]*inv[y]%mod*inv[x-y]%mod;}
int main(){
	scanf("%I64d",&n);
	fac[0]=1;
	rep(i,n)fac[i]=fac[i-1]*i%mod;
	inv[n]=Pow(fac[n],mod-2);
	for(ll i=n;i;i--)inv[i-1]=inv[i]*i%mod;
	rep(i,n)scanf("%I64d",&a[i]);
	rep(i,n+1){
		if(i<n)f[i]=1;
		rep0(j,i){
			if(a[j]<1)continue;
			if(a[j]<=i-j-1)f[i]=(f[i]+C(i-j-1,a[j])*f[j])%mod;
		}
	}
	printf("%I64d\n",f[n+1]);
	return 0;
}