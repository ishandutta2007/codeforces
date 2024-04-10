#include<iostream>
#include<vector>
#include<cstring>
#define int long long
using namespace std;

const int maxn=200005;

int n;
int a[maxn];
vector<int> adj[maxn];
int dp[maxn];
int dep[maxn],sts[maxn];
bool vis[maxn];

void dfs1(int u){
	sts[u]=a[u];
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(dep[v]!=-1) continue; 
		dep[v]=dep[u]+1; 
		dfs1(v);
		sts[u]+=sts[v];
	}
} 

void dfs2(int u){
	vis[u]=1;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(vis[v]) continue;
		dp[v]=dp[u]-sts[v]+sts[1]-sts[v];
		dfs2(v);
	}
} 

signed main(){
	memset(dep,-1,sizeof(dep));
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);adj[v].push_back(u); 
	} 
	dep[1]=0;
	dfs1(1);
	for(int i=1;i<=n;i++) dp[1]+= dep[i]*a[i];
	dfs2(1);
	int ans=0;
	//for(int i=1;i<=n;i++) cout<<dp[i]<<dep[i]<<endl; 
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<ans; 
	return 0;
}