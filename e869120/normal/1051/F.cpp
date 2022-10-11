#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
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

long long N, M, A[110009], B[110009], C[110009], dp[110009][22], dist[110009], dista[110009], D[44][44]; bool used[110009];
vector<pair<int, int> >G[110009]; vector<tuple<int, int, long long>>vec; vector<int>V;

void dfs(int pos, long long dep, int dep2) {
	dist[pos] = dep; dista[pos] = dep2; used[pos] = true;
	for (int i = 0; i < G[pos].size(); i++) {
		if (used[G[pos][i].first] == true) continue;
		dp[G[pos][i].first][0] = pos;
		dfs(G[pos][i].first, dep + 1LL * G[pos][i].second, dep2 + 1);
	}
}

int prevs(int pos, int x) {
	for (int i = 21; i >= 0; i--) {
		if (x >= (1 << i)) { x -= (1 << i); pos = dp[pos][i]; }
	}
	return pos;
}

int lca(int u, int v) {
	if (dista[u] > dista[v]) swap(u, v);
	v = prevs(v, dista[v] - dista[u]);
	if (u == v) return u;

	for (int i = 21; i >= 0; i--) {
		if (dp[u][i] != dp[v][i]) { u = dp[u][i]; v = dp[v][i]; }
	}
	return dp[u][0];
}

long long getdist(int u, int v) {
	long long e = lca(u, v);
	return dist[u] + dist[v] - 2 * dist[e];
}

void init_val() {
	dfs(1, 0, 0);
	for (int i = 1; i <= 21; i++) {
		for (int j = 1; j <= N; j++) dp[j][i] = dp[dp[j][i - 1]][i - 1];
	}
	for (int i = 0; i < V.size(); i++) {
		for (int j = 0; j < V.size(); j++) {
			D[i][j] = getdist(V[i], V[j]);
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		int pos1 = lower_bound(V.begin(), V.end(), get<0>(vec[i])) - V.begin();
		int pos2 = lower_bound(V.begin(), V.end(), get<1>(vec[i])) - V.begin();
		D[pos1][pos2] = min(D[pos1][pos2], get<2>(vec[i]));
		D[pos2][pos1] = min(D[pos2][pos1], get<2>(vec[i]));
	}
	for (int k = 0; k < V.size(); k++) {
		for (int i = 0; i < V.size(); i++) {
			for (int j = 0; j < V.size(); j++) {
				if (D[i][j] > D[i][k] + D[k][j]) D[i][j] = D[i][k] + D[k][j];
			}
		}
	}
}

long long query(int u, int v) {
	for (int i = 0; i < V.size(); i++) {
		D[V.size()][i] = getdist(V[i], u);
		D[i][V.size()] = D[V.size()][i];
		D[V.size() + 1][i] = getdist(V[i], v);
		D[i][V.size() + 1] = D[V.size() + 1][i];
	}
	D[V.size()][V.size() + 1] = getdist(u, v);
	D[V.size() + 1][V.size()] = getdist(v, u);

	long long ans = D[V.size()][V.size() + 1];
	for (int i = 0; i < V.size(); i++) {
		for (int j = 0; j < V.size(); j++) {
			ans = min(ans, D[V.size()][i] + D[i][j] + D[j][V.size() + 1]);
		}
	}
	return ans;
}

int main() {
	scanf("%lld%lld", &N, &M);

	UnionFind UF; UF.init(N + 2);
	for (int i = 1; i <= M; i++) {
		scanf("%lld%lld%lld", &A[i], &B[i], &C[i]);
		if (UF.same(A[i], B[i]) == false) {
			G[A[i]].push_back(make_pair(B[i], C[i]));
			G[B[i]].push_back(make_pair(A[i], C[i]));
			UF.unite(A[i], B[i]);
		}
		else {
			V.push_back(A[i]);
			V.push_back(B[i]);
			vec.push_back(make_tuple(A[i], B[i], C[i]));
		}
	}
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());
	
	init_val();

	int Q; scanf("%d", &Q);
	for (int i = 1; i <= Q; i++) {
		int u, v; scanf("%d%d", &u, &v);
		printf("%lld\n", query(u, v));
	}
	return 0;
}