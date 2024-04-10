#include <bits/stdc++.h>

using namespace std;

const int INF = 20202;

int N, M;
short D[5050][5050];
short U[5050][5050];
short C[5050][5050];
char A[5050];
char B[5050];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 0; i <= N + 1; i++) for(int j = 0; j <= M + 1; j++) D[i][j] = U[i][j] = INF;
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) C[i][j] = 0;
		scanf("%s", A + 1);
		scanf("%s", B + 1);
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(A[i] == B[j]) C[i][j] = C[i - 1][j - 1] + 1;
				else C[i][j] = 0;
			}
		}

		U[N + 1][M + 1] = 0;
		for(int i = N; i >= 1; i--) {
			for(int j = M + 1; j >= 1; j--) {
				if(A[i] == B[j]) U[i][j] = min((int)U[i][j], U[i + 1][j + 1] + 1);
				U[i][j] = min((int)U[i][j], U[i + 1][j] + 1);
			}
		}
		D[0][0] = 0;
		for(int i = 1; i <= N; i++) {
			for(int j = 0; j <= M; j++) {
				if(A[i] == B[j]) D[i][j] = min((int)D[i][j], D[i - 1][j - 1] + 1);
				D[i][j] = min((int)D[i][j], D[i - 1][j] + 2);
			}
		}
		int ans = INF;
		for(int i = 0; i <= N; i++) {
			for(int j = 0; j <= M; j++) {
				int ni = i - C[i][j], nj = j - C[i][j];
				// printf("%d %d: %d %d / u%d d%d\n", i, j, ni, nj, U[i + 1][j + 1], D[ni][nj]);
				if(!ni && !nj) ans = min(ans, (int)U[i + 1][j + 1]);
				else ans = min(ans, U[i + 1][j + 1] + 1 + D[ni][nj]);
			}
		}
		printf("%d\n", ans == INF ? -1 : ans);
	}
	return 0;
}