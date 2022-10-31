#include <bits/stdc++.h>
using namespace std;

const int N = 22;

int dp[1 << N], prv[1 << N], a[N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		a[u] |= (1 << v), a[v] |= (1 << u);
	}
	for (int i = 0; i < n; i++) a[i] |= (1 << i);
	if (m == n * (n - 1) / 2) return puts("0"), 0;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) if ((i & (1 << j)) == 0 && (i == 0 || (dp[i] >> j & 1))) {
			dp[1 << j | i] = dp[i] | a[j];
			prv[1 << j | i] = j;
		}
	}
	int dap = (1 << n) - 1;
	for (int i = 1; i < (1 << n); i++) if (dp[i] == (1 << n) - 1 && __builtin_popcount(dap) > __builtin_popcount(i)) dap = i;
	vector<int> ans;
	cout << __builtin_popcount(dap) << endl;
	while (dap) cout <<1 + prv[dap] << " ", dap -= (1 << prv[dap]);
	cout << endl;
	return 0;
}