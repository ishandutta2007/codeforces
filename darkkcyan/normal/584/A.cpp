#include <iostream>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	if (n == 1 and t == 10) return cout << -1, 0;
	cout << t;
	for (int i = (t == 10) ? 2 : 1; i < n; ++i) {
		cout << 0;
	}
	return 0;
}