#include <bits/stdc++.h>

using namespace std;

int N;
int P[202];
int Q[202];
int C[202];
int X[202];
int pos[202];
bool chk[202];

struct DSU {
	int p[202];

	void init(int n) {
		for(int i = 1; i <= n; i++) p[i] = i;
	}

	int par(int x) {
		if(x == p[x]) return x;
		return p[x] = par(p[x]);
	}

	bool unite(int a, int b) {
		a = par(a); b = par(b);
		if(a == b) return false;
		p[a] = b;
		return true;
	}
}uf;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &P[i]);
			pos[P[i]] = i;
		}

		for(int i = 1; i <= N; i++) C[i] = 0;

		int cid = 0;
		for(int i = 1; i <= N; i++) {
			if(C[i]) continue;
			cid++;
			int x = i;
			while(!C[x]) {
				C[x] = cid;
				x = P[x];
			}
		}

		uf.init(cid);
		for(int i = 1; i <= N; i++) X[i] = 0;
		for(int i = 1; i <= N; i++) chk[i] = false;

		for(int i = 1; i < N; i++) {
			if(uf.unite(C[i], C[i + 1])) {
				chk[i] = true;
			}
		}

		int l = 0;
		for(int i = 1; i <= N; i++) {
			if(chk[i]) {
				X[i] = i + 1;
				if(!l) l = i;
			}
			else {
				if(l) {
					X[i] = l;
					l = 0;
				}
			}
		}

		// for(int i = 1; i <= N; i++) printf("%d ", X[i]); puts("");

		int x = 1;		
		Q[1] = 1;
		for(int i = 2; i <= N; i++) {
			if(X[x]) {
				Q[i] = pos[X[x]];
			}
			else {
				Q[i] = pos[x];
			}
			x = Q[i];
		}
		for(int i = 1; i <= N; i++) printf("%d ", Q[i]); puts("");
	}
	return 0;
}