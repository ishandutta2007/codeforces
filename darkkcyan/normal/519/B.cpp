#include <iostream>
using namespace std;

int main() {
	int n;
	int x1, x2, x3;
	x1 = x2 = x3 = 0;
	cin >> n;
	for (int a, i = 0; i < n; ++i) cin >> a, x1 ^= a;
	for (int a, i = 0; i < n - 1; ++i) cin >> a, x2 ^= a;
	for (int a, i = 0; i < n - 2; ++i) cin >> a, x3 ^= a;
	cout << (x1 ^ x2) << '\n' << (x2 ^ x3);
	return 0;
}