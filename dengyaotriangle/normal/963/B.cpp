#include<bits/stdc++.h>

using namespace std;

const int  maxn=200005;

int n;
vector<int> adj[maxn];
bool vis[maxn];
int sz[maxn];
void dfs(int u){
	sz[u]=1;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(sz[v]) continue;
		dfs(v);
		sz[u]+=sz[v];
	}
}
void dfs2(int u){
	vis[u]=1;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(vis[v])continue;
		if(sz[v]%2==0){
			dfs2(v);
		}
	}
	cout<<endl<<u;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(vis[v])continue;
		if(sz[v]%2==1){
			dfs2(v);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		if(p){
			adj[i].push_back(p);
			adj[p].push_back(i);
		}
	}
	if(n%2==0){
		cout<<"NO";
		return 0;
	}
	cout<<"YES";
	dfs(1);
	dfs2(1);
	return 0;
}