#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll dp[510][5010];
ll h[510];
ll K, N;

void setup() {
    for(ll i=1;i<=N;++i) {
        for(ll j=1;j<=N*K;++j) {
			for(int k=0;k<=min(j, K);++k) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-k]+h[k]);
			}
            //dp[i][j] = dp[i-1][j-1] + h[i];
            //dp[i][j] = max(dp[i][j], dp[i-1][j]);
			//cerr << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
	cin >> K;
	vector<ll> v(N*K);
	for(auto& ii : v) cin >> ii;
	vector<ll> f(N);
	for(auto& ii : f) cin >> ii;
	for(ll i=1;i<=K;++i) {
		cin >> h[i];
	}
	setup();
	
	// stores number of people, number of objects
	map<ll, pii> mp;

	for(ll i=0;i<N;++i) {
		if(mp.count(f[i]) == 0) {
			mp[f[i]] = pii(0, 0);
		}
		++mp[f[i]].first;
	}
	for(auto& x : v) {
		if(mp.count(x) != 0) {
			mp[x].second++;
		}
	}
	ll ans = 0;
	for(const auto& x : mp) {
		ans += dp[x.second.first][x.second.second];
	}
	cout << ans << endl;
	
    return 0;
}