/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, m;
	cin >> n >> m;
	bool f = false, h = false;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (b == c)
			f = true;
	}
	cout << ((f && m % 2 == 0) ? "YES\n" : "NO\n");
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}