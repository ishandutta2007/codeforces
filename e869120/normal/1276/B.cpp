#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int T;
int N, M, U, V, A[1 << 19], B[1 << 19];
int col1[1 << 19], col2[1 << 19], cnts;
vector<int> X[1 << 19];

void dfs1(int pos) {
	col1[pos] = cnts;
	for (int i : X[pos]) {
		if (col1[i] >= 1) continue;
		dfs1(i);
	}
}

void dfs2(int pos) {
	col2[pos] = cnts;
	for (int i : X[pos]) {
		if (col2[i] >= 1) continue;
		dfs2(i);
	}
}

long long solve() {
	for (int i = 1; i <= N; i++) X[i].clear();
	for (int i = 1; i <= M; i++) {
		if (A[i] == U || B[i] == U) continue;
		X[A[i]].push_back(B[i]);
		X[B[i]].push_back(A[i]);
	}
	cnts = 0;
	for (int i = 1; i <= N; i++) col1[i] = -1;
	for (int i = 1; i <= N; i++) {
		if (col1[i] != -1) continue;
		cnts++; dfs1(i);
	}

	for (int i = 1; i <= N; i++) X[i].clear();
	for (int i = 1; i <= M; i++) {
		if (A[i] == V || B[i] == V) continue;
		X[A[i]].push_back(B[i]);
		X[B[i]].push_back(A[i]);
	}
	cnts = 0;
	for (int i = 1; i <= N; i++) col2[i] = -1;
	for (int i = 1; i <= N; i++) {
		if (col2[i] != -1) continue;
		cnts++; dfs2(i);
	}

	map<int, int> Map1; long long ret1 = 0;
	for (int i = 1; i <= N; i++) {
		if (i == U || i == V) continue;
		ret1 += Map1[col1[i]];
		Map1[col1[i]]++;
	}

	map<int, int> Map2; long long ret2 = 0;
	for (int i = 1; i <= N; i++) {
		if (i == U || i == V) continue;
		ret2 += Map2[col2[i]];
		Map2[col2[i]]++;
	}

	map<pair<int, int>, int> Map3; long long ret3 = 0;
	for (int i = 1; i <= N; i++) {
		if (i == U || i == V) continue;
		ret3 += Map3[make_pair(col1[i], col2[i])];
		Map3[make_pair(col1[i], col2[i])]++;
	}
	return 1LL * (N - 2) * (N - 3) / 2LL - (ret1 + ret2 - ret3);
}

int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%d%d%d", &N, &M, &U, &V);
		for (int j = 1; j <= M; j++) {
			scanf("%d%d", &A[j], &B[j]);
		}
		printf("%lld\n", solve());
	}
	return 0;
}