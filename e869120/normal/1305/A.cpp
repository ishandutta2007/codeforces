#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#pragma warning (disable: 4996)
using namespace std;

long long T;
long long N, A[1 << 18], B[1 << 18];

void solve() {
	sort(A, A + N);
	sort(B, B + N);
	for (int i = 0; i < N; i++) { if (i) printf(" "); printf("%lld", A[i]); } printf("\n");
	for (int i = 0; i < N; i++) { if (i) printf(" "); printf("%lld", B[i]); } printf("\n");
}

int main() {
	scanf("%lld", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%lld", &N);
		for (int j = 0; j < N; j++) scanf("%lld", &A[j]);
		for (int j = 0; j < N; j++) scanf("%lld", &B[j]);
		solve();
	}
	return 0;
}