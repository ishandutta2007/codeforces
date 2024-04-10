/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int n, x;
	cin >> n;
	x = n;
	int an = n, mx = 1;
	for (int i = 2; i * i <= n; i++) {
		int cnt = 0;
		while (n % i == 0)
			n /= i, cnt++;
		if (cnt >= mx) {
			mx = cnt;
			an = i;
		}
	}
	cout << mx << '\n';
	for (int i = 0; i < mx - 1; i++)
		cout << an << ' ', x /= an;
	cout << x << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}