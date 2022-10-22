/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int ans[N][N], a[N][N];

void solve() {
	int n, m;
	cin >> n >> m;
	vector <pair <int, pair <int, int>>> v;
	set <int> st[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans[i][j] = 0;
			cin >> a[i][j];
			v.push_back(make_pair(a[i][j], make_pair(i, j)));
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			st[i].insert(j);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		ans[v[i].S.F][i] = v[i].F;
		st[v[i].S.F].erase(v[i].S.S);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans[i][j] == 0) {
				int x = *st[i].begin();
				st[i].erase(x);
				ans[i][j] = a[i][x];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}