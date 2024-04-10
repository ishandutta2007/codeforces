#include <bits/stdc++.h>

using namespace std;

int N, M;
int adj[70][70];
int A[303];
int B[303];
int C[303];
int basis[303][303];
int row[303];
int ans[303];

bool add() {
	// puts("row");
	// for(int i = 1; i <= M + 1; i++) printf("%d ", row[i]); puts("");
	for(int i = 1; i <= M; i++) {
		if(!row[i]) continue;
		if(basis[i][i] == 1) {
			int t = 3 - row[i];
			for(int j = 1; j <= M + 1; j++) {
				row[j] = (row[j] + basis[i][j] * t) % 3;
			}
		}
		else {
			if(row[i] == 2) {
				for(int j = 1; j <= M + 1; j++) row[j] = (row[j] * 2) % 3;
			}
			for(int j = i + 1; j <= M; j++) {
				if(!basis[j][j] || !row[j]) continue;
				int t = 3 - row[j];
				for(int k = j; k <= M + 1; k++) {
					row[k] = (row[k] + t * basis[j][k]) % 3;
				}
			}
			for(int j = 1; j <= M + 1; j++) basis[i][j] = row[j];
			for(int j = 1; j < i; j++) {
				if(!basis[j][i]) continue;
				int t = 3 - basis[j][i];
				for(int k = i; k <= M + 1; k++) {
					basis[j][k] = (basis[j][k] + t * basis[i][k]) % 3;
				}
			}
			break;
		}
	}
	for(int i = 1; i <= M; i++) if(row[i]) return true;
	return row[M + 1] == 0;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 0; i <= M; i++) for(int j = 0; j <= M + 1; j++) basis[i][j] = 0;
		for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) adj[i][j] = -1;

		for(int i = 1; i <= M; i++) {
			scanf("%d%d%d", &A[i], &B[i], &C[i]);
			if(C[i] == 3) C[i] = 0;
			adj[A[i]][B[i]] = adj[B[i]][A[i]] = i;
		}

		bool ok = true;
		for(int i = 1; i <= N; i++) {
			for(int j = i + 1; j <= N; j++) {
				if(adj[i][j] == -1) continue;
				for(int k = j + 1; k <= N; k++) {
					if(adj[i][k] == -1 || adj[j][k] == -1) continue;
					for(int l = 1; l <= M + 1; l++) row[l] = 0;

					int t = 0;
					if(C[adj[i][j]] != -1) {
						t = (t + C[adj[i][j]]) % 3;
					}
					else row[adj[i][j]] = 1;

					if(C[adj[i][k]] != -1) {
						t = (t + C[adj[i][k]]) % 3;
					}
					else row[adj[i][k]] = 1;

					if(C[adj[j][k]] != -1) {
						t = (t + C[adj[j][k]]) % 3;
					}
					else row[adj[j][k]] = 1;

					row[M + 1] = (3 - t) % 3;
					if(!add()) { ok = false; break; }
				}
				if(!ok) break;
			}
			if(!ok) break;
		}

		if(!ok) { puts("-1"); continue; }

		// for(int i = 1; i <= M; i++) {
		// 	for(int j = 1; j <= M + 1; j++) printf("%d ", basis[i][j]); puts("");
		// }

		for(int i = 1; i <= M; i++) ans[i] = C[i];
		for(int i = 1; i <= M; i++) {
			if(ans[i] != -1) continue;
			if(!basis[i][i]) ans[i] = 0;
		}

		for(int i = 1; i <= M; i++) {
			if(ans[i] != -1) continue;
			if(basis[i][i]) {
				int t = basis[i][M + 1];
				for(int j = i + 1; j <= M; j++) {
					t = (t + (3 - basis[i][j]) % 3 * ans[j]) % 3;
				}
				ans[i] = t;
			}
		}

		for(int i = 1; i <= M; i++) {
			if(ans[i] == 0) ans[i] = 3;
			printf("%d ", ans[i]);
		}
		puts("");
	}
	return 0;
}