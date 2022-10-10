#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	long long ans = 0;
	for (int a = 0; a <= 1010; ++a) {
		for (int b = 0; b <= 1010; ++b) {
			ans += (a * a + b == n and b * b + a == m);
		}
	}
	cout << ans;
	return 0;
}