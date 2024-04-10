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
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=2e5+7;
const ll INF=1e9+7;
ll n,T,num;
ll l[N],r[N],f[N][2],pos[N];
struct edge{ll v,next;}e[N*2];
void add(ll x,ll y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs(ll x,ll fa){
	repG(i,x){
		if(e[i].v==fa)continue;
		dfs(e[i].v,x);
	}
	f[x][0]=f[x][1]=0;
	repG(i,x){
		if(e[i].v==fa)continue;
		f[x][0]+=max(f[e[i].v][0]+abs(l[x]-l[e[i].v]),f[e[i].v][1]+abs(l[x]-r[e[i].v]));
		f[x][1]+=max(f[e[i].v][0]+abs(r[x]-l[e[i].v]),f[e[i].v][1]+abs(r[x]-r[e[i].v]));
	}
}
int main(){
	scanf("%lld",&T);
	rep(taskid,T){
		scanf("%lld",&n);
		num=0;
		rep(i,n)pos[i]=-1;
		rep(i,n)scanf("%lld%lld",&l[i],&r[i]);
		rep(i,n-1){
			ll u,v; scanf("%lld%lld",&u,&v);
			add(u,v); add(v,u);
		}
		dfs(1,0);
		printf("%lld\n",max(f[1][0],f[1][1]));
	}
	return 0;
}