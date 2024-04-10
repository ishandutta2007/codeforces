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
const ll INF=1e18+7;
ll n,k,num=0,cnt=0;
ll pos[N],ln[N],q[N];
struct edge{ll v,next;}e[N*2];
void add(ll x,ll y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs(ll x,ll f){
	ln[x]=1;
	ll id=-1;
	repG(i,x){
		if(e[i].v==f)continue;
		dfs(e[i].v,x);
		if(ln[e[i].v]+1>ln[x]){
			ln[x]=ln[e[i].v]+1;
			id=e[i].v;
		}
	}
	repG(i,x)if(e[i].v!=f&&e[i].v!=id)q[++cnt]=ln[e[i].v];
}
int main(){
	scanf("%lld%lld",&n,&k);
	memset(pos,-1,sizeof(pos));
	rep(i,n-1){
		ll x,y; scanf("%lld%lld",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	q[++cnt]=ln[1];
	if(k>=cnt){
		ll ans=0;
		rep0(i,k+1)ans=max(ans,i*(n-i));
		printf("%lld\n",ans);
		return 0;
	}
	sort(q+1,q+cnt+1);
	ll cc=n;
	rep0(i,k)cc-=q[cnt-i];
	ll ans=INF;
	rep0(i,cc+1)ans=min(ans,(n-k-i)*(k-i));
	printf("%lld\n",ans);
	return 0;
}