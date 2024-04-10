/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool div(string s, string t) {
	if (s.size() % t.size())
		return false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != t[i % t.size()])
			return false;
	}
	return true;
}

void solve() {
	string s, t;
	cin >> s >> t;
	string a;
	for (int i = 1; i <= 25; i++) {
		a += s;
		if (div(a, t)) {
			cout << a << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}