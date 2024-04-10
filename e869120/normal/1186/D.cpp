#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, L[100009], R[100009], B[100009]; long double A[100009];

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		scanf("%Lf", &A[i]);
		long long G = (long long)(1.0L * A[i] + 1000000.5L) - 1000000LL;
		if (fabs(1.0L * G - A[i]) <= 1e-9) {
			L[i] = G; R[i] = G;
		}
		else {
			L[i] = (long long)(1.0L * A[i] + 1000000.0L) - 1000000LL;
			R[i] = L[i] + 1LL;
		}
	}
	
	long long S = 0;
	for (int i = 0; i < N; i++) { S += L[i]; B[i] = L[i]; }
	for (int i = 0; i < N; i++) {
		if (S < 0 && L[i] < R[i]) { B[i] = R[i]; S++; }
	}

	for (int i = 0; i < N; i++) printf("%lld\n", B[i]);
	return 0;
}