#include<bits/stdc++.h>
using namespace std;
int n,deg[100004];
vector<int>tr[100004];
int f[100004];
void dfs(int u,int fa,int d){
	f[u]=d;
	for(auto v:tr[u])if(v!=fa)
		dfs(v,u,d^1);
}
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)tr[i].clear(),deg[i]=0;
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		tr[u].push_back(v),tr[v].push_back(u);
		deg[u]++,deg[v]++;
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++)printf("%d ",f[i]?deg[i]:-deg[i]);puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)sol();
}