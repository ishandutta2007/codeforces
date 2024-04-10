#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;
	
vector<int> adj[maxn];
int n;
int sz[maxn][2];
long long sz2[maxn][2];
int dep[maxn];
long long dp[maxn],dp2[maxn];

void dfs1(int u){
	sz[u][0]=1;
	long long ans=0;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(!dep[v]){
			dep[v]=dep[u]+1;
			dfs1(v);
			sz[u][0]+=sz[v][1];
			sz[u][1]+=sz[v][0];
			dp[u]+=dp[v];
		}
	}
	dp[u]+=(sz[u][0]+sz[u][1]-1);
}

long long dfs2(int u){
	long long ans=dp2[u]+sz2[u][1];
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(dep[v]==dep[u]+1){
			dp2[v]=dp2[u]-(sz[v][0]+sz[v][1])+(n-sz[v][0]-sz[v][1]);
			sz2[v][0]=sz[v][0]+sz2[u][1]-sz[v][0];
			sz2[v][1]=sz[v][1]+sz2[u][0]-sz[v][1];
			ans+=dfs2(v);
		}
	}
	return ans;
} 
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dep[1]=1;
	dfs1(1);
	dp2[1]=dp[1];
	sz2[1][0]=sz[1][0];
	sz2[1][1]=sz[1][1];
	cout<<dfs2(1)/4;
	return 0;
}