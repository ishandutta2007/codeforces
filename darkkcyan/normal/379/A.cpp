#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int ans = 0, t = 0;
	while (a) {
		ans += a;
		t += a;
		a = t / b;
		t %= b;
	}
	cout << ans;
	return 0;
}