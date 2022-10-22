/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 103;
int a[N];

void solve() {
	int n;
	cin >> n;
	int mx = 0, x = 0, y = 0, z = 0;
	bool i1 = false, im = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1)
			i1 = true;
		if (a[i] % 3 == 0)
			x++;
		else if (a[i] % 3 == 1)
			y++;
		else
			z++;
		mx = max(mx, a[i]);
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == mx - 1)
			im = true;
	}
	if (y == 0 && z == 0) {
		cout << mx / 3 << ' ';
	} else if (z == 0 || y == 0) {
		cout << mx / 3 + 1 << ' ';
	} else if (mx % 3 == 1 && !i1 && !im) {
		cout << mx / 3 + 1 << ' ';
	} else if (mx % 3 == 0) {
		cout << mx / 3 + 1 << ' ';
	} else {
		cout << mx / 3 + 2 << ' ';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}