/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
const ll ING = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL + 69; // wefwef
int l[N], s[N], a[N];
vector <pair <int, ll>> v[N];
ll ps[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] -= (i + 1);
	}
	ll ans = 0;
	int lst = -1;
	for (int i = 0; i < n; i++) {
		while (lst != n - 1 && a[lst + 1] >= (-1 * i))
			lst++;
		l[i] = lst;
		ans += (lst - i + 1);
	}
	lst = -1;
	int bad = N;
	for (int i = 0; i < n; i++) {
		while (lst != n - 1) {
			if (a[lst + 1] >= (-1 * i))
				lst++;
			else {
				if (bad == N) {
					bad = a[lst + 1];
					lst++;
				}
				else
					break;
			}
		}
		s[i] = lst;
		if (bad == a[i])
			bad = N;
		if (bad >= (-1 * (i + 1)))
			bad = N;
		ps[i + 1] = ps[i] + l[i];
		if (v[l[i]].empty()) {
			v[l[i]].push_back(make_pair(i, s[i] - l[i]));
		} else {
			v[l[i]].push_back(make_pair(i, s[i] - l[i] + v[l[i]].back().S));
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int p, x;
		cin >> p >> x;
		--p;
		x -= (p + 1);
		if (x >= a[p]) {
			if (p == 0 || a[p] == x || v[p - 1].empty()) {
				cout << ans << '\n';
				continue;
			}
			ll wef = v[p - 1].back().S;
			int in = upper_bound(v[p - 1].begin(), v[p - 1].end(), make_pair(-x, -ING)) - v[p - 1].begin() - 1;
			if (in >= 0)
				wef -= v[p - 1][in].S;
			cout << ans + wef << '\n';
		} else {
		    ll r = -x - 1;
			ll L = lower_bound (l, l + n, p) - l;
			if (L > r) {
				cout << ans << '\n';
			} else {
				ll wef = ps[r + 1] - ps[L];
				wef -= (r - L + 1LL) * (ll)(p - 1LL);
				cout << ans - wef << '\n';
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}