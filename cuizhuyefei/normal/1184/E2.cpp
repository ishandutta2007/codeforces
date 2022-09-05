#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct edge{
	int a,b,e;
	inline void in(){cin>>a>>b>>e;}
}E[N];
int n,m,i,j,g[N],id[N],f1[20][N],f2[20][N],dep[N];
vector<int>e[N];
inline bool cmp(int x,int y){
	return E[x].e<E[y].e;
}
int gfa(int x){
	return g[x]==x?x:g[x]=gfa(g[x]);
}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;f1[0][u]=fa;
	for(int i:e[u]){
		int v=E[i].a^E[i].b^u;
		if(v==fa)continue;
		f2[0][v]=E[i].e;dfs(v,u);
	}
}
inline int lca(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	int dt=dep[y]-dep[x],i;
	for(i=0;1<<i<=dt;++i)if(dt>>i&1)y=f1[i][y];
	if(x==y)return x;
	for(i=19;i>=0;--i)if(f1[i][x]!=f1[i][y])x=f1[i][x],y=f1[i][y];
	return f1[0][x];
}
inline int A1(int x,int y){
	int dt=dep[y]-dep[x],i,ans=0;
	for(i=0;1<<i<=dt;++i)if(dt>>i&1)ans=max(ans,f2[i][y]),y=f1[i][y];
	return ans;
}
inline int A2(int x,int y){
	int z=lca(x,y);
	return max(A1(z,x),A1(z,y));
}
bool ont[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;for(i=1;i<=m;++i)E[id[i]=i].in();
	for(i=1;i<=n;++i)g[i]=i;
	sort(id+1,id+m+1,cmp);
	for(i=1;i<=m;++i){
		int x=E[id[i]].a,y=E[id[i]].b;
		if(gfa(x)==gfa(y))continue;
		ont[id[i]]=1;
		g[gfa(x)]=gfa(y);e[x].push_back(id[i]);e[y].push_back(id[i]);
	}
	dfs(1,0);
	for(i=1;i<20;++i)for(j=1;j<=n;++j)f1[i][j]=f1[i-1][f1[i-1][j]],
		f2[i][j]=max(f2[i-1][j],f2[i-1][f1[i-1][j]]);
	for(i=1;i<=m;++i)if(!ont[i])cout<<A2(E[i].a,E[i].b)<<'\n';
	return 0;
}