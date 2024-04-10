/* 	* In the name of GOD 
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
	cout << (s[0] - '1') * 10 + (s.size() * (s.size() + 1) / 2) << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}