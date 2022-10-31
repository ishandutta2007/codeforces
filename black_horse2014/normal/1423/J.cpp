#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;
int dp[61][8];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		long long m;
		cin >> m;
		m >>= 1;
		m += 2;
		cout << (m - m / 2) % P * ((m / 2) % P) % P << "\n";
	}
	return 0;
}