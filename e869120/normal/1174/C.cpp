#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int N, A[100009], cnts;

int main() {
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		if (A[i] >= 1) continue;
		cnts++;
		for (int j = i; j <= N; j += i) A[j] = cnts;
	}
	for (int i = 2; i <= N; i++) { if (i >= 3) printf(" "); printf("%d", A[i]); } printf("\n");
	return 0;
}