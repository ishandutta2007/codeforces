#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 18], B[1 << 18], sum = 0;

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) { scanf("%lld", &A[i]); sum += A[i]; }
	int pos = -1; for (int i = 0; i < N; i++) { if (A[i] < A[(i + 1) % N]) pos = i; }
	if (pos == -1) {
		if (sum == 0) {
			printf("YES\n");
			for (int i = 0; i < N; i++) { if (i) printf(" "); printf("1000000007"); }
			printf("\n");
		}
		else {
			cout << "NO" << endl;
		}
		return 0;
	}

	B[pos] = A[pos] + A[(pos + 1) % N] * 1000000000LL; B[(pos + 1) % N] = A[(pos + 1) % N];
	for (int i = N - 1; i >= 2; i--) {
		int t = (pos + i) % N;
		B[t] = A[t] + B[(t + 1) % N];
	}
	
	printf("YES\n");
	for (int i = 0; i < N; i++) { if (i) printf(" "); printf("%lld", B[i]); }
	printf("\n");
	return 0;
}