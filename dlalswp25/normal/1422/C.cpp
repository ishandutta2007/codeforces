#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N;
char A[101010];
ll B[101010];
ll C[101010];
ll P[101010];

int main() {
	scanf("%s", A + 1);
	N = strlen(A + 1);

	P[0] = 1;
	for(int i = 1; i <= N; i++) P[i] = P[i - 1] * 10 % MOD;

	C[1] = 1;
	for(int i = 2; i <= N; i++) {
		C[i] = (C[i - 1] * 10 + i) % MOD;
	}

	B[0] = 1;
	for(int i = 1; i <= N; i++) B[i] = (B[i - 1] + P[i]) % MOD;

	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		ll t = ((ll)i * (i - 1) / 2) % MOD;
		int k = N - i;
		ans = (ans + t * (A[i] - '0') * P[k]) % MOD;
		if(k) ans = (ans + (A[i] - '0') * (P[k] + k * B[k - 1] % MOD + MOD - C[k - 1]) % MOD);
		if(k) ans = (ans + MOD - (A[i] - '0') * P[k] % MOD) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}