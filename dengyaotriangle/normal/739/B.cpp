#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;
const int maxl=25;
int n;
long long a[maxn];
vector<pair<int,long long> > adj[maxn];
long long cf[maxn],fa[maxn][maxl],dis[maxn][maxl],dep[maxn];
long long ans[maxn];
long long p2[maxl];

void dfs(int u){
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i].first;
		int w=adj[u][i].second;
		if(!dep[v]){
			fa[v][0]=u;
			dis[v][0]=w;
			dep[v]=dep[u]+1;
			dfs(v);
		}
	}
}

void dfs2(int u){
	ans[u]=cf[u];
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i].first;
		int w=adj[u][i].second;
		if(dep[v]==dep[u]+1){
			dfs2(v);
			ans[u]+=ans[v];
		}
	}
} 
int main(){
	ios::sync_with_stdio(0);
	p2[0]=1;
	for(int i=1;i<maxl;i++) p2[i]=p2[i-1]*2;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++){
		int v,w;
		cin>>v>>w;
		adj[i].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(i,w));
	}
	dep[1]=1;
	dfs(1);
	for(int i=1;i<maxl;i++){
		for(int j=1;j<=n;j++){
			fa[j][i]=fa[j][i-1];if(fa[j][i])fa[j][i]=fa[fa[j][i]][i-1];
			dis[j][i]=dis[j][i-1]+dis[fa[j][i-1]][i-1];
		}
	}
	for(int i=1;i<=n;i++){
		int u=i;
		for(int j=maxl-1;j>=0;j--){
			if(fa[u][j]){
				if(dis[u][j]<=a[i]){
					a[i]-=dis[u][j];
					u=fa[u][j];
				}
			}
		}
		cf[fa[u][0]]--;
		cf[fa[i][0]]++;
	}
	dfs2(1);
	for(int i=1;i<=n;i++)cout<<ans[i]<<' '; 
	return 0;
}