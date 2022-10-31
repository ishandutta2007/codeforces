#include <bits/stdc++.h>

#ifdef LOCAL
#include "E:\\Competitive-Programming\\Template\\Standard Template Codes\\debug-template.hpp"
#endif

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int sum = accumulate(a.begin(), a.end(), 0);
	vector<vector<long double>> dp(n + 1, vector<long double>(sum + 1));
	dp[0][0] = 1;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		for (int j = cur; j >= 0; j--) {
			for (int k = i; k >= 0; k--) {
				if (dp[k][j]) {
					dp[k + 1][j + a[i]] += dp[k][j];
				}
			}
		}
		cur += a[i];
	}
	vector<vector<long double>> choose(n + 1, vector<long double>(n + 1));
	for (int i = 0; i <= n; i++) {
		choose[i][0] = choose[i][i] = 1;
		for (int j = 1; j < i; j++) {
			choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
		}
	}
	long double ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sum; j++) {
			ans += dp[i][j] / choose[n][i] * min((sum - j) * 1.0L / (n - i), m * 0.5L * (2 * n - i) / (n - i));
		}
	}
	cout << fixed << setprecision(15) << ans << '\n';
	return 0;
}