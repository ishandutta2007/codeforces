/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, m;
	cin >> n >> m;
	vector <pair <int, pair <int, int>>> v;
	for (int i = 0; i < m; i++) {
		int x, w;
		cin >> x >> w;
		v.push_back(make_pair(w, make_pair(x, i + 1)));
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	vector <pair <int, int>> a;
	for (int i = 0; i < 2 * n; i++) {
		ans += v[i].F;
		a.push_back(v[i].S);
	}
	sort(a.begin(), a.end());
	cout << ans << '\n';
	for (int i = 0; i < n; i++) {
		cout << a[i].S << ' ' << a[2 * n - i - 1].S << '\n';
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}