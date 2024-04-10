#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int N;
int A[1 << 20];

int main() {
	scanf("%d", &N);
	if (N % 2 == 0) {
		printf("NO\n");
	}
	else {
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) { A[i] = i * 2 + 1; A[i + N] = i * 2 + 2; }
			if (i % 2 == 1) { A[i] = i * 2 + 2; A[i + N] = i * 2 + 1; }
		}
		printf("YES\n");
		for (int i = 0; i < 2 * N; i++) {
			if (i) printf(" ");
			printf("%d", A[i]);
		}
		printf("\n");
	}
	return 0;
}