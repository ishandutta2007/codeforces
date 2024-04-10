#include <iostream>

using namespace std;

int main (void) {
	long n;
	cin >> n;
	if (n % 2 == 1) {
		cout << 0;
		return 0;
	}

	long result = (n / 2 - 1) / 2;
	cout << result;

	return 0;
}