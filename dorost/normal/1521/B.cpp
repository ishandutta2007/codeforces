/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234, inf = 1000 * 1000 * 1000;
int a[N], p[N];

void solve() {
	int n, mn = INT_MAX, in = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < mn) {
			mn = a[i];
			in = i;
		}
	}
	int y = 1;
	for (int i = 1;; i++) {
		if (__gcd(inf + i + 1, mn) == 1) {
			y = i;
			break;
		}
	}
	if (n == 1) {
		cout << 0 << endl;
		return;
	}
	cout << n - 1 + (in != 0) << '\n';
	for (int i = 0; i < n; i++) {
		if (i == in)
			continue;
		int x = inf + i + y;
		if (i == 0) 
			x = inf + in + y;
		cout << in + 1 << ' ' << i + 1 << ' ' << mn << ' ' << x << '\n';
	}
	if (0 != in) {
		cout << in + 1 << ' ' << 1 << ' ' << inf + in + y << ' ' << mn << '\n';;
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