/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (t[i] == '1') {
			if (s[i] != '1') {
				ans++;
			} else if (i != 0 && s[i - 1] == '1') {
				ans++;
				s[i - 1] = '0';
			} else if (i != n - 1 && s[i + 1] == '1') {
				ans++;
				s[i + 1] = '0';
			}
		}
	}
	cout << ans << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}