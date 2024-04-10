#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;

vector<int> adj[maxn];
int n,x,y;
int dep[maxn],sz[maxn];

void dfs(int u){
	sz[u]=1;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(!dep[v]){
			dep[v]=dep[u]+1;
			dfs(v);
			sz[u]+=sz[v];
		}
	}
}
int main(){
	cin>>n>>x>>y;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	long long ans=n;
	ans*=n-1;
	dep[x]=1;
	dfs(x);
	long long vy=sz[y];
	memset(dep,0,sizeof(dep)); 
	dep[y]=1;
	dfs(y);
	long long vx=sz[x];
	cout<<ans-vx*vy;
	return 0;
}