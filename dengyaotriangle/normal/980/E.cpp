#include <bits/stdc++.h>

using namespace std;

const int maxn=1000006;
const int maxl=25;
int n,k;
vector<int> adj[maxn];
int fa[maxn][maxl];
bool gt[maxn];
int dep[maxn];
void dfs(int u){
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(!dep[v]){
			dep[v]=dep[u]+1;
			fa[v][0]=u;
			dfs(v);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	k=n-k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dep[n]=1;
	dfs(n);
	for(int i=1;i<maxl;i++){
		for(int j=1;j<=n;j++){
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
	gt[n]=1;
	k--;
	for(int i=n-1;i>=1;i--){
		if(!k) break;
		if(gt[i]) continue;
		int cnt=1,u=i;
		for(int j=maxl-1;j>=0;j--){
			if(fa[u][j]&&!gt[fa[u][j]]){
				u=fa[u][j];
				cnt+=(1<<j);
			}
		}
		if(cnt<=k){
			k-=cnt;
			int ub=u;
			u=i;
			while(1){ 
				gt[u]=1;
				if(u==ub) break; 
				u=fa[u][0];
			}
		}
	}
	for(int i=1;i<=n;i++) if(!gt[i]) cout<<i<<' ';
	return 0;
}