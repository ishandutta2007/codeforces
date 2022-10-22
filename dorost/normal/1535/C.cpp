/* 	* In the name of GOD 
 	* Thanks God */
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int l1[N], l0[N];

void solve() {
	string s;
	cin >> s;
	int x = 0, w = 2, ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '?') {
			if (i % 2) {
				s[i] = (s[i] == '0' ? '1' : '0');
			}
		}
	}
	l1[0] = (s[0] == '1' ? 0 : -1);
	l0[0] = (s[0] == '0' ? 0 : -1);
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '1') {
			l1[i] = i;
			l0[i] = l0[i - 1];
		} else if (s[i] == '0') {
			l0[i] = i;
			l1[i] = l1[i - 1];
		} else {
			l0[i] = l0[i - 1];
			l1[i] = l1[i - 1];
		}
	}
	for (int i = 0; i < s.size(); i++) {
		ans += i - (min(l0[i], l1[i]) + 1) + 1;
	}
	cout << ans << ' ';
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