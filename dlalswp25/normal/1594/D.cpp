#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;

int N, M;
char buf[20];

struct DSU {
	int p[404040];
	int sz[404040];
	bool vst[404040];

	void init(int n) {
		for(int i = 1; i <= n; i++) {
			p[i] = i;
			sz[i] = 1 - i % 2;
			vst[i] = false;
		}
	}

	int par(int x) {
		if(x == p[x]) return x;
		return p[x] = par(p[x]);
	}

	void unite(int a, int b) {
		a = par(a); b = par(b);
		if(a == b) return;
		p[a] = b; sz[b] += sz[a];
	}
}uf;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		uf.init(2 * N);
		for(int i = 1; i <= M; i++) {
			int a, b; scanf("%d%d", &a, &b);
			scanf("%s", buf);
			int t = (buf[0] == 'c');
			uf.unite(2 * a - 1, 2 * b - t);
			uf.unite(2 * a, 2 * b - (!t));
		}

		int ans = 0;
		for(int i = 1; i <= N; i++) if(uf.par(2 * i - 1) == uf.par(2 * i)) ans = INF;
		for(int i = 1; i <= 2 * N; i++) {
			int a = uf.par(2 * i - 1), b = uf.par(2 * i);
			if(uf.vst[a]) continue;
			uf.vst[a] = uf.vst[b] = true;
			ans += max(uf.sz[a], uf.sz[b]);
		}
		if(ans >= INF) puts("-1");
		else printf("%d\n", ans);
	}
	return 0;
}