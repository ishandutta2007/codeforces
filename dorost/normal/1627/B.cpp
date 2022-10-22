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
	vector <int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int mx = max({i + j, i + m - j - 1, n - i - 1 + j, n - i - 1 + m - j - 1});
			v.push_back(mx);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n * m; i++) {
		cout << v[i] << ' ';
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