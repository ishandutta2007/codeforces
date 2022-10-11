#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long n, q;

int main() {
	cin >> q;
	for (int i = 1; i <= q; i++) {
		scanf("%lld", &n);
		long long s = -1;
		if (n % 4 == 0) {
			s = (n - 0) / 4;
			if (n <= 3) s = -1;
		}
		if (n % 4 == 1) {
			s = (n - 5) / 4;
			if (n <= 8) s = -1;
		}
		if (n % 4 == 2) {
			s = (n - 2) / 4;
			if (n <= 5) s = -1;
		}
		if (n % 4 == 3) {
			s = (n - 7) / 4;
			if (n <= 14) s = -1;
		}
		printf("%lld\n", s);
	}
	return 0;
}