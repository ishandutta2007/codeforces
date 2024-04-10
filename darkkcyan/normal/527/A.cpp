#include <iostream>
using namespace std;

int main() {
	#define long long long
	long a, b;
	cin >> a >> b;
	long ans = 0;
	if (a < b) swap(a, b);
	while (a != b and b != 0) {
		ans += a / b;
		a %= b;
		swap(a, b);
	}
	cout << ans;
	return 0;
}