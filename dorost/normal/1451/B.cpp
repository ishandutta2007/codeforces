/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, q;
	string s;
	cin >> n >> q >> s;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		bool f = false;
		for (int i = 0; i < l; i++) {
			if (s[i] == s[l])
				f = true;
		}
		for (int i = r + 1; i < n; i++) {
			if (s[i] == s[r])
				f = true;
		}
		cout << (f ? "YES" : "NO") << '\n';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}