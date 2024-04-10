#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int b = 0;
		for (int i = 9; i; i--)
			if (n >= i) {
				b ^= 1 << i;
				n -= i;
			}
		for (int i = 1; i < 10; i++)
			if (b & 1 << i)
				cout << i;
		cout << '\n';
	}
	return 0;
}