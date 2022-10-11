#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int N, Q, A[1 << 19], B[1 << 19], cl, cr;
int EA[1 << 19], EB[1 << 19];

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++) { scanf("%d", &A[i]); }
	cl = 1; cr = 1;
	for (int i = 1; i <= N; i++) { B[cr] = A[i]; cr++; }

	for (int i = 1; i <= N * 2; i++) {
		EA[i] = B[cl]; EB[i] = B[cl + 1];
		if (B[cl] >= B[cl + 1]) {
			B[cr] = B[cl + 1]; cr++;
			B[cl + 1] = B[cl];
			B[cl] = 0; cl++;
		}
		else {
			B[cr] = B[cl]; cr++;
			B[cl] = 0; cl++;
		}
	}

	for (int i = 1; i <= Q; i++) {
		long long E; scanf("%lld", &E);
		if (E > 1LL * N) {
			long long F = (E - 1LL * N) / (N - 1LL);
			E -= F * (N - 1LL);
		}
		printf("%d %d\n", EA[E], EB[E]);
	}
	return 0;
}