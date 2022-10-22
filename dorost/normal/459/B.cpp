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
int a[N];

void solve() {
	int n, mx = 0, mn = INT_MAX;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == mn)
			x++;
		if (a[i] == mx)
			y++;
	}
	cout << mx - mn << ' ';
	if (x == n) {
		cout << x * (x - 1) / 2;
	} else {
		cout << x * y;
	}
}

int32_t main() {
	int t = 1;
	while (t--) {
		solve();
	}
}