#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int n, m;
const int N=2e5+5;
vector<vector<int>>adj;
int d[N];
int dp[N][2];
bool che[N][2];

int f(int v, int ty){
	if(v==1){
		return 0;
	}
	if(che[v][ty]){
		return dp[v][ty];
	}
	che[v][ty]=1;
	dp[v][ty]=d[v];
	for(auto u:adj[v]){
		if(d[u]>d[v]){
			dp[v][ty]=min(dp[v][ty], f(u, ty));
		}
		if(d[u]<=d[v] && ty==0){
			dp[v][ty]=min(dp[v][ty], f(u, 1));
		}
	}
	return dp[v][ty];
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		adj.clear();
		adj.resize(n+1);
		for(int i=1; i<=n; i++){
			d[i]=0;
			for(int j=0; j<2; j++){
				dp[i][j]=0;
				che[i][j]=0;
			}
		}
		for(int i=0; i<m; i++){
			int u, v;
			cin>>u>>v;
			adj[u].pb(v);
		}
		
		for(int i=0; i<=n; i++){
			d[i]=1e6;
		}
		d[1]=0;
		queue<int>q;
		q.push(1);
		while(!q.empty()){
			auto u=q.front();
			q.pop();
			for(auto uu:adj[u]){
				if(d[uu]>1+d[u]){
					d[uu]=1+d[u];
					q.push(uu);
				}
			}
		}
		for(int i=1; i<=n; i++){
			cout<<f(i, 0)<<" ";
		}
		cout<<endl;
	}
	return 0;
}