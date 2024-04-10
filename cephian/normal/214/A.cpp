#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	int pairs = 0;
	for (int a = 0;; ++a) {
		if (a * a > n || a > m)
			break;
		for (int b = 0;; ++b) {
			if (a * a + b == n && a + b * b == m) {
				++pairs;
			} else if (a * a + b > n || a + b * b > m)
				break;
		}
	}
	cout << pairs << "\n";
	return 0;
}