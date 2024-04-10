#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
 
const int maxn=1000005;
 
int n,m;
vector<int> adj[maxn];
int dfn[maxn],low[maxn],c1,c2,scc[maxn];
stack<int> stk;
bool ins[maxn],vis[maxn];
 
void tarjan(int u){
	low[u]=dfn[u]=++c1;
	ins[u]=vis[u]=1;
	stk.push(u);
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(!vis[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		} else if(ins[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		c2++;
		while(1){
			int v=stk.top();stk.pop();
			ins[v]=0;
			scc[v]=c2;
			if(u==v)break;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)adj[i].clear();
		for(int i=1;i<=n;i++)vis[i]=0;
		c1=c2=0;
		for(int i=1;i<=m;i++){
			int u,v;
			cin>>u>>v;
			if(u!=v) adj[u].push_back(v);
		}
		for(int i=1;i<=n;i++){
			if(!vis[i])tarjan(i);
		}
		if(c2==1){
			cout<<"No\n"; 
		}else{
			cout<<"Yes\n";
			int c=0;
			for(int i=1;i<=n;i++)if(scc[i]==1)c++;
			cout<<c<<' '<<n-c<<'\n';
			for(int i=1;i<=n;i++)if(scc[i]==1)cout<<i<<' ';
			cout<<'\n';
			for(int i=1;i<=n;i++)if(scc[i]!=1)cout<<i<<' ';
			cout<<'\n';
		}
	}	
	return 0;
}