#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long N, lx[1 << 18], ly[1 << 18], rx[1 << 18], ry[1 << 18];

int main() {
	scanf("%lld", &N);
	printf("YES\n");
	for (int i = 0; i < N; i++) {
		scanf("%lld%lld%lld%lld", &lx[i], &ly[i], &rx[i], &ry[i]);
		lx[i] += (1LL << 30); ly[i] += (1LL << 30);
		long long E1 = lx[i] % 2;
		long long E2 = ly[i] % 2;
		printf("%lld\n", E1 * 2LL + E2 + 1LL);
	}
	return 0;
}