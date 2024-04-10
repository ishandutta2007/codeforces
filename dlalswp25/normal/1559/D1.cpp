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

	vector<pair<int, int> > ans;
	for(int i = 1; i <= N; i++) {
		for(int j = i + 1; j <= N; j++) {
			if(uf1.par(i) == uf1.par(j)) continue;
			if(uf2.par(i) == uf2.par(j)) continue;
			ans.emplace_back(i, j);
			uf1.unite(i, j); uf2.unite(i, j);
		}
	}

	printf("%d\n", ans.size());
	for(auto &i : ans) printf("%d %d\n", i.first, i.second);

	return 0;
}