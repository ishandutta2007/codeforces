#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1 << 20;
const int INF = 1e9;
int n, k, cnt[N];

tuple<vector<int>, vector<int>, vector<int>> solve(int a, int b) {
	if (a == b) {
		if (!cnt[a])
			return {{INF}, {INF}, {-INF}};
		else
			return {{INF}, {0}, {0}};
	}
	int m = (a + b) / 2;
	auto [ldp, lmn, lmx] = solve(a, m);
	auto [rdp, rmn, rmx] = solve(m + 1, b);
	int p = (b - a + 1) / 2;
	vector<int> dp(2 * p), mn(2 * p), mx(2 * p);

	for (int i = 0; i < p; i++) {
		mn[i] = min(lmn[i], rmn[i] + p);
		mx[i] = max(lmx[i], rmx[i] + p);
		mn[i + p] = min(rmn[i], lmn[i] + p);
		mx[i + p] = max(rmx[i], lmx[i] + p);
		dp[i] = min({ldp[i], rdp[i], p + rmn[i] - lmx[i]});
		dp[i + p] = min({ldp[i], rdp[i], p + lmn[i] - rmx[i]});
	}
	return {dp, mn, mx};
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	auto [res, a, b] = solve(0, (1 << k) - 1);
	for (auto x : res)
		cout << x << " ";
	return 0;
}