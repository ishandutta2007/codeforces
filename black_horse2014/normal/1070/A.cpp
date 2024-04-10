#include <bits/stdc++.h>
using namespace std;

int dp[550][5500];
pair<int, int> pr[550][5500];
pair<int, int> q[3000000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int d, s; cin >> d >> s;
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	int qn = 0; q[qn++] = {0, 0};
	for (int i = 0; i < qn; i++) {
		auto t = q[i];
		int mod = t.first, sum = t.second;
		if (mod == 0 && sum == s) {
			int len = dp[0][s];
			string ans;
			while(len--) {
				ans.push_back(pr[mod][sum].second + '0');
				int state = pr[mod][sum].first;
				mod = state / 5001, sum = state % 5001;
			}
			reverse(ans.begin(), ans.end());
			cout << ans << endl;
			return 0;
		}
		for (int j = 0; j < 10; j++) {
			if (sum + j <= s) {
				int nmod = (mod * 10 + j) % d;
				int nsum = sum + j;
				if (!~dp[nmod][nsum]) {
					dp[nmod][nsum] = dp[mod][sum] + 1;
					pr[nmod][nsum] = make_pair(mod * 5001 + sum, j);
					q[qn++] = make_pair(nmod, nsum);
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}