#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q;
int u[100004],v[100004],d[100004];
bool used[100004],vis[100004];
vector<int>g[100004],tr[100004];
ll dis[100004];
int par[18][100004],dep[100004],lg[100004];
int ID[100004],N;
ll D1[44],D2[44];
ll f[44][44];
vector<int>node;
void dfs(int x){
	vis[x]=1;
	for(auto y:g[x]){
		if(used[y])continue;
		int to=u[y]^v[y]^x;
		if(vis[to])continue;
		used[y]=1,dfs(to),tr[x].push_back(y);
	}
}
void dfs1(int x){
	for(int i=1;i<=lg[dep[x]];i++)
		par[i][x]=par[i-1][par[i-1][x]];
	for(auto y:tr[x]){
		int to=u[y]^v[y]^x;
		par[0][to]=x;
		dis[to]=dis[x]+d[y];
		dep[to]=dep[x]+1;
		dfs1(to);
	}
}
int lca(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	while(dep[u]<dep[v])v=par[lg[dep[v]-dep[u]]][v];
	if(u==v)return u;
	for(int i=lg[dep[u]];i>=0;--i)
		if(par[i][u]!=par[i][v])u=par[i][u],v=par[i][v];
	return par[0][u];
}
ll calc(int u,int v){
	int L=lca(u,v);
	return dis[u]+dis[v]-dis[L]-dis[L];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&d[i]);
		g[u[i]].push_back(i),g[v[i]].push_back(i);
	}
	dfs(1);
	dfs1(1);
	for(int i=0;i<44;i++)for(int j=0;j<44;j++)f[i][j]=1e18;
	for(int i=1;i<=m;i++)if(!used[i]){
		if(!ID[u[i]])ID[u[i]]=node.size(),node.push_back(u[i]);
		if(!ID[v[i]])ID[v[i]]=node.size(),node.push_back(v[i]);
		int U=ID[u[i]],V=ID[v[i]];
		f[U][V]=min(f[U][V],(ll)d[i]);
		f[V][U]=min(f[V][U],(ll)d[i]);
	}
	N=node.size();
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)f[i][j]=min(f[i][j],calc(node[i],node[j]));
	for(int k=0;k<N;k++)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)	
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	scanf("%d",&q);
	while(q--){
		int u,v;scanf("%d%d",&u,&v);
		ll ans=calc(u,v);
		for(int i=0;i<N;i++)D1[i]=calc(u,node[i]),D2[i]=calc(v,node[i]);
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)
			ans=min(ans,D1[i]+f[i][j]+D2[j]);
		printf("%lld\n",ans);
	}
}