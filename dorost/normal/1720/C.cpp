/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 501;
bool b[N][N];

void solve() {
	int n, m, cnt = 0;
	bool f = false;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			b[i][j] = (c - '0');
			cnt += (c - '0');
			f |= (i && !b[i][j] && !b[i - 1][j]);
			f |= (j && !b[i][j] && !b[i][j - 1]);
			f |= (i && j && !b[i][j] && !b[i - 1][j - 1]);
			f |= (i && (j != m - 1) && !b[i][j] && !b[i - 1][j + 1]);
		}
	}
	if (cnt == n * m)
		cout << cnt - 2 << '\n';
	else if (f) 
		cout << cnt << '\n';
	else
		cout << cnt - 1 << '\n';
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