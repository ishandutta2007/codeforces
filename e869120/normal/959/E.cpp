#include <iostream>
using namespace std;

long long n, sum, t = 1;

int main() {
	cin >> n;
	while (n >= 2) {
		sum += (n / 2)*t;
		n -= n / 2;
		t *= 2;
	}
	cout << sum << endl;
	return 0;
}