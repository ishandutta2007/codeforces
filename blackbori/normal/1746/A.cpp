#include <bits/stdc++.h>

using namespace std;

void tc() {
	int n, k, i, a, s;
	cin >> n >> k;
	s = 0;
	for (i = 1; i <= n; i++) {
		cin >> a; s += a;
	}
	cout << (s > 0 ? "YES" : "NO") << "\n";
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