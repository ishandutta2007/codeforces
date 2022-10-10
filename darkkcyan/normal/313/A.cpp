#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a;
	cin >> a;
	if (a > 0) return cout << a, 0;
	cout << max(a / 10, a / 100 * 10 + a % 10);
	return 0;
}