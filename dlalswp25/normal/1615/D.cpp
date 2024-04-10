#include <bits/stdc++.h>

using namespace std;

int N, M;
int p[404040];
vector<int> adj[202020];
int A[202020];
int B[202020];
int C[202020];

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

void unite(int a, int b) {
	a = par(a); b = par(b);
	p[a] = b;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i <= N + N; i++) p[i] = i;
		for(int i = 1; i < N; i++) {
			scanf("%d%d%d", &A[i], &B[i], &C[i]);
			if(C[i] == -1) continue;
			int b = 0;
			for(int j = 0; j < 30; j++) {
				if(C[i] & 1 << j) b++;
			}
			if(b & 1) {
				unite(2 * A[i], 2 * B[i] - 1);
				unite(2 * A[i] - 1, 2 * B[i]);
			}
			else {
				unite(2 * A[i], 2 * B[i]);
				unite(2 * A[i] - 1, 2 * B[i] - 1);
			}
		}
		for(int i = 1; i <= M; i++) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			if(c) {
				unite(2 * a - 1, 2 * b);
				unite(2 * a, 2 * b - 1);
			}
			else {
				unite(2 * a - 1, 2 * b - 1);
				unite(2 * a, 2 * b);
			}
		}

		bool ok = true;
		for(int i = 1; i <= N; i++) {
			if(par(2 * i) == par(2 * i - 1)) { ok = false; break; }
		}
		if(!ok) { puts("NO"); continue; }

		for(int i = 1; i < N; i++) {
			if(C[i] != -1) continue;
			if(par(2 * A[i]) == par(2 * B[i])) {
				C[i] = 0;
			}
			else if(par(2 * A[i] - 1) == par(2 * B[i])) {
				C[i] = 1;
			}
			else {
				C[i] = 0;
				unite(2 * A[i], 2 * B[i]);
				unite(2 * A[i] - 1, 2 * B[i] - 1);
			}
		}

		puts("YES");
		for(int i = 1; i < N; i++) printf("%d %d %d\n", A[i], B[i], C[i]);
	}
	return 0;
}