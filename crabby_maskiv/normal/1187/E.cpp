#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
vector<int> g[N];
ll size[N],pts[N];
ll dp[N];
void dfs(int cur,int last){
	size[cur]=1;
	for(auto v:g[cur]){
		if(v==last) continue;
		dfs(v,cur);
		pts[cur]+=pts[v];
		size[cur]+=size[v];
	}
	pts[cur]+=size[cur];
}
void dfs2(int cur,int last){
	for(auto v:g[cur]){
		if(v==last) continue;
		dp[v]=dp[cur]-2*size[v]+n;
		dfs2(v,cur);
		
	}
	//pts[cur]+=size[cur];
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	dp[1]=pts[1];
	dfs2(1,0);
	ll ans=0;
	for(i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}