#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;


const int N = 1e5;
ll dp[N][2];

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	ll ans = 0;
	for(int k = 0; k < 2; ++k)
		for(int i = 0; i < n; ++i) {
			cin >> dp[i][k];
			ans = max(ans, dp[i][k]);
		}
	for(int i = 1; i < n; ++i) {
		for(int k = 0; k < 2; ++k) {
			ll self = dp[i][k];
			dp[i][k] = max(dp[i][k], self + dp[i-1][!k]);
			if(i-2 >= 0) {
				dp[i][k] = max(dp[i][k], self + dp[i-2][k]);
				dp[i][k] = max(dp[i][k], self + dp[i-2][!k]);
			}
			ans = max(ans, dp[i][k]);
		}
	}
	cout << ans << '\n';
}