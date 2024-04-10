#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
int dfn[202020];
int ed[202020];
int dep[202020];
int st[20][202020];
vector<int> v[202020];
vector<int> adj[202020];
vector<int> X;
int id;

struct FWT {
	int T[202020];

	void upd(int x, int v) {
		if(!x) return;
		for(int i = x; i <= N; i += i&-i) T[i] += v;
	}
	
	int get(int x) {
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}

	void upd(int l, int r, int v) {
		// printf("upd %d %d %d\n", l, r, v);
		upd(l, v);
		upd(r + 1, -v);
	}
}fwt;

void dfs(int v, int p) {
	dfn[v] = ++id;
	dep[v] = dep[p] + 1;
	st[0][v] = p;
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
	}
	ed[v] = id;
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

int up(int v, int u) {
	for(int i = 19; i >= 0; i--) {
		if(dep[st[i][v]] <= dep[u]) continue;
		v = st[i][v];
	}
	return v;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		X.push_back(A[i]);
	}
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());

	for(int i = 1; i <= N; i++) {
		A[i] = lower_bound(X.begin(), X.end(), A[i]) - X.begin() + 1;
		v[A[i]].push_back(i);
	}

	dfs(1, 0);

	for(int i = 1; i <= 19; i++) for(int j = 1; j <= N; j++) st[i][j] = st[i - 1][st[i - 1][j]];

	int M = X.size();
	for(int i = 1; i <= M; i++) {
		sort(v[i].begin(), v[i].end(), [&](const int& a, const int& b) {
			return dfn[a] < dfn[b];
		});
		if(v[i].size() <= 2) continue;

		bool ok = true;
		if(lca(v[i][0], v[i][1]) == v[i][0]) {
			int u = up(v[i][1], v[i][0]);
			for(int j = 2; j < v[i].size(); j++) {
				if(lca(v[i][j - 1], v[i][j]) == v[i][j - 1]) { ok = false; break; }
				if(lca(u, v[i][j]) != u) { ok = false; break; }
			}
		}
		else {
			for(int j = 2; j < v[i].size(); j++) {
				if(lca(v[i][j - 1], v[i][j]) == v[i][j - 1]) { ok = false; break; }
			}
		}
		if(!ok) { puts("0"); return 0; }
	}

	for(int i = 1; i <= M; i++) {
		if(v[i].size() == 1) continue;

		for(int j = 1; j < v[i].size(); j++) {
			fwt.upd(dfn[v[i][j]], ed[v[i][j]], 1);
		}

		if(lca(v[i][0], v[i][1]) == v[i][0]) {
			fwt.upd(1, N, 1);
			int t = up(v[i][1], v[i][0]);
			fwt.upd(dfn[t], ed[t], -1);
		}
		else fwt.upd(dfn[v[i][0]], ed[v[i][0]], 1);
	}

	int ans = 0;
	for(int i = 1; i <= N; i++) {
		ans += (fwt.get(dfn[i]) == 0);
		// printf("%d %d\n", i, ans);
	}
	printf("%d\n", ans);

	return 0;
}

/*
5
1 3 2 2 1
1 2
1 3
2 4
2 5
*/