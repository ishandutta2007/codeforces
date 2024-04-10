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
	string s;
	cin >> n >> s;
	int t = 0, m = 0;
	bool f = false;
	int x = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'T') {
			x++;
			t++;
		} else {
			x--;
			m++;
		}
		if (x < 0) {
			cout << "NO\n";
			return;
		}
	}
	if (m != n / 3) {
		cout << "NO\n";
		return;
	}
	x = 0;
	reverse(s.begin(), s.end());
	for (int i = 0; i < n; i++) {
		if (s[i] == 'T') {
			x++;
			t++;
		} else {
			x--;
			m++;
		}
		if (x < 0) {
			cout << "NO\n";
			return;
		}
	}
	cout << (x >= 0 ? "YES" : "NO") << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}