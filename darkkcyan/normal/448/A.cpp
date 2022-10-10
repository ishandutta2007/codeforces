#include <iostream>
using namespace std;

int main() {
	int a = 0, b = 0;
	for (int c, i = 0; i < 3; ++i) cin >> c, a += c;
	for (int c, i = 0; i < 3; ++i) cin >> c, b += c;
	int n; cin >> n;
	cout << (n >= (a + 4) / 5 + (b + 9) / 10 ? "YES" : "NO");
	return 0;
}