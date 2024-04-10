/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 333, M = 101234;
int cnt[M], cnt2[M];
vector <pair <int, int>> v[M];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			v[x].push_back(make_pair(i, j));
		}
	}
	ll ans = 0;
	for (int i = 0; i < M; i++) {
		if (v[i].empty())
			continue;
		vector <ll> a, b;
		for (auto [x, y] : v[i]) {
			a.push_back(x);
			b.push_back(y);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		ll ps = a[0];
		for (ll i = 1; i < a.size(); i++) {
			ans += i * a[i] - ps;
			ps += a[i];
		}
		ps = b[0];
		for (ll i = 1; i < b.size(); i++) {
			ans += i * b[i] - ps;
			ps += b[i];
		}
	}
	cout << ans;
}