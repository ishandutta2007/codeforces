#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<long long> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	long long gcd = 0;
	for (int i = 0; i < n - 1; i++) {
		gcd = __gcd(gcd, x[i + 1] - x[i]);
	}
	for (int i = 0; i < m; i++) {
		long long p; cin >> p;
		if (gcd % p == 0) {
			cout << "YES\n";
			cout << x[0] << ' ' << i + 1 << '\n';
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}