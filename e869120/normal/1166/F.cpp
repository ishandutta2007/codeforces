#include <iostream>
#include <map>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

class UnionFind {
public:
	vector<int>par, important;

	void init(int sz, vector<int>imp) {
		par.resize(sz, -1);
		important.resize(sz, (1 << 30));
		for (int i = 0; i < imp.size(); i++) important[imp[i]] = i;
	}
	int root(int pos) {
		if (par[pos] == -1) return pos;
		par[pos] = root(par[pos]);
		return par[pos];
	}
	void unite(int u, int v) {
		u = root(u); v = root(v); if (u == v) return;
		if (important[u] > important[v]) par[u] = v; // v 
		else par[v] = u; // u 
	}
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
};

const int Border = 1000;

int N, M, C, Q, A[100009], B[100009], T[100009], deg[100009];
char T1[100009]; int T2[100009], T3[100009], T4[100009];

int id[100009], roots[509], cnts; vector<int> R[509], G[100009];
map<int, int>Map[100009], Bridge[100009];
UnionFind UF, UF2[509];

void add_edge(int u, int v, int w) {
	if (Map[u][w] >= 1) {
		int Z = Map[u][w];
		UF.unite(Z, v);
		for (int i = 1; i <= cnts; i++) { if (roots[i] != Z && roots[i] != v) UF2[i].unite(Z, v); }
	}
	else Map[u][w] = v;

	if (Map[v][w] >= 1) {
		int Z = Map[v][w];
		UF.unite(Z, u);
		for (int i = 1; i <= cnts; i++) { if (roots[i] != Z && roots[i] != u) UF2[i].unite(Z, u); }
	}
	else Map[v][w] = u;

	Bridge[u][v] = 1;
	Bridge[v][u] = 1;
	G[u].push_back(v);
	G[v].push_back(u);
}

bool check(int u, int v) {
	if (UF.same(u, v) == true) return true;

	if (id[v] >= 1) {
		int D = UF2[id[v]].root(u);
		if (Bridge[D][v] == 1) return true;
		return false;
	}
	else {
		for (int i = 0; i < G[v].size(); i++) {
			if (UF.same(u, G[v][i]) == true) return true;
		}
		return false;
	}
}

int main() {
	scanf("%d%d%d%d", &N, &M, &C, &Q);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &A[i], &B[i], &T[i]);
		deg[A[i]]++; deg[B[i]]++;
	}
	for (int i = 1; i <= Q; i++) {
		cin >> T1[i];
		if (T1[i] == '+') { scanf("%d%d%d", &T2[i], &T3[i], &T4[i]); deg[T2[i]]++; deg[T3[i]]++; }
		else scanf("%d%d", &T2[i], &T3[i]);
	}
	for (int i = 1; i <= N; i++) {
		if (deg[i] >= Border) { cnts++; roots[cnts] = i; id[i] = cnts; }
	}
	for (int i = 1; i <= M; i++) {
		if (id[A[i]] >= 1) R[id[A[i]]].push_back(B[i]);
		if (id[B[i]] >= 1) R[id[B[i]]].push_back(A[i]);
	}
	for (int i = 1; i <= Q; i++) {
		if (T1[i] == '?') continue;
		if (id[T2[i]] >= 1) R[id[T2[i]]].push_back(T3[i]);
		if (id[T3[i]] >= 1) R[id[T3[i]]].push_back(T2[i]);
	}
	UF.init(N + 2, vector<int>{});
	for (int i = 1; i <= cnts; i++) UF2[i].init(N + 2, R[i]);

	for (int i = 1; i <= M; i++) add_edge(A[i], B[i], T[i]);
	for (int i = 1; i <= Q; i++) {
		if (T1[i] == '+') add_edge(T2[i], T3[i], T4[i]);
		if (T1[i] == '?') {
			bool I = check(T2[i], T3[i]);
			if (I == true) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}