#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int n, k;
vector<int> v;

// first is G(s), second is k(s)
// k(s_opt) has to be increasing with lambda
pair<ll, int> dp(ll lambda){
	// dp[did_use_last]
	array<pair<ll, int>, 2> dp{};
	for(int i=0;i<n;++i){
		auto me = make_pair(dp[0].first + v[i] + lambda, dp[0].second-1);
		dp[0] = min(dp[0], dp[1]);
		dp[1] = me;
	}
	dp[0] = min(dp[0], dp[1]);
	//cerr << lambda << " : " << dp[0].first << " " << dp[0].second << "\n";
	return dp[0];
}

signed main(){
	cin >> k >> n;
	v.resize(n);
	for(auto &e:v) cin >> e;
	sort(v.begin(), v.end());
	for(int i=0;i+1<n;++i){
		v[i] = v[i+1] - v[i];
	}
	v.pop_back();
	--n;
	k = -k;
	
	ll l = -1, r = 1;
	while(dp(r-1).second < k) r*=2;
	++r;
	while(dp(l).second > k) l*=2;
	while(l+1 < r){
		const int m = l + (r-l)/2;
		auto s = dp(m);
		if(s.second <= k){
			l = m;
		} else {
			r = m;
		}
	}
	auto s = dp(l);
	ll ans = s.first + k*l;
	cout << ans << "\n";
	
	
	
}