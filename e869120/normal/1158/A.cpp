#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, M, A[100009], B[100009], M1 = -(1LL << 30), M2 = (1LL << 30);

int main() {
	scanf("%lld%lld", &N, &M);
	for (int i = 0; i < N; i++) { scanf("%lld", &A[i]); M1 = max(M1, A[i]); }
	for (int i = 0; i < M; i++) { scanf("%lld", &B[i]); M2 = min(M2, B[i]); }
	sort(A, A + N);
	sort(B, B + M);

	if (M1 > M2) {
		cout << "-1" << endl;
		return 0;
	}

	long long V = 0; for (int i = 0; i < N; i++) V += A[i]; V *= M;
	for (int i = 1; i < M; i++) V += (B[i] - A[N - 1]);
	if (M1 == M2) V += (B[0] - A[N - 1]);
	else V += (B[0] - A[N - 2]);
	cout << V << endl;
	return 0;
}