/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
bool ans[30][N];
bool c[30][N];
int a[N * 2], b[N * 2], x[N * 2];
vector <int> g[30][N];

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		cin >> a[i] >> b[i] >> x[i];
		if (a[i] > b[i])
			swap(a[i], b[i]);
		a[i]--;
		b[i]--;
	}
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < n; j++)
			c[i][j] = 1, ans[i][j] = 0;
		for (int j = 0; j < q; j++) {
			if ((x[j] >> i) & 1) {
				g[i][b[j]].push_back(a[j]);
				g[i][a[j]].push_back(b[j]);
			} else {
				c[i][a[j]] = 0;
				c[i][b[j]] = 0;
			}
		}
		for (int j = 0; j < n; j++) {
			if (c[i][j] == false) {
				ans[i][j] = false;
				continue;
			}
			bool f = true;
			for (int k : g[i][j]) {
				if (k <= j && !ans[i][k])
					f = false;
				if (k > j && c[i][k] == false)
					f = false;
			}
			if (f) 
				ans[i][j] = false;
			else
				ans[i][j] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		int a = 0;
		for (int j = 0; j < 30; j++)
			a += (ans[j][i] * (1 << j));
		cout << a << ' ';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}