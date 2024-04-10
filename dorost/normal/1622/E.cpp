/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 11, M = 10123;
int x[N], r[N], c[M], p[M];
pair <int, int> d[M];
string s[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	int ma = 1 << n;
	int mx = -1, in = -1;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < ma; i++) {
		for (int j = 0; j < m; j++)
			c[j] = 0;
		for (int j = 0; j < n; j++)
			r[j] = 0;
		int y = i;
		for (int j = 0; j < n; j++) {
			if (y % 2) {
				for (int k = 0; k < m; k++) {
					if (s[j][k] == '1')
						c[k]++;
				}
			} else {
				for (int k = 0; k < m; k++) {
					if (s[j][k] == '1')
						c[k]--;
				}
			}
			y /= 2;
		}
		for (int j = 0; j < m; j++) {
			d[j].F = c[j];
			d[j].S = j;
		}
		sort(d, d + m);
		for (int j = 0; j < m; j++) {
			p[d[j].S] = m - j;
		}
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (s[j][k] == '1') {
					r[j] += p[k];
				}
			}
		}
		int ans = 0;
		for (int j = 0; j < n; j++) {
			ans += abs(r[j] - x[j]);
		}
		if (ans > mx) {
			in = i;
			mx = ans;
		}
	}
	for (int i = in; i <= in; i++) {
		for (int j = 0; j < m; j++)
			c[j] = 0;
		for (int j = 0; j < n; j++)
			r[j] = 0;
		int y = i;
		for (int j = 0; j < n; j++) {
			if (y % 2) {
				for (int k = 0; k < m; k++) {
					if (s[j][k] == '1')
						c[k]++;
				}
			} else {
				for (int k = 0; k < m; k++) {
					if (s[j][k] == '1')
						c[k]--;
				}
			}
			y /= 2;
		}
		for (int j = 0; j < m; j++) {
			d[j].F = c[j];
			d[j].S = j;
		}
		sort(d, d + m);
		for (int j = 0; j < m; j++) {
			p[d[j].S] = m - j;
		}
		for (int j = 0; j < m; j++) {
			cout << p[j] << ' ';
		}
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