/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s, t;
	cin >> s >> t;
	if (t.size() > s.size()) {
		cout << "NO ";
		return;
	}
	if (t.size() == s.size()) {
		if (s == t) {
			cout << "YES ";
		} else {
			cout << "NO ";
		}
		return;
	}
	int x = (t.size() - s.size()) % 2, lst = x - 1, in = 0;
	for (int i = x; i < s.size(); i++) {
		if ((i - lst) % 2 == 0) {
			continue;
		}
		if (in == t.size())
			continue;
		if (t[in] == s[i]) {
			lst = i;
			in++;
		}
	}
	if (in != t.size() || (s.size() - lst) % 2 == 0) {
		cout << "NO ";
	} else {
		cout << "YES "; 
	}
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