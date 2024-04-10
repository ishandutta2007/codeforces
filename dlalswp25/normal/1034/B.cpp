#include <bits/stdc++.h>

using namespace std;

int X[6] = {0, 1, 2, 3, 2, 1};

int main() {
	long long N, M; scanf("%lld%lld", &N, &M);
	if(N > M) swap(N, M);
	if(M <= 2) { puts("0"); return 0; }
	if(N == 1) {
		printf("%lld\n", M - X[M % 6]);
		return 0;
	}
	if(N == 2) {
		if(M % 2 == 0) { printf("%lld\n", N * M); return 0; }
		if(M == 3) { puts("4"); return 0; }
		if(M == 7) { puts("12"); return 0; }
		printf("%lld\n", N * M);
		return 0;
	}
	if(N % 2 == 0 || M % 2 == 0) { printf("%lld\n", N * M); return 0; }
	printf("%lld\n", N * M - 1);
	return 0;
}