#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

class UnionFind {
public:
	vector<int>par;

	void init(int size_) {
		par.resize(size_, -1);
	}
	int root(int pos) {
		if (par[pos] == -1) return pos;
		par[pos] = root(par[pos]);
		return par[pos];
	}
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
	void unite(int u, int v) {
		u = root(u); v = root(v); if (u == v) return;
		par[u] = v;
	}
};

vector<int>x[300009]; long long N, M, P[300009], Q[300009], A[300009], B[300009], C[300009], E[300009], sum, dist[300009];
bool used[300009], paid[300009];
vector<int>y;

void dfs(int pos, int par, int depth) {
	used[pos] = true; dist[pos] = depth; P[pos] = par;

	vector<int>T;
	for (int i = 0; i < x[pos].size(); i++) {
		if (used[x[pos][i]] == true) continue;
		dfs(x[pos][i], pos, depth + 1); T.push_back(x[pos][i]);
	}

	long long F = C[pos];

	for (int i : T) F -= E[i];
	E[pos] = F;
}

int main() {
	cin >> N >> M; UnionFind UF; UF.init(N + 2);
	for (int i = 1; i <= N; i++) cin >> C[i];
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &A[i], &B[i]);
		if (UF.same(A[i], B[i]) == false) {
			UF.unite(A[i], B[i]);
			x[A[i]].push_back(B[i]);
			x[B[i]].push_back(A[i]); paid[i] = true;
		}
		else {
			y.push_back(i);
		}
	}
	dfs(1, -1, 0);

	bool OK = false;

	if (E[1] == 0) OK = true;
	else {
		pair<int, int>D = make_pair(-1, -1); int DT = 0;
		for (int i = 0; i < y.size(); i++) {
			int p1 = A[y[i]], p2 = B[y[i]];
			if (dist[p1] % 2 != dist[p2] % 2 || E[1] % 2 == 1) continue;
			D = make_pair(p1, p2); DT = y[i];
			if (dist[p1] % 2 == 0) { Q[y[i]] = E[1] / 2; OK = true; break; }
			if (dist[p1] % 2 == 1) { Q[y[i]] = -E[1] / 2; OK = true; break; }
		}
		if (OK == true) {
			for (int i = 1; i <= N; i++) used[i] = false;
			C[D.first] -= Q[DT]; C[D.second] -= Q[DT];
			dfs(1, -1, 0);
		}
	}

	if (OK == true) {
		cout << "YES" << endl;
		for (int j = 1; j <= M; j++) {
			if (dist[A[j]] < dist[B[j]]) swap(A[j], B[j]);
			if (paid[j] == true) {
				cout << E[A[j]] << endl;
			}
			else {
				cout << Q[j] << endl;
			}
		}
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}