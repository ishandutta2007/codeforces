#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void tc() {
	ll n, m, i, j, a, s;
	cin >> n;
	s = 0; m = 1e18;
	for (i = 0; i < n + n; i++) {
		for (j = 0; j < n + n; j++) {
			cin >> a;
			if (i >= n && j >= n) s += a;
			else if ((i == n && j == 0)
				|| (i == n && j == n - 1)
				|| (i == n + n - 1 && j == 0)
				|| (i == n + n - 1 && j == n - 1)
				|| (j == n && i == 0)
				|| (j == n && i == n - 1)
				|| (j == n + n - 1 && i == 0)
				|| (j == n + n - 1 && i == n - 1)) m = min(m, a);
		}
	}
	cout << s + m << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	
	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}