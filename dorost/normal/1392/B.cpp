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
int a[N], b[N];

void solve() {
	int n, k;
	cin >> n >> k;
	bool f = false;
	int mx = -100000000000000ll;
	for (int i = 0; i < n; i++) {
		cin >> a[i], mx = max(mx, a[i]);
		if (a[i] == 0)
			f = true;
	}
	if ((!f && k == 1) || (f && k % 2)) {
		for (int i = 0; i < n; i++) 
			cout << mx - a[i] << ' ';
	}else if ((!f && k % 2 == 0) || (f && k % 2 == 0)) {
		int mx2 = -100000000000000ll;
		for (int i = 0; i < n; i++) 
			b[i] = mx - a[i], mx2 = max(mx2, b[i]);
		for (int i = 0; i < n; i++)
			cout << mx2 - b[i] << ' ';
	}else {
		int mx2 = -100000000000000ll;
		int mx3 = -100000000000000ll;
		for (int i = 0; i < n; i++) 
			b[i] = mx - a[i], mx2 = max(mx2, b[i]);
		for (int i = 0; i < n; i++)
			a[i] = mx2 - b[i], mx3 = max(mx3, a[i]);
		for (int i = 0; i < n; i++)
			cout << mx3 - a[i] << ' ';
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