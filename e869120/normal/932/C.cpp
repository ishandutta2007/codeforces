#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int N, A, B, C[1000009];

int main() {
	cin >> N >> A >> B;
	for (int i = 0; i*A <= N; i++) {
		if ((N - i * A) % B != 0) continue;
		for (int j = 0; j < i; j++) {
			int cl = j * A;
			for (int k = 0; k < A; k++) C[cl + k] = cl + ((k + 1) % A);
		}
		int e = (N - i * A) / B;
		for (int j = 0; j < e; j++) {
			int cl = i * A + j * B;
			for (int k = 0; k < B; k++) C[cl + k] = cl + ((k + 1) % B);
		}
		for (int j = 0; j < N; j++) {
			if (j) printf(" ");
			printf("%d", C[j] + 1);
		}
		printf("\n");
		return 0;
	}
	printf("-1\n");
	return 0;
}