/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	bool f = false;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if ((int)sqrt(x) * (int)sqrt(x) != x) {
			f = true;
		}
	}
	cout << (f ? "YES" : "NO") << '\n';
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