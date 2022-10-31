#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 1; i <= 4; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int pay1 = min(a, b);
		int pay2 = min(c, d);
		if (pay1 + pay2 <= n) {
			pay1 += n - pay2 - pay1;
			cout << i << " " << pay1 << " " << pay2 << "\n";
			return 0;
		}
	}
	cout << "-1\n";

	return 0;
}