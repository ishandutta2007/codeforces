#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += m % i == 0 and m / i <= n;
	}
	cout << ans;
	return 0;
}