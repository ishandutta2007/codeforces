/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s;
	cin >> s;
	bool f = false, h = true;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == s[i + 1] && s[i] == '1' && f == false) {
			f = true;
		}
		if (s[i] == s[i + 1] && s[i] == '0' && f) {
			h = false;
		}
	}
	cout << (h ? "YES" : "NO") << ' ';
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