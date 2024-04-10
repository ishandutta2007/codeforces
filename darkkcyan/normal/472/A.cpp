#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	if (n & 1) {
		cout << 9 << ' ' << (n - 9);
	} else {
		cout << 4 << ' ' << (n - 4);
	}
	return 0;
}