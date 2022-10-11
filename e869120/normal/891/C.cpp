#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

vector<int>I;

class UnionFind {
public:
	vector<int>par;

	void init(int size_) {
		par.resize(size_, -1);
	}
	int root(int pos) {
		if (par[pos] == -1) return pos;
		par[pos] = root(par[pos]); I.push_back(pos);
		return par[pos];
	}
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
	void unite(int u, int v) {
		u = root(u); v = root(v);
		if (u == v) return;
		par[u] = v; I.push_back(u);
	}
};

const int MAX_N = 500009;

int N, E, Q, X[MAX_N], Y[MAX_N], W[MAX_N], ans[MAX_N]; vector<tuple<int, int, int, int>>tup;
vector<int>Z[MAX_N], L[MAX_N]; map<int, vector<pair<int, int>>>M[MAX_N];

int main() {
	cin >> N >> E;
	for (int i = 1; i <= E; i++) {
		scanf("%d%d%d", &X[i], &Y[i], &W[i]);
		tup.push_back(make_tuple(W[i], 2, X[i], Y[i]));
	}
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		int G; scanf("%d", &G);
		for (int j = 0; j < G; j++) {
			int P; scanf("%d", &P);
			Z[i].push_back(P); L[i].push_back(W[P]);
			tup.push_back(make_tuple(W[P], 1, P, i));
		}
	}
	UnionFind UF; UF.init(N + 2);
	for (int i = 1; i <= Q; i++) { sort(L[i].begin(), L[i].end()); L[i].erase(unique(L[i].begin(), L[i].end()), L[i].end()); }
	sort(tup.begin(), tup.end());
	
	for (int i = 0; i < tup.size(); i++) {
		if (get<1>(tup[i]) == 1) {
			int x1 = UF.root(X[get<2>(tup[i])]), y1 = UF.root(Y[get<2>(tup[i])]);
			if (x1 == y1) {
				ans[get<3>(tup[i])] = 1;
			}
			M[get<3>(tup[i])][get<0>(tup[i])].push_back(make_pair(x1, y1));
		}
		if (get<1>(tup[i]) == 2) {
			if (UF.same(get<2>(tup[i]), get<3>(tup[i])) == false) {
				UF.unite(get<2>(tup[i]), get<3>(tup[i]));
			}
		}
	}
	UnionFind UF2; UF2.init(N + 2);
	for (int i = 1; i <= Q; i++) {
		if (ans[i] == 1) continue;
		for (int j = 0; j < L[i].size(); j++) {
			vector<pair<int, int>> R = M[i][L[i][j]];
			I.clear();
			for (int k = 0; k < R.size(); k++) {
				if (UF2.same(R[k].first, R[k].second) == false) UF2.unite(R[k].first, R[k].second);
				else {
					ans[i] = 1;
				}
			}
			for (int k = 0; k < I.size(); k++) UF2.par[I[k]] = -1;
		}
	}
	for (int i = 1; i <= Q; i++) {
		if (ans[i] == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}