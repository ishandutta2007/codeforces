#include<bits/stdc++.h>
const int N=1e6+3;
int n,m,cnt,b0[N],b1[N],c1,dep[N];bool vis[N],ans[N];
struct edge{int v,p;};
std::vector<edge>g[N];
void Dfs0(int u,int p){
	int v;
	vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		v=g[u][i].v;
		if(!vis[v]){
			dep[v]=dep[u]+1;
			Dfs0(v,g[u][i].p);
		}
		else if(g[u][i].p!=p&&dep[v]<dep[u]){
			if((dep[u]^dep[v])&1)
				++b0[u],--b0[v];
			else
				++b1[u],--b1[v],++c1;
		}
	}
}
void Dfs1(int u,int p){
	int v;
	vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		v=g[u][i].v;
		if(!vis[v]){
			Dfs1(v,g[u][i].p);
			if(!c1||!b0[v]&&b1[v]==c1)ans[g[u][i].p]=1;
			b0[u]+=b0[v];
			b1[u]+=b1[v];
		}
		else if(g[u][i].p!=p&&dep[v]<dep[u]){
			if(!c1||c1==1&&(~(dep[u]^dep[v])&1))ans[g[u][i].p]=1;
		}
	}
}
int main(){
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&u,&v),g[u].push_back((edge){v,i}),g[v].push_back((edge){u,i});
	for(u=1;u<=n;u++)vis[u]=0;
	for(u=1;u<=n;u++)if(!vis[u])Dfs0(u,0);
	for(u=1;u<=n;u++)vis[u]=0;
	for(u=1;u<=n;u++)if(!vis[u])Dfs1(u,0);
	for(int i=1;i<=m;i++)cnt+=ans[i];
	printf("%d\n",cnt);
	for(int i=1;i<=m;i++)if(ans[i])printf("%d ",i);puts("");
	return 0;
}