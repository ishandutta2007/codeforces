/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	for (int i = 0; i < m; i++)
		s += 'B';
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int l = x - 1;
		int r = m - x;
		if (l > r)
			swap(l, r);
		if (s[l] == 'B')
			s[l] = 'A';
		else
			s[r] = 'A';
	}
	cout << s << '\n';
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