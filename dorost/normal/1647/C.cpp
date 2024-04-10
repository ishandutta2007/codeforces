/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101;
string s[N];

void solve() {
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++)
			if (s[i][j] == '1')
				ans++;
	}
	if (s[0][0] == '1') {
		cout << -1 << '\n';
		return;
	}
	cout << ans << '\n';
	for (int i = m - 1; i >= 1; i--) {
		for (int j = 0; j < n; j++) {
			if (s[j][i] == '1') {
				cout << j + 1 << ' ' << i << ' ' << j + 1 << ' ' << i + 1 << '\n';
			}
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		if (s[i][0] == '1') {
			cout << i << ' ' << 1 << ' ' << i + 1 << ' ' << 1 << '\n';
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