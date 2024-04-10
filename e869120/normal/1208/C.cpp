#include <iostream>
using namespace std;

int N, A[2009][2009], cnt;

int main() {
	cin >> N;
	for (int i = 0; i < N / 4; i++) {
		for (int j = 0; j < N / 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					A[i * 4 + k][j * 4 + l] = cnt;
					cnt++;
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int rem = 0;
		for (int j = 0; j < N; j++) {
			if (j) printf(" ");
			printf("%d", A[i][j]); rem ^= A[i][j];
		}
		sum += rem;
		printf("\n");
	}
	return 0;
}