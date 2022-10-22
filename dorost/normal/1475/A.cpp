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
	int n;
	cin >> n;
	bool f = true;
	for (int i = 0; i < 60; i++) {
		if (n % 2 && n != 1)
			f = false;
		n /= 2;
	}
	cout << (!f ? "YES" : "NO") << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}