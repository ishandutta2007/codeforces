#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long n, q, a;

long long solve(long long x) {
	while (true) {
		if (x % 2 == 0) return x / 2 + 1;
		long long E = x / 2;
		x = n + E;
	}
}

int main() {
	cin >> n >> q;
	for (int i = 1; i <= q; i++) {
		scanf("%lld", &a); a--;
		printf("%lld\n", solve(a));
	}
	return 0;
}