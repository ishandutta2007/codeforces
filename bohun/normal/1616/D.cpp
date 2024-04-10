#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &e : a)
			cin >> e;
		int x;
		cin >> x;
		for (auto &e : a)
			e -= x;

		vector<vector<int>> dp(n, vector<int>(3, -1e9));
		dp[0][0] = 0;
		dp[0][1] = 1;

		for (int i = 1; i < n; i++) {
			dp[i][0] = *max_element(dp[i - 1].begin(), dp[i - 1].end());
			dp[i][1] = 1 + dp[i - 1][0];
			if (a[i - 1] + a[i] >= 0)
				dp[i][2] = 1 + dp[i - 1][1];
			if (i >= 2 && min(a[i - 2], 0) + a[i - 1] + a[i] >= 0)
				dp[i][2] = max(dp[i][2], 1 + dp[i - 1][2]);
		}

		cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';
	}
	return 0;
}