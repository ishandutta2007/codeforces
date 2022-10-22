/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			string s;
			for (int o = i; o <= j; o++) {
				s += a[o];
			}
			for (int k = 0; k < m; k++) {
				for (int l = k; l < m; l++) {
					string t;
					for (int o = k; o <= l; o++) {
						t += b[o];
					}
					if (t == s) {
						mx = max(mx, (int)t.size());
					}
				}
			}
		}
	}
	cout << n + m - (mx * 2) << ' ';
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