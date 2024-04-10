#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = 320000;

class MergeTech {
public:
	vector<int> G[MAX_N];
	int group[MAX_N], col[MAX_N];
	int a0[MAX_N], a1[MAX_N], J[MAX_N];
	int CurrentSum;

	void init(int sz) {
		CurrentSum = 0;
		for (int i = 1; i <= sz; i++) {
			G[i].push_back(i);
			group[i] = i;
			a0[i] = 1; a1[i] = 0;
			J[i] = 2; col[i] = 0;
		}
	}
	void deletes(int u) {
		if (J[u] == 0) CurrentSum -= a1[u];
		if (J[u] == 1) CurrentSum -= a0[u];
		if (J[u] == 2) CurrentSum -= min(a0[u], a1[u]);
	}
	void adds(int u) {
		if (J[u] == 0) CurrentSum += a1[u];
		if (J[u] == 1) CurrentSum += a0[u];
		if (J[u] == 2) CurrentSum += min(a0[u], a1[u]);
	}
	void unite(int u, int v, int dif) {
		dif ^= (col[u] ^ col[v]);
		u = group[u]; v = group[v]; if (u == v) return;
		if (G[u].size() < G[v].size()) swap(u, v);
		deletes(u); 
		deletes(v);

		for (int i : G[v]) {
			col[i] ^= dif;
			group[i] = u; G[u].push_back(i);
			if (col[i] == 0) a0[u]++;
			if (col[i] == 1) a1[u]++;
		}
		G[v].clear();
		if (J[v] != 2) J[u] = (J[v] ^ dif);
		adds(u);
	}
	void decide(int pos, int x) {
		int u = group[pos];
		deletes(u);

		if (col[pos] == x) J[group[pos]] = 0;
		if (col[pos] != x) J[group[pos]] = 1;
		adds(u);
	}
};

MergeTech Z;
int N; string S;
int K; vector<int> X[MAX_N];

int main() {
	scanf("%d%d", &N, &K); cin >> S;
	for (int i = 1; i <= K; i++) {
		int p; scanf("%d", &p);
		for (int j = 1; j <= p; j++) {
			int q; scanf("%d", &q); X[q].push_back(i);
		}
	}

	Z.init(K + 1);
	for (int i = 1; i <= N; i++) {
		if (X[i].size() == 1) Z.decide(X[i][0], (S[i - 1] - '0') ^ 1);
		if (X[i].size() == 2) Z.unite(X[i][0], X[i][1], (S[i - 1] - '0') ^ 1);
		printf("%d\n", Z.CurrentSum);
	}
	return 0;
}