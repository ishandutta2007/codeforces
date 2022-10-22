/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N][5], b[5][N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) 
			a[i][j] = 0;
		string s;
		cin >> s;
		for (auto c : s) {
			a[i][c - 'a']++;
		}
		for (int j = 0; j < 5; j++) {
			b[j][i] = a[i][j] * 2 - (int)s.size();
		}
	}
	int mx = 0;
	for (int j = 0; j < 5; j++) {
		int x = 0;
		sort(b[j], b[j] + n, greater<int>());
		for (int i = 0; i < n; i++) {
			x += b[j][i];
			if (x <= 0) {
				x = i;
				break;
			} else if (i == n - 1) {
				x = n;
			}
		}
		mx = max(mx, x);
	}
	cout << mx << '\n';
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