#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long a, b, c; cin >> a >> b >> c; c -= abs(a) + abs(b);
	cout << (c < 0 or c & 1 ? "No" : "Yes");
	return 0;
}