#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int M;
char A[20][20];
ll D[17171][15][70];
int cnt[17171];

ll ans[17171];

ll sum[17171][70][15][2];
int tmp[70];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%s", A[i]);
	}
	M = (N + 1) / 2;

	for(int i = 1; i < 16384; i++) {
		int t = i&-i;
		cnt[i] = cnt[i ^ t] + 1;
	}

	for(int i = 0; i < N; i++) D[1 << i][i][0] = 1;

	for(int i = 1; i < M; i++) {
		for(int j = 0; j < (1 << N); j++) {
			if(cnt[j] != i) continue;
			for(int k = 0; k < N; k++) {
				if(!(j & (1 << k))) continue;
				for(int l = 0; l < (1 << i - 1); l++) {
					for(int m = 0; m < N; m++) {
						if(j & (1 << m)) continue;
						int t = (A[k][m] == '1');
						D[j | (1 << m)][m][l << 1 | t] += D[j][k][l];
					}
				}
			}
		}
	}

	// for(int i = 0; i < (1 << N); i++) {
	// 	for(int j = 0; j < N; j++) {
	// 		for(int k = 0; k < (1 << (M - 1)); k++) {
	// 			if(D[i][j][k] == 0) continue;
	// 			printf("%d %d %d %d\n", i, j, k, D[i][j][k]);
	// 		}
	// 	}
	// }

	for(int i = 0; i < (1 << N); i++) {
		if(cnt[i] != N - M) continue;
		for(int j = 0; j < N; j++) {
			if(!(i & (1 << j))) continue;
			for(int k = 0; k < (1 << (N - M - 1)); k++) {
				for(int l = 0; l < N; l++) {
					if(i & (1 << l)) continue;
					if(A[j][l] == '1') sum[i][k][l][1] += D[i][j][k];
					else sum[i][k][l][0] += D[i][j][k];
				}
			}
		}
	}

	// for(int i = 0; i < (1 << N); i++) {
	// 	for(int k = 0; k < (1 << N - M - 1); k++) {
	// 		for(int l = 0; l < N; l++) {
	// 			int a = sum[i][k][l][0], b = sum[i][k][l][1];
	// 			if(a == 0 && b == 0) continue;
	// 			printf("%d %d %d / %d %d\n", i, k, l, sum[i][k][l][0], sum[i][k][l][1]);
	// 		}
	// 	}
	// }

	int X = (1 << (M - 1)) - 1;
	// printf("x %d\n", X);

	for(int i = 0; i <= X; i++) {
		for(int j = 0; j < (M - 1); j++) {
			if(i & (1 << j)) {
				tmp[i] += (1 << (M - 2 - j));
			}
		}
	}

	// for(int i = 0; i < 64; i++) printf("%d ", tmp[i]); return 0;

	for(int i = 0; i < (1 << N); i++) {
		if(cnt[i] != M) continue;
		int t = ((1 << N) - 1) ^ i;
		for(int j = 0; j < N; j++) {
			if(!(i & (1 << j))) continue;
			for(int k = 0; k < (1 << (M - 1)); k++) {
				for(int l = 0; l < (1 << (N - M - 1)); l++) {
					int u = tmp[k];
					// printf("%d %d %d %d - %d %d\n", i, j, k, l, k | (u << M), k | (1 << (M - 1)) | (u << M));
					ans[u | (1 << (M - 1)) | (l << M)] += D[i][j][k] * sum[t][l][j][1];
					ans[u | (l << M)] += D[i][j][k] * sum[t][l][j][0];
				}
			}
		}
	}

	for(int i = 0; i < (1 << (N - 1)); i++) printf("%lld ", ans[i]); puts("");

	return 0;
}