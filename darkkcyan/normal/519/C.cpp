#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long m, n; cin >> m >> n;
	m = min(m, 2 * n);
	n = min(n, 2 * m);
	long long ans = (m + n) / 3;
	cout << ans;
	return 0;
}