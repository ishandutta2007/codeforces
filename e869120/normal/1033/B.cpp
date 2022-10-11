#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

bool prime(long long x) {
	for (long long i = 2; i*i <= x; i++) {
		if (x%i == 0) return false;
	}
	return true;
}

bool check(long long a, long long b) {
	if (a - b == 1LL) return prime(2LL * a - 1LL);
	return false;
}

int main() {
	long long Q, A, B; scanf("%lld", &Q);
	for (int i = 1; i <= Q; i++) {
		scanf("%lld%lld", &A, &B);
		bool I = check(A, B);
		if (I == true) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}