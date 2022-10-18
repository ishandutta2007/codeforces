#include<iostream>
#include<vector>
using namespace std;

const int maxn=100006;

int n;
int dep[maxn];
std::vector<int> adj[maxn];

void dfs(int u){
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(!dep[v]){
			dep[v]=dep[u]+1;
			dfs(v);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dep[1]=1;
	dfs(1);
	double ans=0;
	for(int i=1;i<=n;i++) ans+=1.0/(double)(dep[i]);
	printf("%.20lf",ans);
	return 0;
}