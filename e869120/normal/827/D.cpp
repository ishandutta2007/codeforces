#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

class UnionFind {
public:
	vector<int>par;
	void init(int sz) {
		par.resize(sz, -1);
	}
	int root(int pos) {
		if (par[pos] == -1) return pos;
		par[pos] = root(par[pos]);
		return par[pos];
	}
	void unite(int u, int v) {
		u = root(u); v = root(v); if (u == v) return;
		par[u] = v;
	}
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
};

int N, M, A[1 << 18], B[1 << 18], C[1 << 18], dist[1 << 18], Order[1 << 18];
int par[1 << 18][22], parw[1 << 18][22];
vector<int>G[1 << 18]; map<pair<int, int>, int>Map;
bool used[1 << 18];

int Answer[1 << 18];

void dfs1(int pos, int dep) {
	used[pos] = true; dist[pos] = dep;
	for (int i = 0; i < G[pos].size(); i++) {
		if (used[G[pos][i]] == true) continue;
		par[G[pos][i]][0] = pos; parw[G[pos][i]][0] = Map[make_pair(pos, G[pos][i])];
		dfs1(G[pos][i], dep + 1);
	}
}

int prevs(int u, int x) {
	for (int i = 21; i >= 0; i--) {
		if (x >= (1 << i)) { u = par[u][i]; x -= (1 << i); }
	}
	return u;
}

int lca(int u, int v) {
	if (dist[u] > dist[v]) swap(u, v);
	v = prevs(v, dist[v] - dist[u]);
	if (u == v) return u;

	for (int i = 21; i >= 0; i--) {
		if (par[u][i] != par[v][i]) { u = par[u][i]; v = par[v][i]; }
	}
	return par[u][0];
}

int prevs_2(int u, int x) {
	int minx = 0;
	for (int i = 21; i >= 0; i--) {
		if (x >= (1 << i)) { minx = max(minx, parw[u][i]); u = par[u][i]; x -= (1 << i); }
	}
	return minx;
}

int lca_weight(int u, int v) {
	int L = lca(u, v);
	int L1 = prevs_2(u, dist[u] - dist[L]);
	int L2 = prevs_2(v, dist[v] - dist[L]);
	return max(L1, L2);
}

void Step_1() {
	// 
	UnionFind UF; UF.init(N + 2);
	vector<tuple<int, int, int, int>>I;
	for (int i = 1; i <= M; i++) I.push_back(make_tuple(C[i], A[i], B[i], i));
	sort(I.begin(), I.end());
	for (int i = 1; i <= M; i++) { A[i] = get<1>(I[i - 1]); B[i] = get<2>(I[i - 1]); C[i] = get<0>(I[i - 1]); Order[get<3>(I[i - 1])] = i; }

	for (int i = 1; i <= M; i++) {
		if (UF.same(A[i], B[i]) == false) {
			G[A[i]].push_back(B[i]); Map[make_pair(A[i], B[i])] = C[i];
			G[B[i]].push_back(A[i]); Map[make_pair(B[i], A[i])] = C[i];
			UF.unite(A[i], B[i]);
		}
	}
}

void Step_2() {
	// 
	dfs1(1, 0);
	for (int i = 1; i <= 21; i++) {
		for (int j = 1; j <= N; j++) par[j][i] = par[par[j][i - 1]][i - 1];
	}
	for (int i = 1; i <= 21; i++) {
		for (int j = 1; j <= N; j++) parw[j][i] = max(parw[j][i - 1], parw[par[j][i - 1]][i - 1]);
	}
}

int col[1 << 18][22];

void Step_3() {
	for (int i = 1; i <= N; i++) { for (int j = 0; j <= 21; j++) col[i][j] = (1 << 30); }

	for (int i = 1; i <= M; i++) {
		if (Map[make_pair(A[i], B[i])] >= 1) continue;
		Answer[i] = lca_weight(A[i], B[i]) - 1;

		int M1 = lca(A[i], B[i]);
		int M2 = dist[A[i]] - dist[M1], X2 = A[i];
		for (int j = 21; j >= 0; j--) {
			if (M2 >= (1 << j)) { M2 -= (1 << j); col[X2][j] = min(col[X2][j], C[i]); X2 = par[X2][j]; }
		}
		int M3 = dist[B[i]] - dist[M1], X3 = B[i];
		for (int j = 21; j >= 0; j--) {
			if (M3 >= (1 << j)) { M3 -= (1 << j); col[X3][j] = min(col[X3][j], C[i]); X3 = par[X3][j]; }
		}
	}
	for (int i = 21; i >= 1; i--) {
		for (int j = 1; j <= N; j++) {
			col[j][i - 1] = min(col[j][i - 1], col[j][i]);
			col[par[j][i - 1]][i - 1] = min(col[par[j][i - 1]][i - 1], col[j][i]);
		}
	}
}

void Step_4() {
	for (int i = 1; i <= M; i++) {
		if (Map[make_pair(A[i], B[i])] == 0) continue;
		int D1 = A[i], D2 = B[i]; if (dist[D1] > dist[D2]) swap(D1, D2);
		Answer[i] = col[D2][0] - 1;
		if (Answer[i] > 1050000000) Answer[i] = -1;
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) { scanf("%d%d%d", &A[i], &B[i], &C[i]); }
	Step_1();
	Step_2();
	Step_3();
	Step_4();
	for (int i = 1; i <= M; i++) { if (i >= 2) printf(" "); printf("%d", Answer[Order[i]]); } printf("\n");
	return 0;
}