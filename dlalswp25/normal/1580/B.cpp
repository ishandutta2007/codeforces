#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M, K, MOD;
ll D[105][105][105];
ll F[105];
ll ncr[105][105];

int main() {
	scanf("%d%d%d%d", &N, &M, &K, &MOD);
	if(K > (N + 1) / 2 || M + K - 1 > N) { puts("0"); return 0; }

	for(int i = 0; i <= N; i++) ncr[i][0] = ncr[i][i] = 1;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= i; j++) ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % MOD;
	F[0] = 1;
	for(int i = 1; i <= N; i++) F[i] = F[i - 1] * i % MOD;

	for(int i = 0; i <= N; i++) D[M + 1][i][0] = F[i];

	for(int i = M; i >= 1; i--) {
		for(int j = 0; j <= N; j++) {
			for(int k = 0; k <= K; k++) {
				if(k > (j + 1) / 2) break;
				if(!j) { D[i][j][k] = (j == k) % MOD; continue; }
				for(int l = 0; l < j; l++) {
					for(int m = 0; m <= k - (i == M); m++) {
						D[i][j][k] = (D[i][j][k] + D[i + 1][l][m] * D[i + 1][j - l - 1][k - (i == M) - m] % MOD * ncr[j - 1][l]) % MOD;
					}
				}
			}
		}
	}

	printf("%lld\n", D[1][N][K]);

	return 0;
}