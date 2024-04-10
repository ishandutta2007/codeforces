/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
int ps[N];

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	ps[0] = (s[0] == '+' ? 1 : -1);
	for (int i = 0; i < s.size(); i++) {
		if (i % 2) {
			s[i] = (s[i] == '-' ? '+' : '-');
		}
		if (i != 0) {
			ps[i] = ps[i - 1] + (s[i] == '+' ? 1 : -1);
		}
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		int ans = ps[r];
		if (l != 0) 
			ans -= ps[l - 1];
		if (ans == 0) {
			cout << 0 << ' ';
		} else {
			cout << ((r - l + 1) % 2 == 0 ? 2 : 1) << ' ';
		}
	}
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