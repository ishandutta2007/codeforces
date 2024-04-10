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
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=6e5+7;
const int INF=1e9+7;
int n,m,q,cnt,ts=0,num=0;
int p[N],ip[N],U[N],V[N],op[N],X[N],fa[N][22],Ans[N],dw[N],pb[N],f[N],id[N],pos[N],dv[N],dep[N];
vector<int>qs[N];
int ff(int x){return (f[x]==x)?x:f[x]=ff(f[x]);}
struct edge{int v,next;}e[N*2];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
int bg[N],ed[N];
void dfs(int x,int ft,int d){
	dep[x]=d;
	bg[x]=ed[x]=++ts;
	fa[x][0]=ft;
	for(int i=0;fa[fa[x][i]][i];i++)fa[x][i+1]=fa[fa[x][i]][i];
	repG(i,x){
		if(e[i].v==ft)continue;
		dfs(e[i].v,x,d+1);
		ed[x]=ed[e[i].v];
	}
}
bool vis[N];
void work(int x){
	vis[x]=1;
	repG(i,x){
		if(vis[e[i].v])continue;
		if(qs[e[i].v].size())continue;
		work(e[i].v);
	}
}
int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%d%d%d",&n,&m,&q);
	cnt=m;
	rep(i,n){
		scanf("%d",&p[i]);
		ip[p[i]]=i;
	}
	rep(i,m)scanf("%d%d",&U[i],&V[i]);
	rep(i,q)scanf("%d%d",&op[i],&X[i]);
	rep(i,q){
		if(op[i]==2)dw[X[i]]=cnt--;
		dv[i]=cnt;
	}
	rep(i,m)if(!dw[i])dw[i]=cnt--;
	rep(i,m)pb[dw[i]]=i;
	rep(i,n)f[i]=id[i]=i;
	rep(i,m){
		int u=ff(U[pb[i]]),v=ff(V[pb[i]]);
		if(f[u]!=f[v]){
			add(i+n,id[u]);
			add(i+n,id[v]);
			f[v]=u;
			id[u]=i+n;
		}
	}
	rep(i,n)if(ff(i)==i)add(n+m+1,id[i]);
	dfs(n+m+1,0,1);
	for(int i=q;i;i--){
		if(op[i]==1){
			int h=X[i];
			for(int j=19;~j;j--)if(fa[h][j]&&fa[h][j]<=dv[i]+n)h=fa[h][j];
			qs[h].push_back(i);
		}
	}
	work(n+m+1);
	for(int i=n;i;i--){
		if(vis[ip[i]])continue;
		int o=ip[i];
		for(int j=19;~j;j--)if(fa[o][j]&&!vis[fa[o][j]])o=fa[o][j];
		int t=qs[o][qs[o].size()-1];
		Ans[t]=i;
		qs[o].pop_back();
		if(!qs[o].size())work(o);
	}
	rep(i,q)if(op[i]&1)printf("%d\n",Ans[i]);
	return 0;
}