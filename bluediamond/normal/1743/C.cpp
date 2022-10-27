#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
mt19937 rng(228);
#else
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

#define int long long

const int INF = (int)1e18 + 7;

signed main() {
#ifndef ONPC
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		vector<int> ok(n);
		vector<int> a(n);
		assert((int)s.size() == n);
		for (int i = 0; i < n; i++) {
			char ch = s[i];
			assert(ch == '0' || ch == '1');
			ok[i] = ch - '0';
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<vector<int>> dp(2, vector<int>(n, 0));
		if (ok[0]) {
			dp[1][0] = a[0];
		}
		for (int i = 1; i < n; i++) {
			dp[0][i] = dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
			if (ok[i] == 1) {
				dp[0][i] = max(dp[0][i], dp[0][i - 1] + a[i - 1]);
				dp[1][i] += a[i];
			}
			else {
				assert(ok[i] == 0);
			}
		}
		cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
	}

	return 0;
}


/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */