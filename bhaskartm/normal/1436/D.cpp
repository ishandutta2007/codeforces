#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

bool pre[200005];
int vals[200005];
int sz[200005];
int sum[200005];
bool che;

vector<vector<int>>adj;
int maxi;
int mini;

void dfs(int v){
	if(adj[v].size()==0){
		sz[v]=1;
	}
	sum[v]=vals[v];
	for(auto u:adj[v]){
		dfs(u);
		sum[v]+=sum[u];
		sz[v]+=sz[u];
	}
	int va=(sum[v]/sz[v]);
	if(sum[v]%sz[v]!=0){
		va++;
	}
	mini=max(mini, va);
	
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	mini=0;
	adj.resize(n+1);
	for(int i=2; i<=n; i++){
		int x;
		cin>>x;
		adj[x].pb(i);
		pre[x]=1;
	}
	for(int i=1; i<=n; i++){
		cin>>vals[i];
		if(pre[i]==0){
			maxi=max(maxi, vals[i]);
		}
	}
	dfs(1);
	cout<<mini;
	return 0;
}