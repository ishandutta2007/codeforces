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
	int k, n, a, b;
	cin >> k >> n >> a >> b;
	if (k <= n * b) {
		cout << -1 << ' ';
		return;
	}
	cout << min(n, (k - n * b - 1) / (a - b)) << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}