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
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	int x = (n + k + 1) / 2;
	int mn = INT_MAX, in = 0;
	sort(b, b + n);
	for (int i = 0; i <= n - x; i++) {
		if (mn > b[i + x - 1] - b[i]) {
			mn = b[i + x - 1] - b[i];
			in = i;
		}
	}
	cout << b[in] << ' ' << b[in + x - 1] << '\n';
	int l = b[in], r = b[in + x - 1];
	int ps = 0;
	int lst = 0;
	for (int i = 0; i < n; i++) {
		ps += ((a[i] >= l) && (a[i] <= r) ? 1 : -1);
		if (ps > 0) {
			k--;
			if (k == 0) {
				cout << lst + 1 << ' ' << n << '\n';
				return;
			}
			cout << lst + 1 << ' ' << i + 1 << '\n';
			lst = i + 1;
			ps = 0;
		}
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}