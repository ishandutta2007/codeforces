#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 19], Last[1 << 19], V[1 << 19];
long long Q, T[1 << 19], E1[1 << 19], E2[1 << 19];

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);

	scanf("%lld", &Q);
	for (int i = 1; i <= Q; i++) {
		scanf("%lld", &T[i]);
		if (T[i] == 1) {
			scanf("%lld%lld", &E1[i], &E2[i]);
			A[E1[i]] = E2[i];
			Last[E1[i]] = i;
		}
		if (T[i] == 2) {
			scanf("%lld", &E1[i]);
			V[i] = E1[i];
		}
	}
	for (int i = Q; i >= 0; i--) V[i] = max(V[i], V[i + 1]);

	for (int i = 1; i <= N; i++) {
		if (i >= 2) printf(" ");
		printf("%lld", max(A[i], V[Last[i]]));
	}
	printf("\n");
	return 0;
}