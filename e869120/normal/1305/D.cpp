#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#pragma warning (disable: 4996)
using namespace std;

int N, A[1 << 18], B[1 << 18];
vector<int> X[1 << 18], G, I1, I2;
bool used[1 << 18], forced[1 << 18];

void dfs(int pos) {
	used[pos] = true; int cnts = 0;
	for (int i : X[pos]) {
		if (used[i] == true) continue;
		dfs(i); cnts++;
	}
	if (cnts == 0) G.push_back(pos);
}

void dfs2(int p1, int p2) {
	if (p1 == p2) { I2 = I1; return; }

	used[p1] = true;
	for (int i : X[p1]) {
		if (used[i] == true) continue;
		I1.push_back(i);
		dfs2(i, p2);
		I1.pop_back();
	}
}

void parse(int p1, int p2) {
	for (int i = 1; i <= N; i++) used[i] = false;
	I2.clear();
	dfs2(p2, p1);
	for (int i : I2) forced[i] = true;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		cin >> A[i] >> B[i];
		X[A[i]].push_back(B[i]);
		X[B[i]].push_back(A[i]);
	}
	dfs(1);
	if (X[1].size() == 1) G.push_back(1);

	int cr = G.size() / 2, cl = 0;
	while (cr < G.size()) {
		cout << "? " << G[cl] << " " << G[cr] << endl;
		int t; cin >> t;
		parse(G[cl], t);
		parse(G[cr], t);
		cl++; cr++;
	}

	for (int i = 1; i <= N; i++) {
		if (forced[i] == false) {
			cout << "! " << i << endl;
		}
	}
	return 0;
}