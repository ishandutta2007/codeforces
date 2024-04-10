#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n,m,u,v;
vector<int>g[100004];
int K,dep[100004],p[17][100004],dfn[100004],cnt;
void dfs(int x){
	dfn[x]=++cnt;
	for(int i=1;i<17&&p[i-1][x];i++)p[i][x]=p[i-1][p[i-1][x]];
	for(auto y:g[x])if(y!=p[0][x])p[0][y]=x,dep[y]=dep[x]+1,dfs(y);
}
int lca(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	for(int i=16;i>=0;i--)if((1<<i)&(dep[v]-dep[u]))v=p[i][v];
	if(u==v)return u;
	for(int i=16;i>=0;i--)if(p[i][u]!=p[i][v])v=p[i][v],u=p[i][u];
	return p[0][u];
}
int d[100004];
bool cmp(int a,int b){
	return dfn[a]<dfn[b];
}
vector<int>G[100004];
int f[100004],sz[100004];
bool vis[100004];
int sta[100004],t;
void dfs1(int x){
	for(auto y:G[x])dfs1(y);
	if(vis[x]){
		sz[x]=1,f[x]=0;
		for(auto y:G[x])f[x]+=f[y]+sz[y];
	}else{
		sz[x]=0,f[x]=0;
		for(auto y:G[x])f[x]+=f[y],sz[x]+=sz[y];
		if(sz[x]>1)sz[x]=0,f[x]++;
	}
	G[x].clear();
}
void solve(){
	for(int i=1;i<=K;i++)scanf("%d",&d[i]),vis[d[i]]=1;
	for(int i=1;i<=K;i++)if(vis[p[0][d[i]]]){puts("-1");for(int i=1;i<=K;i++)vis[d[i]]=0;return;}
	sort(d+1,d+K+1,cmp);
	sta[0]=1,t=1;
	for(int i=1;i<=K;i++){
		if(d[i]==1)continue;
		int L=lca(d[i],sta[t-1]);
		while(t>1&&dep[sta[t-2]]>dep[L])G[sta[t-2]].push_back(sta[t-1]),t--;
		if(sta[t-1]!=L){
			if(sta[t-2]==L)G[sta[t-2]].push_back(sta[t-1]),t--;
			else G[L].push_back(sta[t-1]),sta[t-1]=L;
		}
		sta[t++]=d[i];
	}
	while(t>1)G[sta[t-2]].push_back(sta[t-1]),t--;
	dfs1(1);
	printf("%d\n",f[1]);
	for(int i=1;i<=K;i++)vis[d[i]]=0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs(1);
	int A,B;
	scanf("%d",&m);
	while(m--)scanf("%d",&K),solve();
}