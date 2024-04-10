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
const ll N=2e5+7;
const ll INF=1e9+7;
ll T,n;
ll w[N],dg[N],h[N*2];
struct edge{ll v,next;}e[N*2];
bool cmp(ll x,ll y){return x>y;}
int main(){
	scanf("%I64d",&T);
	while(T--){
		scanf("%I64d",&n);
		rep(i,n)dg[i]=0;
		ll ans=0;
		rep(i,n)scanf("%I64d",&w[i]);
		rep(i,n)ans+=w[i];
		rep(i,n-1){
			ll u,v; scanf("%I64d%I64d",&u,&v);
			dg[u]++; dg[v]++;
		}
		ll cnt=0;
		rep(i,n)rep(j,dg[i]-1)h[++cnt]=w[i];
		sort(h+1,h+cnt+1,cmp);
		printf("%I64d ",ans);
		rep(i,n-2){
			ans+=h[i];
			printf("%I64d ",ans);
		}
		puts("");
	}
	return 0;
}