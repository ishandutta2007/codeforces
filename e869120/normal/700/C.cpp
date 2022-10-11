#include <iostream>
#include <vector>
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
		u = root(u); v = root(v);
		if (u == v) return;
		par[u] = v;
	}
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
};

int N, M, S, T, P[1 << 15], Q[1 << 15], W[1 << 15], col1[1 << 15], id[1 << 10][1 << 10], counts[1 << 10][1 << 10], cnts;
int pre[1 << 15], low[1 << 15], dista[1 << 10], distb[1 << 10]; bool used[1 << 15];
vector<int> G[1 << 15], X[1 << 15];
int minx = 2100000000; vector<int> minid;

void dfs1(int pos) {
	if (col1[pos] >= 1) return;
	col1[pos] = cnts;
	for (int i = 0; i < G[pos].size(); i++) dfs1(G[pos][i]);
}

void dfs2(int pos, int prevs, int erased) {
	pre[pos] = cnts; cnts++;
	low[pos] = pre[pos];
	for (int i = 0; i < X[pos].size(); i++) {
		int to = X[pos][i];
		if (pre[to] == -1) {
			dfs2(to, pos, erased);
			low[pos] = min(low[pos], low[to]);
			if (low[to] == pre[to]) {
				int w1 = W[erased];
				int w2 = W[id[to][pos]];
				bool I1 = (dista[pos] < dista[to]);
				bool I2 = (distb[pos] < distb[to]);
				if (minx > w1 + w2 && I1 != I2 && counts[pos][to] == 1 && erased != id[to][pos]) {
					minx = w1 + w2;
					minid = vector<int>{ erased, id[to][pos] };
				}
			}
		}
		else {
			if (prevs == to) continue;
			low[pos] = min(low[pos], low[to]);
		}
	}
}

void dfs3(int pos, int dep) {
	if (dista[pos] != -1) return;
	dista[pos] = dep;
	for (int i = 0; i < X[pos].size(); i++) dfs3(X[pos][i], dep + 1);
}

void dfs4(int pos, int dep) {
	if (distb[pos] != -1) return;
	distb[pos] = dep;
	for (int i = 0; i < X[pos].size(); i++) dfs4(X[pos][i], dep + 1);
}

void solve(int pos) {
	for (int i = 1; i <= N; i++) { low[i] = -1; pre[i] = -1; dista[i] = -1; distb[i] = -1; X[i].clear(); }
	cnts = 0;
	counts[P[pos]][Q[pos]]--; counts[Q[pos]][P[pos]]--;
	for (int i = 1; i <= M; i++) { if (i == pos) continue; X[P[i]].push_back(Q[i]); X[Q[i]].push_back(P[i]); }
	dfs3(S, 0);
	dfs4(T, 0);
	dfs2(S, -1, pos);
	counts[P[pos]][Q[pos]]++; counts[Q[pos]][P[pos]]++;
	if (pre[T] == -1) { if (minx > W[pos]) { minx = W[pos]; minid = vector<int>{ pos }; } }
}

int main() {
	cin >> N >> M >> S >> T;
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &P[i], &Q[i], &W[i]);
		G[P[i]].push_back(Q[i]); id[P[i]][Q[i]] = i; counts[P[i]][Q[i]]++;
		G[Q[i]].push_back(P[i]); id[Q[i]][P[i]] = i; counts[Q[i]][P[i]]++;
	}
	for (int i = 1; i <= N; i++) {
		if (col1[i] >= 1) continue;
		cnts++; dfs1(i);
	}

	if (col1[S] != col1[T]) {
		cout << "0" << endl;
		cout << "0" << endl << endl;
		return 0;
	}

	UnionFind UF; UF.init(N + 2);
	for (int i = 1; i <= M; i++) {
		if (UF.same(P[i], Q[i]) == false) {
			UF.unite(P[i], Q[i]);
			used[i] = true;
		}
	}

	for (int i = 1; i <= M; i++) {
		if (used[i] == false) continue;
		solve(i);
	}
	if (minx == 2100000000) {
		cout << "-1" << endl;
	}
	else {
		cout << minx << endl;
		cout << minid.size() << endl;
		for (int i = 0; i < minid.size(); i++) { if (i) cout << " "; cout << minid[i]; } cout << endl;
	}
	return 0;
}