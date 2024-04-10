/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], b[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i != 0) {
			b[i - 1] = a[i] - a[i - 1];
		}
	}
	int mx = 0;
	for (int i = 0; i < n; i++) {
		if (i != 0 && a[i] == a[i - 1])
			continue;
		ll u = a[i];
		int x = 2;
		ll sum = 0;
		for (int k = i + 1; k < n; k++) {
			if (a[k] == a[i])
				x++;
			else {
				sum = a[k] - a[i];
				break;
			}
		}
		if (sum != 0) {
			for (int l = 0; l < 50; l++) {
				int in = lower_bound(a, a + n, sum * 2LL + u) - a;
				if (in == n) {
					break;
				}
				sum = a[in] - u;
				x++;
			}
		} else {
			x--;
		}
		mx = max(mx, x);
	}
	cout << n - mx << ' ';
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