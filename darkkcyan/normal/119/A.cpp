#include <iostream>
#include <algorithm>
using namespace std;

#define gcd __gcd

int main() {
	int n, s[2];
	cin >> s[0] >> s[1] >> n;
	bool p = 0;
	while (n > 0) {
		n -= gcd(s[p], n);
		p ^= 1;
	}
	cout << !p;
	return 0;
}