#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll MOD;

ll D[404][404];
ll ncr[404][404];
ll E[404];

int main() {
	scanf("%d%lld", &N, &MOD);
	for(int i = 0; i <= 400; i++) ncr[i][0] = 1;
	for(int i = 1; i <= 400; i++) {
		for(int j = 1; j <= i; j++) {
			ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
		}
	}

	E[1] = 1;
	for(int i = 2; i <= 400; i++) {
		E[i] = E[i - 1] * 2 % MOD;
	}

	D[1][1] = 1;
	D[2][2] = 2;

	for(int i = 3; i <= N; i++) {
		for(int j = 1; j < i; j++) {
			for(int k = 1; k <= j; k++) {
				D[i][j] = (D[i][j] + D[i - k - 1][j - k] * E[k] % MOD * ncr[j][k]) % MOD;
			}
		}
		D[i][i] = E[i];
	}

	ll ans = 0;
	for(int i = 1; i <= N; i++) ans = (ans + D[N][i]) % MOD;
	printf("%lld\n", ans);

	return 0;
}