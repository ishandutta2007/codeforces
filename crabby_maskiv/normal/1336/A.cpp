#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m,T;
int dep[N],sz[N];
vector<int> g[N];
void dfs(int u,int last){
	sz[u]=1;
	for(auto v:g[u]){
		if(v==last) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
int w[N];
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	for(i=1;i<=n;i++)
		w[i]=dep[i]-(sz[i]-1);
	sort(w+1,w+n+1);
	ll ans=0;
	for(i=1;i<=m;i++)
		ans+=w[n-i+1];
	cout<<ans;
	return 0;
}