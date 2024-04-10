/*  * In the name of GOD 
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
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1)
			a++;
		else
			b++;
	}
	b %= 2;
	if (b) {
		if (a < 2) {
			cout << "NO\n";
		} else {
			cout << (a % 2 ? "NO" : "YES") << '\n';
		}
	} else {
		cout << (a % 2 ? "NO" : "YES") << '\n';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}