#include <iostream>
#include <map>
using namespace std;
#pragma warning (disable: 4996)

long long N, M, A[1 << 18], B[1 << 18], C[1 << 18], D[1 << 18], sum = 0;
map<long long, long long> Map;

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld%lld", &A[i], &B[i]);
		if (Map[A[i]] < B[i]) { sum += B[i] - Map[A[i]]; Map[A[i]] = B[i]; }
	}
	scanf("%lld", &M);
	for (int i = 0; i < M; i++) {
		scanf("%lld%lld", &C[i], &D[i]);
		if (Map[C[i]] < D[i]) { sum += D[i] - Map[C[i]]; Map[C[i]] = D[i]; }
	}
	printf("%lld\n", sum);
	return 0;
}