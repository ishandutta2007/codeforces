#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;
const int maxl=25;

int n;
vector<int> adj[maxn];
int dep[maxn];
int fa[maxn];
long long cf[maxn];
vector<int> cs[maxn];
vector<int> csn[maxn];
vector<long long> df[maxn];
int dfn[maxn],c1;
int dfm[maxn];
long long ans[maxn];

void dfs(int u){
	dfn[u]=dfm[u]=++c1;
	cs[dep[u]].push_back(u);
	csn[dep[u]].push_back(dfn[u]);
	df[dep[u]].push_back(0); 
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(!dep[v]){
			fa[v]=u;
			dep[v]=dep[u]+1;
			dfs(v);
			dfm[u]=max(dfm[u],dfm[v]);
		}	
	}
}

void dfs2(int u,long long x){
	ans[u]=x;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(dep[v]==dep[u]+1){
			dfs2(v,x+cf[v]);
		}
	}
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
	dfs(1);
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		int v,d;
		long long x;
		cin>>v>>d>>x;
		cf[v]+=x;
		int cur=dep[v]+d+1;
		if(cur<=n){
			int p1=lower_bound(csn[cur].begin(),csn[cur].end(),dfn[v])-csn[cur].begin();
			int p2=lower_bound(csn[cur].begin(),csn[cur].end(),dfm[v]+1)-csn[cur].begin();
			if(p1<csn[cur].size())df[cur][p1]-=x;
			if(p2<csn[cur].size())df[cur][p2]+=x;
		} 
	} 
	for(int i=1;i<=n;i++){
		for(int j=0;j<df[i].size();j++){
			if(j)df[i][j]+=df[i][j-1];
			cf[cs[i][j]]+=df[i][j];
		}
	}
	dfs2(1,cf[1]); 
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}