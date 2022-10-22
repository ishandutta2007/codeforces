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
const ll N=3007;
const ll INF=1e9+7;
ll n,num=0;
struct edge{ll v,next,c;}e[N*2];
ll pos[N],sz[N],X[N],Y[N];
int sz1[N][N],sz2[N][N],v1[N][N],v2[N][N];
ll g[N][N];
struct pir{ll x,y;};
vector<pir>p[N];
void add(ll x,ll y,ll c){e[num]=(edge){y,pos[x],c}; pos[x]=num++;}
void dfs1(ll x,ll f){
	sz[x]=1;
	repG(i,x){
		if(e[i].v==f)continue;
		dfs1(e[i].v,x);
		sz[x]+=sz[e[i].v];
	}
}
void dfs2(ll x,ll f,ll b,ll t,ll s,ll d){
	repG(i,x){
		if(e[i].v==f)continue;
		v1[b][e[i].c]=t;
		v2[b][e[i].c]=e[i].v;
		sz1[b][e[i].c]=s;
		sz2[b][e[i].c]=sz[e[i].v];
		g[b][e[i].c]=d;
		dfs2(e[i].v,x,b,t,s,d+1);
	}
}
int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%I64d",&n);
	rep(i,n-1){
		scanf("%I64d%I64d",&X[i],&Y[i]);
		add(X[i],Y[i],i); add(Y[i],X[i],i);
	}
	rep(i,n-1){
		dfs1(X[i],Y[i]);
		dfs1(Y[i],X[i]);
		dfs2(X[i],Y[i],i,Y[i],sz[Y[i]],1);
		dfs2(Y[i],X[i],i,X[i],sz[X[i]],1);
		v1[i][i]=X[i];
		v2[i][i]=Y[i];
		sz1[i][i]=sz[X[i]];
		sz2[i][i]=sz[Y[i]];
		g[i][i]=0;
	}
	rep(i,n-1)rep(j,i)p[g[i][j]].push_back((pir){i,j});
	ll ans=0;
	memset(g,0,sizeof(g));
	rep0(i,n){
		for(ll j=0;j<p[i].size();j++){
			ll u=p[i][j].x,v=p[i][j].y;
			ll g1=X[u]+Y[u]-v1[u][v],g2=X[v]+Y[v]-v2[u][v]; 
			ll f=max(g[g1][v2[u][v]],g[v1[u][v]][g2])+(ll)sz1[u][v]*sz2[u][v];
			ans=max(ans,f);
			g[v1[u][v]][v2[u][v]]=max(g[v1[u][v]][v2[u][v]],f);
			if(u!=v){
				swap(u,v);
				swap(g1,g2);
				f=max(g[g1][v2[u][v]],g[v1[u][v]][g2])+(ll)sz1[u][v]*sz2[u][v];
				ans=max(ans,f);
				g[v1[u][v]][v2[u][v]]=max(g[v1[u][v]][v2[u][v]],f);
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}