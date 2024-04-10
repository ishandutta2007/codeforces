#include <bits/stdc++.h>

using namespace std;

int N, M1, M2;

struct DSU {
	int p[101010];

	void init() {
		for(int i = 1; i <= N; i++) p[i] = i;
	}

	int par(int x) {
		if(x == p[x]) return x;
		return p[x] = par(p[x]);
	}

	void unite(int a, int b) {
		a = par(a); b = par(b);
		p[a] = b;
	}
}uf1, uf2;

set<int> S1, S2;

void f(int a, int b) {
	printf("%d %d\n", a, b);
	S1.erase(uf1.par(a)); uf1.unite(a, b);
	S2.erase(uf2.par(a)); uf2.unite(a, b);
}

int main() {
	scanf("%d%d%d", &N, &M1, &M2);
	uf1.init(); uf2.init();
	for(int i = 1; i <= M1; i++) {
		int a, b; scanf("%d%d", &a, &b);
		uf1.unite(a, b);
	}
	for(int i = 1; i <= M2; i++) {
		int a, b; scanf("%d%d", &a, &b);
		uf2.unite(a, b);
	}

	for(int i = 1; i <= N; i++) {
		if(uf1.par(i) == i) S1.insert(i);
		if(uf2.par(i) == i) S2.insert(i);
	}

	int ans = N - 1 - max(M1, M2);
	printf("%d\n", ans);
	for(int i = 0; i < ans; i++) {
		assert(S1.size() > 1 && S2.size() > 1);
		// printf("S1 "); for(int j : S1) printf("%d ", j); puts("");
		// printf("S2 "); for(int j : S2) printf("%d ", j); puts("");
		int a = *S1.begin();
		S1.erase(S1.begin());
		int b = *S1.begin();
		S1.insert(a);
		if(uf2.par(a) != uf2.par(b)) {
			f(a, b); continue;
		}
		int c = *S2.begin();
		if(uf2.par(c) == uf2.par(a)) {
			S2.erase(S2.begin());
			c = *S2.begin();
			S2.insert(uf2.par(a));
		}
		if(uf1.par(a) != uf1.par(c)) f(a, c);
		else f(b, c);
	}

	return 0;
}