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
	int x = 0, y = 0, ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			x++;
		if (s[i] == '[') 
			y++;
		if (s[i] == ')' && x) {
			x--;
			ans++;
		}
		if (s[i] == ']' && y) {
			y--;
			ans++;
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}