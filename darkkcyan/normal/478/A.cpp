#include <iostream>
using namespace std;

int main() {
	int s = 0;
	for (int a, i = 0; i < 5; ++i) { cin >> a; s += a; }
	cout << (s % 5 or !s ? -1 : s / 5);
	return 0;
}