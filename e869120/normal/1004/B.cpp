#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long N, M, L[100009], R[100009];

int main() {
	scanf("%lld%lld", &N, &M);
	for (int i = 0; i < M; i++) scanf("%lld%lld", &L[i], &R[i]);
	for (int i = 0; i < N; i++) printf("%d", i % 2);
	printf("\n");
	return 0;
}