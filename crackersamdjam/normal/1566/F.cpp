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
int const MM = 2e5+5;

int t, n, m;
ll a[MM];
ll dp[MM][2];
vector<pair<ll, ll>> v[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n>>m;
		a[0] = -1e10;
		a[n+1] = 1e10;
		for(int i = 1; i <= n; i++){
			cin>>a[i];
		}
		sort(a, a+n+1);
		while(m--){
			ll l, r;
			cin>>l>>r;
			int f = lower_bound(a, a+n+2, l)-a;
			int s = upper_bound(a, a+n+2, r)-a;
			if(f == s){
				v[s].emplace_back(l, r);
				// pr(l, r);
			}
		}

		for(int i = 0; i <= n+2; i++){
			sort(all(v[i]));
			vector<pair<ll, ll>> nx;
			ll rs = 1e10;
			reverse(all(v[i]));
			for(auto j: v[i]){
				if(j.second < rs){
					rs = j.second;
					nx.emplace_back(j);
				}
			}
			v[i] = move(nx);
			// pr("i", i);
			// for(auto j: v[i])
			// 	pr("  ", j.first, j.second);
			sort(all(v[i]));
		}

		memset(dp, 0x3f, sizeof dp);
		dp[0][0] = dp[0][1] = 0;

		for(int i = 1; i <= n+1; i++){
			int sz = size(v[i]);
			//try all combos of l/s
			// 0 means left first
			// 1 means right
			for(int fa = 0; fa <= 1; fa++){
				for(int fb = 0; fb <= 1; fb++){
					for(int j = -1; j < sz; j++){
						ll ls = (j >= 0) ? (v[i][j].first - a[i-1]) : 0;
						ll rs = (j+1 < sz) ? (a[i] - v[i][j+1].second) : 0;
						ll cost = dp[i-1][fa] + (ls)*(fa ? 1: 2) + (rs)*(fb ? 2 : 1);
						dp[i][fb] = min(dp[i][fb], cost);
					}
				}
			}
			// pr("  dp", i, sz, dp[i][0], dp[i][1]);
		}

		cout<<dp[n+1][0]<<'\n';

		for(int i = 0; i <= n+2; i++){
			v[i].clear();
		}
		// pr("________________");
	}
}