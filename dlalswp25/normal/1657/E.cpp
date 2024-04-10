#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int MX = 250;

int N, K;
ll D[252][252];
ll ncr[252][252];
ll pw[252][62626];

int main() {
	for(int i = 0; i <= MX; i++) ncr[i][0] = 1;
	for(int i = 1; i <= MX; i++) {
		for(int j = 1; j <= i; j++) ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
	}
	for(int i = 1; i <= MX; i++) {
		pw[i][0] = 1;
		for(int j = 1; j <= MX * MX; j++) pw[i][j] = pw[i][j - 1] * i % MOD;
	}

	scanf("%d%d", &N, &K);
	D[0][0] = 1;
	for(int i = 1; i <= K; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k <= j; k++) {
				ll e = j * (j - 1) / 2 - k * (k - 1) / 2;
				D[i][j] = (D[i][j] + ncr[j][k] * D[i - 1][k] % MOD * pw[K - i + 1][e]) % MOD;
			}
		}
	}
	printf("%lld\n", D[K][N - 1]);
	return 0;
}