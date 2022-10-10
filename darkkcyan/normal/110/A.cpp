#include <iostream>
using namespace std;

int main() {
	long long a;
	cin >> a;
	int lc = 0;
	while (a) {
		if (a % 10 ==  4 or a % 10 == 7) ++lc;
		a /=10;
	}
	if (lc == 0) return cout << "NO", 0;
	while (lc) {
		if (lc % 10 != 4 and lc % 10 != 7) return cout << "NO", 0;
		lc /= 10;
	}
	cout << "YES";
	return 0;
}