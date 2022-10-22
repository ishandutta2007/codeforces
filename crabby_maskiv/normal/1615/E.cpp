#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;
vector<int> g[N];
int dep[N],son[N],top[N];
int fa[N];
void dfs1(int u){
	for(auto v:g[u]){
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs1(v);
		if(dep[v]+1>dep[u]){
			dep[u]=dep[v]+1;
			son[u]=v;
		}
	}
}
void dfs2(int u,int tp){
	top[u]=tp;
	if(son[u]) dfs2(son[u],tp);
	for(auto v:g[u]){
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs1(1);
	dfs2(1,1);
	priority_queue<int> q;
	for(i=1;i<=n;i++){
		if(!son[i]) q.push(dep[top[i]]+1);
		else q.push(0);
	}
	ll ans=-1e18;
	int c=0;
	for(i=1;i<=m;i++){
		c+=q.top();q.pop();
		if(n-c>=n/2) ans=max(ans,ll(n-i-n/2)*(i-n/2));
		else ans=max(ans,ll(c-i)*(i-(n-c)));
	}
	cout<<ans;
	return 0;
}