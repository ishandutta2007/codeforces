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
	int n = s.size();
	int ans = 0;
	int x = 0;
	for (int i = 0; i < n; i++) {
		if (i < n - 2) {
			if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
				ans += 2;
				s[i + 1] = x % 10 + '0';
				x++;
				s[i + 2] = x % 10 + '0';
				x++;
				continue;
			} else if (s[i] == s[i + 2]) {
				ans++;
				s[i + 2] = x % 10 + '0';
				x++;
				continue;
			}
		} 
		if (i < n - 1) {
			if (s[i] == s[i + 1]) {
				ans++;
				s[i + 1] = x % 10 + '0';
				x++;
				continue;
			}
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