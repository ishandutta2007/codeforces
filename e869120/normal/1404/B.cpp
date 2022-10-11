#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int N, SX, SY, DX, DY;
int A[1 << 19], B[1 << 19];
int dist[1 << 19];
vector<int> X[1 << 19];

void dfs(int pos, int dep) {
	dist[pos] = dep;
	for (int i : X[pos]) {
		if (dist[i] == -1) dfs(i, dep + 1);
	}
}

void getdist(int pos) {
	for (int i = 1; i <= N; i++) dist[i] = -1;
	dfs(pos, 0);
}

bool solve() {
	for (int i = 1; i <= N; i++) X[i].clear();
	for (int i = 1; i <= N - 1; i++) X[A[i]].push_back(B[i]);
	for (int i = 1; i <= N - 1; i++) X[B[i]].push_back(A[i]);

	// 
	pair<int, int> maxn1 = make_pair(-1, -1);
	getdist(1);
	for (int i = 1; i <= N; i++) maxn1 = max(maxn1, make_pair(dist[i], i));
	pair<int, int> maxn2 = make_pair(-1, -1);
	getdist(maxn1.second);
	for (int i = 1; i <= N; i++) maxn2 = max(maxn2, make_pair(dist[i], i));
	DX = min(DX, maxn2.first);
	DY = min(DY, maxn2.first);

	// 
	getdist(SX);
	int dst1 = dist[SY];
	if (dst1 <= DX) return false;
	if (DX * 2 < DY) return true;
	return false;
}

int main() {
	int T; scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%d%d%d%d", &N, &SX, &SY, &DX, &DY);
		for (int j = 1; j <= N - 1; j++) scanf("%d%d", &A[j], &B[j]);
		bool I = solve();
		if (I == false) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}