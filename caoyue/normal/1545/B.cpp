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
const ll N=5e5+7;
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
ll fac[N],inv[N],a[N];
ll C(ll x,ll y){
	if(x<y||y<0)return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod; 
}
char s[N];

int main(){
	fac[0]=1;
	rep(i,N-3)fac[i]=fac[i-1]*i%mod;
	inv[N-3]=Pow(fac[N-3],mod-2);
	for(ll i=N-3;i;i--)inv[i-1]=inv[i]*i%mod;
	ll T; scanf("%lld",&T);
	while(T--){
		ll n,c0=0,c1=0; scanf("%lld",&n);
		scanf("%s",s+1);
		rep(i,n){
			if(s[i]=='0')a[++c0]=c1;
			else c1++;
		}
		if(!c0){
			puts("1");
			continue;
		}
		if(a[1]&1)c1--;
		rep(i,c0-1)if((a[i]^a[i+1])&1)c1--;
		c1=c1/2;
		printf("%lld\n",C(c0+c1,c0));
	}
	return 0;
}