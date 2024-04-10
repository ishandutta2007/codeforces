#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int f[18][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int n; cin >> n;
		vector<int> a(n);
		vector<long long> pre(n + 1, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			f[0][i] = a[i];
		}
		for (int i = 1; i < 18; i++) {
			for (int j = 0; j < n; j++) {
				f[i][j] = f[i - 1][j];
				if (j + (1 << i - 1) < n) {
					f[i][j] = max(f[i][j], f[i - 1][j + (1 << i - 1)]);
				}
			}
		}
		auto query = [&](int l, int r) {
			int k = 31 - __builtin_clz(r - l + 1);
			return max(f[k][l], f[k][r - (1 << k) + 1]);
		};
		int m; cin >> m;
		vector<pair<int, int> > b(m);
		for (int i = 0; i < m; i++) {
			cin >> b[i].second >> b[i].first;
		}
		sort(b.begin(), b.end());
		for (int i = m - 2; i >= 0; i--) {
			b[i].second = max(b[i].second, b[i + 1].second);
		}
		vector<int> pos(n + 1, 0);
		for (int i = 0, j = 0; i <= n; i++) {
			while (j < m && b[j].first < i) j++;
			pos[i] = j;
		}
		int cur = 0;
		int ans = 0;
		while (cur < n) {
			int st = cur;
			int en = n + 1;
			while (en - st > 1) {
				int mid = st + en >> 1;
				if (pos[mid - cur] >= m || b[pos[mid - cur]].second < query(cur, mid - 1)) {
					en = mid;
				} else {
					st = mid;
				}
			}
			if (st == cur) {
				break;
			}
			cur = st;
			ans++;
		}
		if (cur < n) {
			cout << -1 << "\n";
		} else {
			cout << ans << "\n";
		}
	}
	return 0;
}