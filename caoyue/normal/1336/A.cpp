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
ll n,num=0,k,ans=0;
ll pos[N],sz[N],dep[N],p[N];
struct edge{ll v,next;}e[N*2];
void add(ll x,ll y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs(ll x,ll f,ll d){
	sz[x]=1;
	dep[x]=d;
	repG(i,x){
		if(e[i].v==f)continue;
		dfs(e[i].v,x,d+1);
		sz[x]+=sz[e[i].v];
	}
}
bool cmp(ll a,ll b){return a>b;}
int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%lld%lld",&n,&k);
	rep(i,n-1){
		ll u,v; scanf("%lld%lld",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0,0);
	rep(i,n)p[i]=sz[i]-dep[i]-1;
	sort(p+1,p+n+1,cmp);
	rep(i,n-k)ans+=p[i];
	printf("%lld\n",ans);
	return 0;
}