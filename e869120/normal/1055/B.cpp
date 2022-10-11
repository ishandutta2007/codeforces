#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long N, M, L, A[100009]; bool used[100009];

int main() {
	scanf("%lld%lld%lld", &N, &M, &L);
	for (int i = 1; i <= N; i++) { scanf("%lld", &A[i]); if (A[i] > L) used[i] = true; }

	int cnt = 0; for (int i = 0; i <= N; i++) { if (used[i] != used[i + 1]) cnt++; } cnt /= 2;

	for (int i = 1; i <= M; i++) {
		long long T; scanf("%lld", &T);
		if (T == 0) {
			printf("%d\n", cnt);
		}
		if (T == 1) {
			long long P, D; scanf("%lld%lld", &P, &D);
			A[P] += D;
			if (A[P] - D <= L && L < A[P]) {
				used[P] = true; cnt++;
				if (used[P - 1] == true) cnt--;
				if (used[P + 1] == true) cnt--;
			}
		}
	}
	return 0;
}