#include <iostream>
#include <vector>
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
		u = root(u), v = root(v);
		par[u] = v;
	}

	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
};

int N, M, A[1 << 18], B[1 << 18]; vector<int>G[1 << 18];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &A[i], &B[i]);
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	int maxn = -1, maxid = 0;
	for (int i = 1; i <= N; i++) {
		if (maxn < (int)G[i].size()) { maxn = G[i].size(); maxid = i; }
	}

	vector<pair<int, int>>vec, actuals;
	for (int i = 1; i <= M; i++) {
		if (A[i] == maxid || B[i] == maxid) vec.push_back(make_pair(A[i], B[i]));
	}
	for (int i = 1; i <= M; i++) vec.push_back(make_pair(A[i], B[i]));

	UnionFind UF; UF.init(N + 1);
	for (int i = 0; i < vec.size(); i++) {
		if (UF.same(vec[i].first, vec[i].second) == false) {
			actuals.push_back(vec[i]);
			UF.unite(vec[i].first, vec[i].second);
		}
	}

	for (int i = 0; i < actuals.size(); i++) printf("%d %d\n", actuals[i].first, actuals[i].second);
	return 0;
}