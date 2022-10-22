/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

void solve() {
	int n;
	cin >> n;
	vector <int> v[2];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v[i % 2].push_back(a[i]);
	}
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	for (int i = 0; i < n; i++) {
		a[i] = v[i % 2][i / 2];
	}
	cout << (is_sorted(a, a + n) ? "Yes" : "NO") << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}