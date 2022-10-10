#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	for (int i = 0, c = 2 * n - 1; i <= n; ++i, c -= 2) {
		for (int f = 1; f <= c; ++f) cout << " ";
		for (int f = 0; f <= i; ++f) {
			if (i < n or f != 0) cout << ' ';
			cout << f;
		}
		for (int f = i - 1; f >= 0; --f) cout << ' ' << f;
		cout << endl;
	}
	
	for (int i = n - 1, c = 1; i >= 0; --i, c += 2) {
		for (int f = 1; f <= c; ++f) cout << " ";
		for (int f = 0; f <= i; ++f) cout << ' ' << f;
		for (int f = i - 1; f >= 0; --f) cout << ' ' << f;
		cout << endl;
	}
	return 0;
}