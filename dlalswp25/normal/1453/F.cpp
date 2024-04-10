#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;

int N;
int A[3030];
int B[3030];
int D[3030][3030];
int E[3030][3030];
int nxt[3030][3030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) for(int j = 0; j <= N; j++) D[i][j] = E[i][j] = INF;
		for(int i = N - 1; i >= 1; i--) {
			if(!A[i]) continue;
			if(i + A[i] == N) continue;
			bool ok = false;
			for(int j = 1; j <= A[i]; j++) {
				if(A[i + j]) ok = true;
			}
			if(!ok) A[i] = 0;
		}

		for(int i = 1; i <= N; i++) B[i] = A[i];
		for(int i = 1; i <= N; i++) for(int j = 0; j <= N; j++) nxt[i][j] = 0;

		for(int i = 2; i <= N; i++) {
			if(i != N && !A[i]) continue;
			for(int j = 1; j <= i; j++) B[j] = A[j];
			int p = i - 1;
			for(int j = 0; j <= N; j++) {
				while(p >= 1) {
					if(!B[p]) { p--; continue; }
					if(B[p] + p < i) { p--; continue; }
					else break;
				}
				if(p < 1) break;
				nxt[i][j] = p;
				B[p] = 0; p--;
			}
		}

		// for(int i = 1; i <= N; i++) {
		// 	for(int j = 0; j <= N; j++) {
		// 		printf("%d ", nxt[i][j]);
		// 	}
		// 	puts("");
		// }

		for(int i = 1; i < N; i++) {
			if(!A[i]) continue;
			for(int j = 0; j <= N; j++) {
				if(!nxt[i][j]) break;
				int k = nxt[i][j];
				E[i][A[k] + k] = min(E[i][A[k] + k], D[k][i] + j);
			}
			E[i][0] = INF;
			E[1][0] = 0;
			for(int j = 1; j <= N; j++) {
				E[i][j] = min(E[i][j], E[i][j - 1]);
			}
			for(int j = i + 1; j <= i + A[i]; j++) {
				if(j != N && !A[j]) continue;
				D[i][j] = E[i][j - 1];
			}
		}

		int ans = INF;
		for(int i = 0; i <= N; i++) {
			if(!nxt[N][i]) break;
			int j = nxt[N][i];
			ans = min(ans, D[j][N] + i);
		}
		printf("%d\n", ans);
	}
	return 0;
}