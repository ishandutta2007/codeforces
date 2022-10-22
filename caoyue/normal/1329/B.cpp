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
const ll N=37;
const ll INF=1e9+7;
ll T;
ll f[N];
ll solve(ll x,ll mod){
	if(x<=1)return (x+1ll)%mod;
	ll nw=0,cnt=1;
	while(cnt*2ll<=x)cnt<<=1,nw++;
	return f[nw]*(x-cnt+2ll);
}
int main(){
	scanf("%lld",&T);
	while(T--){
		ll d,m; scanf("%lld%lld",&d,&m);
		f[1]=2;
		REP(i,2,30)f[i]=f[i-1ll]*(1ll+(1ll<<(i-1ll)))%m;
		printf("%lld\n",(solve(d,m)-1+m)%m);
	}
	return 0;
}