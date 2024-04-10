#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main() {
	int N; scanf("%d", &N);
	ll ans = 1;
	for(int i = 1; i <= N; i++) ans = ans * i % MOD;
	ll t = 1;
	for(int i = 1; i < N; i++) t = t * 2 % MOD;
	printf("%lld\n", (ans + MOD - t) % MOD);

	return 0;
}