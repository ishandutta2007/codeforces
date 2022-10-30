#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int sz[3]; cin >> sz[0] >> sz[1] >> sz[2];
	int n = sz[0] + sz[1] + sz[2];
	vector<int> used(n + 1, 0);
	for (int j : {0, 1, 2}) {
		for (int i = 0; i < sz[j]; i++) {
			int x; cin >> x;
			used[x] = j;
		}
	}
	vector<int> pre[3];
	for (int i : {0, 1, 2}) {
		pre[i] = vector<int>(n + 1, 0);
	}
	for (int i = 1; i <= n; i++) {
		for (int j : {0, 1, 2}) {
			pre[j][i] = pre[j][i - 1] + (used[i] == j);
		}
	}
	int ans = 0, max_diff = -n - 1;
	for (int i = n; i >= 0; i--) {
		max_diff = max(max_diff, pre[1][i] - pre[2][i]);
		ans = max(ans, pre[0][i] - pre[1][i] + pre[2][n] + max_diff);
	}
	cout << n - ans << endl;
	return 0;
}