#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n + 1];
	a[0] = 1;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	partial_sum(a, a + (n + 1), a);
	int m; cin >> m;
	for (int i = 0; i < m; ++i) {
		int t; cin >> t;
		cout << (upper_bound(a, a + n + 1, t) - a) << '\n';
	}
	return 0;
}