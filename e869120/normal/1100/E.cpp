#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, M, A[1 << 18], B[1 << 18], C[1 << 18], Order[1 << 18], deg[1 << 18];
vector<int> X[1 << 17];

bool istopological(int pos) {
	for (int i = 0; i <= N; i++) { X[i].clear(); deg[i] = 0; Order[i] = 0; }
	for (int i = 1; i <= M; i++) {
		if (C[i] > pos) {
			X[A[i]].push_back(B[i]);
			deg[B[i]]++;
		}
	}
	queue<int>Q; int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (deg[i] == 0) { Q.push(i); cnt++; Order[i] = cnt; }
	}
	while (!Q.empty()) {
		int pos1 = Q.front(); Q.pop();
		for (int i = 0; i < X[pos1].size(); i++) {
			deg[X[pos1][i]]--;
			if (deg[X[pos1][i]] == 0) { Q.push(X[pos1][i]); cnt++; Order[X[pos1][i]] = cnt; }
		}
	}
	for (int i = 1; i <= N; i++) {
		if (deg[i] >= 1) return false;
	}
	return true;
}

int main() {
	scanf("%d%d", &N, &M); int maxn = 0;
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &A[i], &B[i], &C[i]);
		maxn = max(maxn, C[i]);
	}
	int cl = 0, cr = maxn + 2, cm, minx = (1 << 30);
	for (int i = 0; i < 35; i++) {
		cm = (cl + cr) / 2;
		bool I = istopological(cm);
		if (I == true) { cr = cm; minx = min(minx, cm); }
		else { cl = cm; }
	}
	istopological(minx);
	printf("%d", minx);
	vector<int> vec;
	for (int i = 1; i <= M; i++) {
		if (C[i] <= minx && Order[A[i]] > Order[B[i]]) vec.push_back(i);
	}
	printf(" %d\n", (int)vec.size());
	for (int i = 0; i < vec.size(); i++) { if (i) printf(" "); printf("%d", vec[i]); } printf("\n");
	return 0;
}