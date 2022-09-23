#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M, K;

ll D[606][606];
ll Q[606][606];
ll X[606][606];
int A[404040];
int B[404040];
int C[404040];

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(i != j) D[i][j] = (1LL << 60);
		}
	}

	for(int i = 1; i <= M; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		D[a][b] = min(D[a][b], (ll)c);
		D[b][a] = D[a][b];
		A[i] = a; B[i] = b; C[i] = c;
	}

	for(int k = 1; k <= N; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}

	scanf("%d", &K);
	for(int i = 1; i <= K; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		Q[a][b] = max(Q[a][b], (ll)c);
		Q[b][a] = Q[a][b];
	}

	for(int y = 1; y <= N; y++) {
		for(int u = 1; u <= N; u++) {
			for(int v = 1; v <= N; v++) {
				X[y][u] = max(X[y][u], Q[u][v] - D[y][v]);
			}
		}
	}

	int ans = 0;
	for(int i = 1; i <= M; i++) {
		int x = A[i], y = B[i];
		bool ok = false;
		for(int u = 1; u <= N; u++) {
			ll t = C[i] + D[x][u];
			if(X[y][u] >= t) { ok = true; break; }
		}
		if(ok) ans++;
	}
	printf("%d\n", ans);
	return 0;
}