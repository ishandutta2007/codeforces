/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1008;
bitset <N> b[N][N];
int a[N][N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[i][j] = 0;
			cin >> a[i][j];
			if (a[i][j] == -1)
				a[i][j] = 0;
		}
	}
	if ((n + m - 1) & 1) { 
		cout << "No\n";
		return;
	}
	int h = (n + m - 1) / 2;
	b[0][0][a[0][0]] = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				if (i != 0) {
					b[i][j] |= b[i - 1][j];
				}
				if (j != 0) {
					b[i][j] |= b[i][j - 1];
				}
			} else {
				if (i != 0) {
					b[i][j] |= (b[i - 1][j] << 1);
				}
				if (j != 0) {
					b[i][j] |= (b[i][j - 1] << 1);
				}
			}
		}
	}
	cout << (b[n - 1][m - 1][h] ? "Yes" : "No") << endl;
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