#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	for (int i = 0, d = 1, e = n / 2, s = 1; i < n; ++i, (d == n and (s = -s)), d += s * 2, e -= s) {
		for (int f = 0; f < e; ++f) cout << '*';
		for (int f = 0; f < d; ++f) cout << 'D';
		for (int f = 0; f < e; ++f) cout << '*';
		cout << '\n';
	}
	return 0;
}