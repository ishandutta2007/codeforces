#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	if (n & 1) cout << '-';
	cout << (n + 1) / 2;
	return 0;
}