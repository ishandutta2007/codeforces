#include <iostream>
#include <algorithm>

using namespace std;

int ab(int n) {
	return (n < 0) ? -n : n;
}

int main() {
	ios::sync_with_stdio(0);

	int n, x;
	cin >> n >> x;
	int low = -50, high = 1050;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		low = max(low, min(a, b));
		high = min(high, max(a, b));
	}
	if (high < low)
		cout << "-1\n";
	else if (x >= low && x <= high)
		cout << "0\n";
	else
		cout << min(ab(x - low), ab(x - high)) << "\n";

	return 0;
}