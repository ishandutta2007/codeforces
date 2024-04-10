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
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[j][i];
		}
	}
	int ans = m + 1;
	vector<int> ret;
	for (int j = 0; j < n - 1; j++) {
		vector<pair<int, int>> d(m);
		for (int i = 0; i < m; i++) {
			d[i] = {a[j][i] - a[n - 1][i], i};
		}
		sort(d.begin(), d.end(), greater<pair<int, int>>());
		int sum = 0, st = m;
		for (int i = 0; i < m; i++) {
			sum += d[i].first;
			if (sum < 0) {
				st = i;
				break;
			}
		}
		if (ans > m - st) {
			ans = m - st;
			ret.clear();
			for (int j = st; j < m; j++) {
				ret.push_back(d[j].second);
			}
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < ans; i++) {
		cout << ret[i] + 1 << " \n"[i == ans - 1];
	}
	return 0;
}