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

int N, M, D, A[1 << 18], B[1 << 18], col[1 << 18], cnts;
vector<int>I[1 << 18], J, L; vector<pair<int, int>>vec, vec1;
bool used[1 << 18], colored[1 << 18];

void dfs(int pos) {
	if (col[pos] >= 1) return;
	col[pos] = cnts;
	for (int i = 0; i < I[pos].size(); i++) dfs(I[pos][i]);
}

void prints() {
	UnionFind UF2; UF2.init(N + 1);
	for (int i = 0; i < L.size(); i++) vec1.push_back(make_pair(1, L[i]));
	for (int i = 1; i <= M; i++) {
		if (A[i] == 1 || B[i] == 1) continue;
		vec1.push_back(make_pair(A[i], B[i]));
	}

	for (int i = 0; i < vec1.size(); i++) {
		if (UF2.same(vec1[i].first, vec1[i].second) == true) continue;
		UF2.unite(vec1[i].first, vec1[i].second);
		vec.push_back(vec1[i]);
	}

	printf("YES\n");
	for (int i = 0; i < vec.size(); i++) printf("%d %d\n", vec[i].first, vec[i].second);
}

int main() {
	scanf("%d%d%d", &N, &M, &D);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &A[i], &B[i]);
		if (B[i] == 1) J.push_back(A[i]);
		if (A[i] == 1) J.push_back(B[i]);
	}

	UnionFind UF; UF.init(N + 1);
	for (int i = 1; i <= M; i++) {
		if (A[i] != 1 && B[i] != 1 && UF.same(A[i], B[i]) == false) {
			UF.unite(A[i], B[i]);
			I[A[i]].push_back(B[i]);
			I[B[i]].push_back(A[i]);
		}
	}

	for (int i = 2; i <= N; i++) {
		if (col[i] >= 1) continue;
		cnts++; dfs(i);
	}

	int sums = 0;
	for (int pos : J) {
		if (used[col[pos]] == false) {
			used[col[pos]] = true; colored[pos] = true;
			UF.unite(1, pos);
			L.push_back(pos);
			sums++;
		}
	}

	if (sums == D) {
		prints();
		return 0;
	}
	for (int pos : J) {
		if (colored[pos] == false) {
			colored[pos] = true;
			L.push_back(pos);
			sums++;
			if (sums == D) {
				prints();
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}