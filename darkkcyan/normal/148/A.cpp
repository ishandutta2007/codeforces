#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, n;
	cin >> a >> b >> c >> d >> n;
	int ans = 0;
	for (int i = 1; i <= n; ++i) 
		ans += !(i % a and i % b and i % c and i % d and i % d);
	cout << ans;
	return 0;
}