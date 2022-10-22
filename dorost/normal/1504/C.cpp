/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool ok (string s) {
	int x = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			x++;
		else
			x--;
		if (x < 0)
			return false;
	}
	return (x == 0);
}

void solve() {
	int n;
	string s;
	cin >> n >> s;
	string ans;
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1')
			x++;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			y++;
			if (y <= x / 2) {
				ans += '(';
			} else {
				ans += ')';
			}
		} else {
			z++;
			if (z % 2) {
				ans += '(';
			} else {
				ans += ')';
			}
		}
	}
	string ans2 = ans;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			ans2[i] = (ans2[i] == '(' ? ')' : '(');
		}
	}
	if (ok(ans) && ok(ans2)) {
		cout << "YES\n";
		cout << ans << '\n' << ans2 << '\n';
	} else {
		cout << "NO\n";
	}
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