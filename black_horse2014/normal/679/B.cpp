#include <bits/stdc++.h>
using namespace std;

long long c[110000];
int dp[1100000];

pair<int, long long> solve(long long en) {
	if (en == 0) return make_pair(0, 0);
	if (en <= 1000000) {
		int ans = *max_element(dp + 1, dp + en + 1);
		for (int i = en; i >= 1; i--) {
			if (dp[i] == ans) return make_pair(ans, i);
		}
	}
	pair<int, long long> ret = make_pair(0, 0);
	ret = max(ret, solve(1000000));
	int k = upper_bound(c + 1, c + 100001, en) - c - 1;
	if (en >= c[k]) {
		pair<int, long long> temp = solve(en - c[k]);
		temp.first += 1, temp.second += c[k];
		ret = max(ret, temp);
	}
	{
		pair<int, long long> temp = solve(c[k] - c[k - 1] - 1);
		temp.first += 1, temp.second += c[k - 1];
		ret = max(ret, temp);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	long long n; cin >> n;
	for (int i = 1; i <= 100000; i++) c[i] = 1LL * i * i * i;
	dp[0] = 0;
	for (int i = 1, j = 0; i <= 1000000; i++) {
		if (c[j + 1] <= i) j++;
		dp[i] = dp[i - c[j]] + 1;
	}
	pair<int, long long> ret = solve(n);
	cout << ret.first << ' ' << ret.second << endl;
	return 0;
}