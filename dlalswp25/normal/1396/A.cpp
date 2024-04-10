#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll A[101010];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	if(N == 1) {
		printf("1 1\n");
		printf("%lld\n", -A[1]);
		puts("1 1");
		puts("0");
		puts("1 1");
		puts("0");
		return 0;
	}

	printf("%d %d\n", 1, N);
	for(int i = 1; i < N; i++) {
		ll r = (A[i] + (ll)(N - 1) * 1000000000LL) % (N - 1);
		printf("%lld ", N * (N - 1 - r));
		A[i] += N * (N - 1 - r);
	}
	printf("0\n");

	printf("%d %d\n", N, N);
	printf("%lld\n", -A[N]);
	printf("%d %d\n", 1, N - 1);
	for(int i = 1; i < N; i++) printf("%lld ", -A[i]); puts("");
	return 0;
}