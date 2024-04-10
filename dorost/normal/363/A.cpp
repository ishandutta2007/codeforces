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
	reverse(s.begin(), s.end());
	for (auto c : s) {
		int x = c - '0';
		if (x >= 5) {
			cout << "-O|";
			x -= 5;
		}else {
			cout << "O-|";
		}
		for (int i = 0; i < x; i++) {
			cout << 'O';
		}
		cout << '-';
		for (int i = x + 1; i < 5; i++)
			cout << 'O';
		cout << '\n';
	}
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}