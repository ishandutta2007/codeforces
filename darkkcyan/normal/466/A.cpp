#include <iostream>
using namespace std;

int main() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int ans = (n / m + (n % m > 0)) * b;
	for (int i = 0; i <= n; i += m) {
		ans = min(ans, i * b / m + (n - i) * a);
		// cout << i << ' ' << (i * b / m + (n - i) * a) << endl;
	}
	cout << ans;
	return 0;
}