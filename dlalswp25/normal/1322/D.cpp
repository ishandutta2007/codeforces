#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int D[2020][2020];
int N, M;

int L[2020];
int S[2020];
int C[4040];

int A[2020][2020];
int mx[2020];

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", &L[i]);
	for(int i = 1; i <= N; i++) scanf("%d", &S[i]);
	for(int i = 1; i <= N + M; i++) scanf("%d", &C[i]);

	reverse(L + 1, L + N + 1);
	reverse(S + 1, S + N + 1);

	for(int i = 1; i <= M; i++) {
		for(int j = 0; j <= N; j++) {
			int b = 1;
			for(int k = 0; k < 11; k++) {
				if(b == 1 && (j & (1 << k))) {
					A[i][j] += C[i + k + 1];
				}
				else b = 0;
			}
		}
	}

	for(int i = 1; i <= M + 15; i++) for(int j = 0; j <= N; j++) D[i][j] = -1010101010;

	D[0][0] = 0;
	for(int i = 1; i <= M; i++) mx[i] = -1010101010;

	// for(int i = 1; i <= M; i++) {
	// 	for(int j = 0; j <= N; j++) {
	// 		printf("%d ", A[i][j]);
	// 	}
	// 	puts("");
	// }

	for(int i = 1; i <= N; i++) {
		int cost = C[L[i]] - S[i];
		int m = L[i];

		for(int j = i; j > 1; j--) {
			for(int k = m; k > 0; k--) {
				int s = (j - 1) * (1 << m - k);
				if(s > N) break;
				for(int l = 0; l < (1 << m - k); l++) {
					if(s + l > N) break;
					D[L[i]][j] = max(D[L[i]][j], D[k][s + l] + cost + A[L[i]][j - 1]);
				}
			}
			mx[L[i]] = max(mx[L[i]], D[L[i]][j]);
		}

		for(int k = L[i]; k > 0; k--) {
			if(m - k >= 11) {
				D[L[i]][1] = max(D[L[i]][1], mx[k] + cost);
			}
			else {
				for(int l = 0; l < (1 << m - k); l++) {
					if(l > N) break;
					D[L[i]][1] = max(D[L[i]][1], D[k][l] + cost);
				}
			}
		}

		D[L[i]][1] = max(D[L[i]][1], C[L[i]] - S[i]);
		mx[L[i]] = max(mx[L[i]], D[L[i]][1]);

		// printf("****%d****\n", i);
		// for(int j = 1; j <= M + 2; j++) {
		// 	for(int k = 1; k <= N; k++) {
		// 		printf("%d ", D[j][k]);
		// 	}
		// 	puts("");
		// }
	}

	int ans = 0;
	for(int i = 0; i <= M + 15; i++) {
		for(int j = 0; j <= N; j++) {
			ans = max(ans, D[i][j]);
		}
	}

	printf("%d\n", ans);

	return 0;
}