#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	int r, c;
	for (r = 0; r < 5; ++r) {
		for (c = 0; c < 5; ++c) {
			int a; cin >> a;
			if (a != 0) break;
		}
		if (c != 5) break;
	}
	cout << (abs(r - 2) + abs(c - 2));
	return 0;
}