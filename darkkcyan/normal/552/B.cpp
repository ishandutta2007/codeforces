#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	long long ans = 0;
	long long  i, f;
	for (i = 10, f = 1; i <= n; i *= 10, ++f) {
		ans += (i - i / 10) * f;
	}
	i /= 10;
	ans += (n - i + 1) * f;
	cout << ans;
	return 0;
}