/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012345;
int ps[N];
int dp[N];
bool b[N];
bool g[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n * m; i++)
		g[i] = 0;
	int cnt = 0;
	ps[0] = 0;
	for (int i = 0; i < n * m; i++) {
		char c;
		cin >> c;
		b[i + 1] = (c - '0');
		if (c == '0') {
			ps[i + 1] = ps[i];
		} else {
			ps[i + 1] = ps[i] + 1;
		}
	}
	bool o = 0;
	for (int i = 1; i <= m; i++) {
		o |= b[i];
		dp[i] = o;
	}
	for (int i = m + 1; i <= n * m; i++) {
		dp[i] = dp[i - m] + (ps[i] != ps[i - m]);
	}
	for (int i = 1; i <= n * m; i++) {
		if (b[i]) {
			if (!g[i % m])
				cnt++;
			g[i % m] = true;
		}
		cout << dp[i] + cnt << ' '; 
	}
	cout << '\n';
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