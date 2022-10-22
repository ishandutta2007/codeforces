/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s;
	cin >> s;
	int n = (int)s.size() / 2;
	int a = n, b = n;
	for (int i = 0; i < n * 2; i++) {
		if (s[i] == '(')
			a--;
		else if (s[i] == ')')
			b--;
	}
	if (a == 0 || b == 0) {
		cout << "YES\n";
		return;
	}
	string t = s;
	int cnt = 0;
	int ps = 0;
	int mn = INT_MAX;
	for (int i = 0; i < n * 2; i++) {
		if (s[i] == '?') {
			cnt++;
			if (cnt <= a) {
				t[i] = '(', ps++;
			} else
				t[i] = ')', ps--;
		} else {
			t[i] = s[i];
			if (s[i] == '(')
				ps++;
			else
				ps--;
		}
		if (cnt == a) {
			mn = min(mn, ps);
		}
		assert(ps >= 0);
	}
	cout << (mn > 1 ? "NO\n" : "YES\n");
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}