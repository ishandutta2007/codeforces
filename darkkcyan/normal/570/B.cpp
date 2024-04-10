#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	if (n == 1) return cout << 1, 0;
	if (n & 1 and (n + 1) / 2 == m) return cout << (m - 1), 0;
	if (m <= n / 2) cout << (m + 1);
	else cout << (m - 1);
	return 0;
}