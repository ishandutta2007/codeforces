#include <bits/stdc++.h>
using namespace std;

int a[2222], b[2222];

int main() {
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i-1];
	for (int i = 1; i <= m; i++) cin >> b[i], b[i] += b[i-1];
	int x; cin >> x;
	int ans = 0;
	vector<pair<int, int> > c;
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			c.emplace_back(b[j] - b[i-1], j - i + 1);
		}
	}
	sort(c.begin(), c.end());
	for (int i = 0; i+1 < c.size(); i++) c[i+1].second = max(c[i+1].second, c[i].second);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int t = x / (a[j] - a[i-1]);
			int k = upper_bound(c.begin(), c.end(), make_pair(t, m+1)) - c.begin() - 1;
			if (k >= 0) {
				ans = max(ans, (j - i + 1) * c[k].second);
			}
		}
	}
	cout << ans << endl;
	return 0;
}