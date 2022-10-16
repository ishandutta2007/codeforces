#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
template<typename T> int size(const T &a){return a.size();}

using namespace std;
using ll = long long;
const int MM = 2e5+5;

int t, n, dep[MM], par[MM];
vector<int> adj[MM], in[MM];
ll a[MM], dp[MM];

void dfs(int cur, int pre){
	par[cur] = pre;
	dep[cur] = dep[pre]+1;
	in[dep[cur]].emplace_back(cur);
	for(int u: adj[cur]){
		if(u != pre)
			dfs(u, cur);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 2,p; i <= n; i++){
			cin>>p;
			adj[i].emplace_back(p);
			adj[p].emplace_back(i);
		}
		for(int i = 2; i <= n; i++){
			cin>>a[i];
		}
		dfs(1, 0);

		for(int i = *max_element(dep+1, dep+1+n); i; i--){
			ll mn = LLONG_MAX/3, mx = LLONG_MIN/3; //for swap
			ll lo = LLONG_MAX/3, hi = LLONG_MIN/3; //for same
			for(int u: in[i]){
				lo = min(lo, a[u]);
				hi = max(hi, a[u]);
				mn = min(mn, a[u]);
				mx = max(mx, a[u]);
				for(int v: adj[u]){
					if(v == par[u])
						continue;
					mn = min(mn, a[u]-dp[v]);
					mx = max(mx, a[u]+dp[v]);
				}
			}
			for(int u: in[i]){
				dp[u] = max(dp[u], mx-a[u]);
				dp[u] = max(dp[u], a[u]-mn);
				for(int v: adj[u]){
					if(v == par[u])
						continue;
					dp[u] = max(dp[u], dp[v] + hi-a[u]);
					dp[u] = max(dp[u], dp[v] + a[u]-lo);
				}
			}
		}
		cout<<dp[1]<<'\n';

		for(int i = 1; i <= n; i++){
			adj[i].clear();
			in[i].clear();
			dp[i] = 0;
		}
	}
}