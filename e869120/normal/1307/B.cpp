#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long T;
long long N, X, A[1 << 18];

long long solve() {
	long long maxn = 0;
	for (int i = 1; i <= N; i++) {
		if (A[i] == X) return 1;
		maxn = max(maxn, A[i]);
	}
	return max(2LL, (X + maxn - 1LL) / maxn);
}

int main() {
	scanf("%lld", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%lld%lld", &N, &X);
		for (int j = 1; j <= N; j++) scanf("%lld", &A[j]);
		printf("%lld\n", solve());
	}
	return 0;
}