/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int a[7], b[7], c[7];
	for (int i = 0; i < 7; i++) {
		cin >> a[i];
	}
	int x = a[0], y = a[1], z = a[2];
	b[0] = x;
	b[1] = y;
	b[2] = z;
	b[3] = x + y;
	b[4] = y + z;
	b[5] = x + z;
	b[6] = x + y + z;
	sort(b, b + 7);
	bool f = true;
	for (int i = 0; i < 7; i++) {
		if (a[i] != b[i])
			f = false;
	}
	if (f) {
		cout << x << ' ' << y << ' ' << z << '\n';
		return;
	}
	x = a[0], y = a[1], z = a[3];
	b[0] = x;
	b[1] = y;
	b[2] = z;
	b[3] = x + y;
	b[4] = y + z;
	b[5] = x + z;
	b[6] = x + y + z;
	sort(b, b + 7);
	f = true;
	for (int i = 0; i < 7; i++) {
		if (a[i] != b[i])
			f = false;
	}
	if (f) {
		cout << x << ' ' << y << ' ' << z << '\n';
		return;
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}