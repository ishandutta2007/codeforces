/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], b[N], ps[N], ss[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	ps[0] = b[0];
	for (int i = 1; i < n; i++) {
		ps[i] = ps[i - 1] + b[i];
	}
	ss[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		ss[i] = ss[i + 1] + a[i];
	}
	int mn = INT_MAX;
	for (int i = 0; i < n; i++) {
		int x = 0, y = 0;
		if (i != 0) {
			x = ps[i - 1];
		}
		if (i != n - 1) {
			y = ss[i + 1];
		}
		mn = min(mn, max(x, y));
	}
	cout << mn << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}