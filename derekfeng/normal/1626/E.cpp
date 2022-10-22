#include<bits/stdc++.h>
using namespace std;
int n,a[300004],sz[300004],ans[300004],tot;
vector<int>g[300004],t[300004];
bool check(int x){
	for(auto y:g[x])
		if(a[y])return 1;
	return 0;
}
void dfs(int u,int fa){
	sz[u]=a[u];
	for(auto v:g[u])if(v!=fa){
		dfs(v,u),sz[u]+=sz[v];
		if(sz[v]>=2)t[v].push_back(u);
		if(tot-sz[v]>=2)t[u].push_back(v);
	}
}
void dfs1(int u){
	if(ans[u])return;
	ans[u]=1;
	for(auto v:t[u])dfs1(v);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),tot+=a[i];
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		if(a[i]||check(i))dfs1(i);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}