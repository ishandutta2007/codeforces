/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], n, nxt[N], ps[N], nxtps[N];

bool f() {
	ps[0] = 0;
	for (int i = 0; i < n; i++) {
//		cout << a[i] << ' ';
		ps[i + 1] = ps[i] + a[i];
	}
//	cout << '\n';
//	for (int i = 0; i <= n; i++)
//		cout << ps[i] << ' ';
//	cout << '\n';
	for (int i = 0; i <= n; i++)
		nxt[i] = n, nxtps[i] = n + 1;
	vector <pair <int, int>> v = {make_pair(a[0], 0)};
	for (int i = 1; i < n; i++) {
		while ((int)v.size()) {
			if (v.back().F < a[i]) {
				nxt[v.back().S] = i;
				v.pop_back();
			} else {
				break;
			}
		}
		v.push_back({a[i], i});
	}
	v = {make_pair(ps[0], 0)};
	for (int i = 1; i <= n; i++) {
		while ((int)v.size()) {
			if (v.back().F < ps[i]) {
				nxtps[v.back().S] = i;
				v.pop_back();
			} else {
				break;
			}
		}
		v.push_back({ps[i], i});
	}
//	for (int i = 0; i <= n; i++) {
//		cout << nxt[i] << ' ' << nxtps[i] << '\n';
//	}
	bool f = true;
	for (int i = 0; i < n; i++) {
		f &= (nxtps[i + 1] - 1 >= nxt[i]);
	}
	return f;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	bool ans = f();
	reverse(a, a + n);
	ans &= f();
	cout << (ans ? "YES" : "NO") << '\n';
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