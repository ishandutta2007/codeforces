#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;
vector<int> g[N];
int c[N],mx[N],dp[N];
bool vis[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[v].push_back(u);
		c[u]++;
	}
	q.push({0,n});
	while(!q.empty()){
		int u=q.top().sc,d=q.top().fr;q.pop();
		if(vis[u]) continue;
		dp[u]=d;
		vis[u]=1;
		for(auto v:g[u]){
			c[v]--;
			mx[v]=max(mx[v],d+1);
			q.push({c[v]+mx[v],v});
		}
	}
	cout<<dp[1];
	return 0;
}