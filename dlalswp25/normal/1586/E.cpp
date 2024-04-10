#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
vector<int> adj[303030];

int st[20][303030];
int dep[303030];
int chk[303030];
vector<int> ans[303030];

struct DSU {
	int p[303030] = {0, };

	int par(int x) {
		if(x == p[x]) return x;
		return p[x] = par(p[x]);
	}

	void unite(int a, int b) {
		a = par(a); b = par(b);
		p[a] = b;
	}
}uf;

void dfs(int v, int p) {
	st[0][v] = p;
	dep[v] = dep[p] + 1;
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
	}
}

int lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int i = 19; i >= 0; i--) {
		if(dep[st[i][a]] < dep[b]) continue;
		a = st[i][a];
	}
	if(a == b) return a;
	for(int i = 19; i >= 0; i--) {
		if(st[i][a] == st[i][b]) continue;
		a = st[i][a]; b = st[i][b];
	}
	return st[0][a];
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) uf.p[i] = i;
	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		if(uf.par(a) == uf.par(b)) continue;
		uf.unite(a, b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);
	for(int i = 1; i <= 19; i++) for(int j = 1; j <= N; j++) st[i][j] = st[i - 1][st[i - 1][j]];

	scanf("%d", &Q);
	for(int q = 1; q <= Q; q++) {
		int a, b; scanf("%d%d", &a, &b);
		int l = lca(a, b);

		while(a != l) {
			ans[q].push_back(a);
			chk[a] ^= 1;
			a = st[0][a];
		}
		ans[q].push_back(l);

		vector<int> tmp;
		while(b != l) {
			tmp.push_back(b);
			chk[b] ^= 1;
			b = st[0][b];
		}

		while(tmp.size()) {
			ans[q].push_back(tmp.back());
			tmp.pop_back();
		}
	}

	int s = 0;
	for(int i = 1; i <= N; i++) {
		int t = chk[i];
		for(int j : adj[i]) {
			if(j == st[0][i]) continue;
			if(chk[j]) t ^= 1;
		}
		if(t) s++;
	}

	if(!s) {
		puts("YES");
		for(int i = 1; i <= Q; i++) {
			printf("%d\n", ans[i].size());
			for(int j : ans[i]) printf("%d ", j); puts("");
		}
	}
	else {
		puts("NO");
		printf("%d\n", s / 2);
	}

	return 0;
}