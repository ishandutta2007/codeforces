/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

int32_t main() {
	int n, mx = INT_MIN, mn = INT_MAX;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	if (mx - mn <= 1) {
		cout << n << '\n';
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		return 0;
	}
	int cnt[3] = {};
	for (int i = 0; i < n; i++) {
		cnt[a[i] - mn]++;
	}
	int an = -1, mn1 = INT_MAX;
	for (int i = -n; i <= n; i++) {
		int x = cnt[0];
		int y = cnt[1];
		int z = cnt[2];
		x -= i;
		z -= i;
		y += 2 * i;
		if (x < 0 || z < 0 || y < 0) {
			continue;
		}
		int aa = min(cnt[0], x) + min(cnt[1], y) + min(cnt[2], z);
		if (aa < mn1) {
			mn1 = aa;
			an = i;
		}
	}
	int x = cnt[0];
	int y = cnt[1];
	int z = cnt[2];
	x -= an;
	z -= an;
	y += 2 * an;
	cout << mn1 << '\n';
	for (int i = 0; i < x; i++) {
		cout << mn << ' ';
	}
	for (int i = 0; i < y; i++) {
		cout << mn + 1 << ' ';
	}
	for (int i = 0; i < z; i++) {
		cout << mn + 2 << ' ';
	}
}