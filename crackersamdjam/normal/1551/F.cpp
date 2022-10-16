// https://cboj.ca/problem/cbojrxp6
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
int const MM = 105;
ll const mod = 1e9+7;

int t, n, K;
vector<int> adj[MM];
vector<int> in[MM];
int cnt[MM], tot[MM];
int dd;

void dfs(int cur, int pre, int dis){
	cnt[dis]++;
	dd = max(dd, dis);
	for(int u: adj[cur]){
		if(u != pre)
			dfs(u, cur, dis+1);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n>>K;
		for(int i = 0,a,b; i < n-1; i++){
			cin>>a>>b;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}

		ll ans = 0;

		for(int i = 1; i <= n; i++){
			for(int u: adj[i]){
				dd = 0;
				dfs(u, i, 1);
				for(int j = 0; j <= dd; j++){
					in[j].emplace_back(cnt[j]);
					cnt[j] = 0;
				}
			}
			for(int j = 0; j <= n; j++){
				vector<ll> dp(K+1);
				dp[0] = 1;
				for(auto v: in[j]){
					for(int k = K; k > 0; k--){
						dp[k] += dp[k-1]*v;
						dp[k] %= mod;
					}
				}
				ans += dp[K];
				ans %= mod;
				in[j].clear();
			}
		}

		if(K == 2){
			ans = (ll)n*(n-1)/2%mod;
		}

		cout<<ans<<'\n';

		for(int i = 0; i <= n; i++){
			adj[i].clear();
		}
	}	
}