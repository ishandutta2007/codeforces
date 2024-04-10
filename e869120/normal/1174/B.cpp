#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, A[100009], c1 = 0, c2 = 0;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) { scanf("%d", &A[i]); if (A[i] % 2 == 0) c1++; if (A[i] % 2 == 1) c2++; }

	if (!(c1 == 0 || c2 == 0)) sort(A, A + N);
	for (int i = 0; i < N; i++) { if (i) printf(" "); printf("%d", A[i]); } printf("\n");
	return 0;
}