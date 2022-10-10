#include <iostream>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	int s = 0;
	for (int a, i = 0; i < n; ++i) cin >> a, s += a;
	if (s + (n - 1) * 10 > m) cout << -1;
	else cout << ((m - s) / 5);
	return 0;
}