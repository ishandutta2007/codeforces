/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s, t;
	int n;
	cin >> n >> s >> t;
	int ans = 0, lst = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			ans += 2;
			continue;
		}
		if (s[i] == '0') {
			ans++;
		}
		if (i == 0) {
			continue;
		}
		if (lst < i - 1 && s[i] != s[i - 1] && t[i] != t[i - 1])
			ans++, lst = i;
	}
	cout << ans << ' ';
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