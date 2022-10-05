#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, K, A, B, ans, nxt;

int main() {
	scanf("%I64d%I64d%I64d%I64d", &n, &K, &A, &B);
	if (K == 1) {
		printf("%I64d\n", (n - 1) * A);
		return 0;
	}
	while (n >= K) {
		ans += A * (n % K);
		n = n / K * K;
		ans += min(B, A * (n - n / K));
		n = n / K;
	}
	ans += A * (n - 1);
	printf("%I64d\n", ans);
	return 0;
}