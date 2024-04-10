/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, m;
	string s;
	cin >> n >> m >> s;
	m = min(m, n);
	for (int i = 0; i < m; i++) {
		string t = s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '1')
				continue;
			int x = 0;
			if (j != 0) {
				x += s[j - 1] - '0';
			}
			if (j != n - 1) {
				x += s[j + 1] - '0';
			}
			if (x == 1) {
				t[j] = '1';
			}
		}
		s = t;
	}
	cout << s << '\n';
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