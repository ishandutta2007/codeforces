#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
int C[202020];

vector<pii> adj[202020];

int st[20][202020];
int mx[20][202020];
int dep[202020];
int D[202020];

void dfs(int v, int p) {
	dep[v] = dep[p] + 1;
	st[0][v] = p;
	for(pii i : adj[v]) {
		if(i.first == p) continue;
		mx[0][i.first] = i.second;
		dfs(i.first, v);
	}
}

int query(int a, int b) {
	if(dep[a] < dep[b]) return query(b, a);
	int ret = 0;
	for(int i = 19; i >= 0; i--) {
		if(dep[st[i][a]] < dep[b]) continue;
		ret = max(ret, mx[i][a]);
		a = st[i][a];
	}
	if(a == b) return ret;
	for(int i = 19; i >= 0; i--) {
		if(st[i][a] == st[i][b]) continue;
		ret = max(ret, mx[i][a]);
		ret = max(ret, mx[i][b]);
		a = st[i][a];
		b = st[i][b];
	}
	return max(ret, max(mx[0][a], mx[0][b]));
}

void upd(int l, int r, int x) {
	D[l] += x;
	D[r + 1] -= x;
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", &C[i]);
	for(int i = 1; i < M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].emplace_back(b, i);
		adj[b].emplace_back(a, i);
	}

	dfs(1, 0);

	for(int i = 1; i <= 19; i++) {
		for(int j = 1; j <= N; j++) {
			st[i][j] = st[i - 1][st[i - 1][j]];
			mx[i][j] = max(mx[i - 1][j], mx[i - 1][st[i - 1][j]]);
		}
	}

	for(int i = 1; i < N; i++) {
		int x = query(C[i], C[i + 1]);
		// printf("%d %d\n", i, x);
		upd(0, x - 1, 1);
	}

	int s = 0;
	for(int i = 0; i < M; i++) {
		s += D[i];
		printf("%d\n", s);
	}

	return 0;
}