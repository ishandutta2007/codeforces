#include<bits/stdc++.h>
using namespace std;
int n,q,dfn[200005],cnt;
vector<int>g[200005];
int p[200005][20],dep[200005];
void dfs(int x){
	dfn[x]=++cnt;
	for(int i=1;i<20;i++)if(p[x][i-1])
		p[x][i]=p[p[x][i-1]][i-1];
	for(auto y:g[x])if(y!=p[x][0])
		p[y][0]=x,dep[y]=dep[x]+1,dfs(y);
}
int lca(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	for(int i=19;~i;i--)
		if((1<<i)&(dep[v]-dep[u]))v=p[v][i];
	if(u==v)return u;
	for(int i=19;~i;i--)if(p[u][i]!=p[v][i])
		u=p[u][i],v=p[v][i];
	return p[u][0];
}
bool cmp(int a,int b){return dfn[a]<dfn[b];}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs(1);
	scanf("%d",&q);
	while(q--){
		int m,x;scanf("%d",&m);vector<int>v;
		while(m--)scanf("%d",&x),v.push_back(x);
		sort(v.begin(),v.end(),cmp);
		int it=1;
		while(it<v.size()){
			if(lca(v[it-1],v[it])!=v[it-1])break;
			it++;
		}
		if(it==v.size()){puts("YES");continue;}
		int L=lca(v[it],v[it-1]);
		if(L!=v[0]&&lca(v[0],L)==v[0]){puts("No");continue;}
		it++;
		while(it<v.size()){
			if(lca(v[it-1],v[it])!=v[it-1])break;
			it++;
		}
		puts(it<v.size()?"NO":"YES");
	}
}