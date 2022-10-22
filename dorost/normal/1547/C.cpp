/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 103;
int a[N], b[N];

void solve() {
	int k, n, m;
	cin >> k >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	a[n] = INT_MAX;
	b[m] = INT_MAX;
	int it1 = 0, it2 = 0;
	vector <int> v;
	for (int i = 0; i < n + m; i++) {
		if (a[it1] < b[it2]) {
			v.push_back(a[it1]);
			it1++;
		} else {
			v.push_back(b[it2]);
			it2++;
		}
	}
	for (auto x : v) {
		if (x > k) {
			cout << -1 << '\n';
			return;
		} else if (x == 0) {
			k++;
		}
	}
	for (auto x : v) {
		cout << x << ' ';
	}
	cout << '\n';
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