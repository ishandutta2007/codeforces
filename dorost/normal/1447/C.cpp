/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int ps[N];
pair <int, int> a[N];

void solve() {
	int n, w;
	cin >> n >> w;
	ps[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].F;
		a[i].S = i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		ps[i + 1] = ps[i] + a[i].F;
	}
	for (int i = 0; i <= n; i++) {
		int x = lower_bound(ps + i + 1, ps + n + 1, ps[i] + ((w + 1) / 2)) - ps;
		if (x == n + 1)
			x = n;
		int y = ps[x] - ps[i];
//		cerr << 'y' << i + 1 << ' ' << x << ' ' << y << '\n';
		if (y >= ((w + 1) / 2) && y <= w) {
			cout << x - i << '\n';
			for (int j = i + 1; j <= x; j++) {
				cout << a[j - 1].S + 1 << ' ';
			}
			cout << '\n';
			return;
		}
	}
	cout << -1 << '\n';
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