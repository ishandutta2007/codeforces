#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1LL << 61;

int N, M;
ll A[105][105];
ll B[105][105];
ll D[105][105];
ll E[105][105];

void dp1(int x, int y) {
	if(B[1][1] > A[1][1]) { D[x][y] = INF; return; }
	D[1][1] = A[1][1] - B[1][1];

	for(int i = 1; i <= x; i++) {
		for(int j = 1; j <= y; j++) {
			if(i + j == 2) continue;

			if(A[i][j] < B[i][j]) { D[i][j] = INF; continue; }
			if(D[i - 1][j] == INF && D[i][j - 1] == INF) { D[i][j] = INF; continue; }

			ll C = A[i][j] - B[i][j];
			D[i][j] = min(D[i - 1][j], D[i][j - 1]) + C;
		}
	}
}

void dp2(int x, int y) {
	if(B[N][M] > A[N][M]) { E[x][y] = INF; return; }
	E[N][M] = A[N][M] - B[N][M];

	for(int i = N; i >= x; i--) {
		for(int j = M; j >= y; j--) {
			if(i + j == N + M) continue;

			if(A[i][j] < B[i][j]) { E[i][j] = INF; continue; }
			if(E[i + 1][j] == INF && E[i][j + 1] == INF) { E[i][j] = INF; continue; }

			ll C = A[i][j] - B[i][j];
			E[i][j] = min(E[i + 1][j], E[i][j + 1]) + C;
		}
	}
}

int main() {
	int T; scanf("%d", &T);

	while(T--) {
		scanf("%d%d", &N, &M);
		for(int i = 0; i <= N + 1; i++) {
			D[i][0] = D[i][M + 1] = INF;
			E[i][0] = E[i][M + 1] = INF;
		}
		for(int i = 0; i <= M + 1; i++) {
			E[0][i] = E[N + 1][i] = INF;
			D[0][i] = D[N + 1][i] = INF;
		}

		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) scanf("%lld", &A[i][j]);

		ll ans = INF;
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) {
			for(int k = 1; k <= N; k++) for(int l = 1; l <= M; l++) {
				B[k][l] = A[i][j] - (i - k) - (j - l);
			}
			dp1(i, j);
			dp2(i, j);

			ans = min(ans, D[i][j] + E[i][j]);
		}
		printf("%lld\n", ans);
	}

	return 0;
}