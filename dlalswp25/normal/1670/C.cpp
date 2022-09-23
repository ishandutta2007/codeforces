#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int N;
int A[101010];
int B[101010];
int C[101010];
int D[101010];
bool X[101010];

struct DSU {
	int p[101010];

	void init(int n) {
		for(int i = 1; i <= n; i++) p[i] = i;
	}

	int par(int x) {
		if(x == p[x]) return x;
		return p[x] = par(p[x]);
	}

	void unite(int a, int b) {
		a = par(a); b = par(b);
		if(a == b) return;
		p[a] = b;
	}
}uf;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) X[i] = false;
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &C[i]);
		uf.init(N);
		for(int i = 1; i <= N; i++) {
			if(A[i] == B[i]) X[A[i]] = true;
			else uf.unite(A[i], B[i]);
		}
		for(int i = 1; i <= N; i++) D[i] = 0;

		int ans = 1;
		for(int i = 1; i <= N; i++) {
			if(!C[i]) continue;
			int t = uf.par(C[i]);
			if(D[t]) {
				if(D[t] == -1 && C[i] == B[i]) ans = 0;
				if(D[t] == 1 && C[i] == A[i]) ans = 0;
			}
			else {
				if(C[i] == A[i]) D[t] = -1;
				else D[t] = 1;
			}
		}

		for(int i = 1; i <= N; i++) {
			if(uf.par(i) != i) continue;
			if(X[i]) continue;
			if(!D[i]) ans = ans * 2 % MOD;
		}
		printf("%d\n", ans);
	}
	return 0;
}