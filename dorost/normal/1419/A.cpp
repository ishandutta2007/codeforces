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
	if (n % 2) {
		bool f = false;
		for (int i = 0; i < n; i += 2) {
			if ((s[i] - '0') % 2)
				f = true;
		}
		cout << (f ? 1 : 2) << ' ';
	} else {
		bool f = false;
		for (int i = 1; i < n; i += 2) {
			if ((s[i] - '0') % 2 == 0)
				f = true;
		}
		cout << (f ? 2 : 1) << ' ';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}