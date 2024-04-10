#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double
const int N=1000000007;
vector<vector<int>>adj;
vector<int>szs;
int sz[100005];
int n;
void dfs(int v, int p){
	sz[v]=1;
	for(auto u:adj[v]){
		if(u!=p){
			dfs(u, v);
			sz[v]+=sz[u];
		}
	}
	if(v!=1){
		szs.pb((sz[v]*(n-sz[v])));
	}
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		adj.clear();
		adj.resize(n+1);
		szs.clear();
		for(int i=0; i<n-1; i++){
			int u, v;
			cin>>u>>v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		int m;
		cin>>m;
		vector<int>v;
		for(int i=0; i<m; i++){
			int x;
			cin>>x;
			v.pb(x);
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		dfs(1, -1);
		sort(szs.begin(), szs.end());
		reverse(szs.begin(), szs.end());
		int ans[n-1];
		if(m<=n-1){
			for(int i=0; i<n-1; i++){
				if(i<m){
					ans[i]=(szs[i]*v[i])%N;
				}
				else{
					ans[i]=szs[i];
				}
			}
			int fin=0;
			for(int i=0; i<n-1; i++){
				fin+=ans[i];
				fin=fin%N;
			}
			cout<<fin<<endl;
			continue;
		}
		int gap=(m-(n-1)+1);
		ans[0]=szs[0];
		for(int i=0; i<gap; i++){
			ans[0]=(ans[0]*v[i])%N;
		}
		for(int i=1; i<n-1; i++){
			ans[i]=(v[gap+i-1]*szs[i])%N;
		}
		int fin=0;
		for(int i=0; i<n-1; i++){
			fin=(fin+ans[i])%N;
		}
		cout<<fin<<endl;
	}
	return 0;
}