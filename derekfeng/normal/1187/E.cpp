#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0;
int n;
ll dist[200004];
int cnt[200004];
vector <int>g[200004];
void dfs(int x,int par){
	cnt[x]=1;
	for (int i=0;i<g[x].size();i++) if (g[x][i]!=par){
		dfs(g[x][i],x);
		cnt[x]+=cnt[g[x][i]];
	}
}
void dfs1(int x,int par){
	for (int i=0;i<g[x].size();i++) if (g[x][i]!=par){
		dfs1(g[x][i],x);
		dist[x]+=dist[g[x][i]]+cnt[g[x][i]];
	}
}
void dfs2(int x,int par,ll now){
	ans=max(ans,now+n+dist[x]);
	ll res=now+dist[x];
	for (int i=0;i<g[x].size();i++) if (g[x][i]!=par) dfs2(g[x][i],x,res-dist[g[x][i]]-cnt[g[x][i]]*2+n);
}
int main(){
	cin>>n;
	for (int i=0;i<n-1;i++){
		int x,y;scanf ("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1;i<=n;i++) cnt[i]=g[i].size();
	dfs(1,-1);
	dfs1(1,-1);
	dfs2(1,-1,0);
	cout<<ans;
}