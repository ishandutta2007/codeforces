#include <bits/stdc++.h>
using namespace std;

int dp[33000];
int cnt[26];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int n, m, k; string s; cin >> n >> m >> k >> s;
		for (int i = 0; i < 26; i++) cnt[i] = 0;
		for (int i = 0; i < k; i++) cnt[s[i] - 'A']++;
		const int inf = 1e9;
		int ans = inf;
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j <= n + 1; j++) dp[j] = -inf;
			dp[0] = 0;
			int sum = 0;
			for (int j = 0; j < 26; j++) {
				if (j == i) continue;
				for (int k = min(n, sum + cnt[j]); k >= 0; k--) {
					if (k <= cnt[j]) dp[k] = max(dp[k] + cnt[j], sum);
					else dp[k] = max(dp[k] + cnt[j], dp[k - cnt[j]]);
					dp[k] = max(dp[k], dp[k + 1]);
				}
				sum += cnt[j];
			}
			for (int j = max(0, n - cnt[i]); j <= n; j++) {
				if (m - dp[j] + n - j > cnt[i]) continue;
				ans = min(ans, max(0, m - dp[j]) * (n - j));
			}
		}
		cout << ans << endl;
	}
	return 0;
}