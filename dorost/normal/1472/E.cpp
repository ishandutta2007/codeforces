/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int h[2 * N];
vector <pair <int, int>> v[2 * N];
pair <int, int> a[N];
pair <int, int> b[2 * N];

void solve() {
	int n;
	cin >> n;
	vector <pair <int, int>> c1;
	for (int i = 0; i < n; i++) {
		cin >> h[i * 2] >> h[i * 2 + 1];
		a[i] = {h[i * 2], h[i * 2 + 1]};
	}
	sort(h, h + 2 * n);
	int x = 0;
	c1.push_back({h[0], 0});
	for (int i = 1; i < 2 * n; i++) {
		if (h[i] != h[i - 1]) {
			x++;
			c1.push_back({h[i], x});
		}
	}
	for (int i = 0; i < n; i++) {
		int in = lower_bound(c1.begin(), c1.end(), make_pair(a[i].F, -1)) - c1.begin();
		a[i].F = c1[in].S;
		in = lower_bound(c1.begin(), c1.end(), make_pair(a[i].S, -1)) - c1.begin();
		a[i].S = c1[in].S;
	}
	for (int i = 0; i < 2 * n + 10; i++)
		v[i].clear();
	for (int i = 0; i < n; i++) {
		v[a[i].F].push_back({i, a[i].S});
		v[a[i].S].push_back({i, a[i].F});
	}
	for (int i = 0; i < 2 * n + 10; i++) {
		if (i == 0) {
			int mn = INT_MAX, an = -1;
			for (auto x : v[0]) {
				if (x.S < mn) {
					mn = x.S;
					an = x.F;
				}
			}
			b[i] = {mn, an};
		} else {
			int mn = b[i - 1].F, an = b[i - 1].S;
			for (auto x : v[i]) {
				if (x.S < mn) {
					mn = x.S;
					an = x.F;
				}
			}
			b[i] = {mn, an};
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i].F == 0) {
			cout << -1 << ' ';
		} else {
			if (b[a[i].F - 1].S != -1 && b[a[i].F - 1].F < a[i].S) {
				cout << b[a[i].F - 1].S + 1 << ' ';
			} else {
				cout << -1 << ' ';
			}
		}
	}
	cout << '\n';
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