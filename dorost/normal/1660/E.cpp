/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2002;
string s[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int mx = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x = 0;
		for (int j = 0; j < n; j++) {
			ans += (s[i][j] == '1');
			if (s[(i + j) % n][j] == '1')
				x++;
		}
		mx = max(mx, x);
	}
	ans -= mx;
	ans += (n - mx);
	cout << ans << '\n';
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