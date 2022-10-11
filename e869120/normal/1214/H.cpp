#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

// 
int N, K, A[1 << 18], B[1 << 18];
vector<pair<int, int>> X[1 << 18];

// 
int dist[1 << 18], dist1[1 << 18], dist2[1 << 18];
bool diameter[1 << 18];
vector<int> centroid;

void getdist(int stt) {
	for (int i = 1; i <= N; i++) dist[i] = (1 << 30);
	queue<int> Q; Q.push(stt); dist[stt] = 0;

	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		for (pair<int, int> i : X[pos]) {
			if (dist[i.first] > dist[pos] + 1) {
				dist[i.first] = dist[pos] + 1;
				Q.push(i.first);
			}
		}
	}
}

void init() {
	getdist(1);
	pair<int, int> maxn = make_pair(-1, -1);
	for (int i = 1; i <= N; i++) maxn = max(maxn, make_pair(dist[i], i));
	getdist(maxn.second);
	for (int i = 1; i <= N; i++) dist1[i] = dist[i];
	pair<int, int> maxn2 = make_pair(-1, -1);
	for (int i = 1; i <= N; i++) maxn2 = max(maxn2, make_pair(dist[i], i));

	int cx = maxn2.second;
	while (cx != maxn.second) {
		for (pair<int, int> i : X[cx]) {
			if (dist[i.first] < dist[cx]) { cx = i.first; diameter[i.second] = true; break; }
		}
	}

	getdist(maxn2.second);
	for (int i = 1; i <= N; i++) dist2[i] = dist[i];

	int minx = (1 << 30);
	for (int i = 1; i <= N; i++) {
		if (minx > max(dist1[i], dist2[i])) {
			minx = max(dist1[i], dist2[i]);
			centroid.clear();
		}
		if (minx == max(dist1[i], dist2[i])) {
			centroid.push_back(i);
		}
	}
}

int C[1 << 18];
vector<int> Y[1 << 18];
bool flag = false;

int dfs2(int pos, int dep) {
	C[pos] = dep; vector<int> vecs;
	for (int i = 0; i < Y[pos].size(); i++) {
		if (C[Y[pos][i]] >= 1) continue;
		int nex = dep - 1; if (nex == 0) nex = K;
		int r = dfs2(Y[pos][i], nex);
		vecs.push_back(r + 1);
	}
	sort(vecs.begin(), vecs.end());
	reverse(vecs.begin(), vecs.end());
	if (vecs.size() == 0) return 0;
	if (vecs.size() >= 2 && vecs[0] + vecs[1] + 1 >= K) flag = true;
	return vecs[0];
}

int dfs3(int pos, int dep) {
	C[pos] = dep; vector<int> vecs;
	for (int i = 0; i < Y[pos].size(); i++) {
		if (C[Y[pos][i]] >= 1) continue;
		int nex = dep + 1; if (nex == K + 1) nex = 1;
		int r = dfs3(Y[pos][i], nex);
		vecs.push_back(r + 1);
	}
	sort(vecs.begin(), vecs.end());
	reverse(vecs.begin(), vecs.end());
	if (vecs.size() == 0) return 0;
	if (vecs.size() >= 2 && vecs[0] + vecs[1] + 1 >= K) flag = true;
	return vecs[0];
}

void solve_1(vector<int> vec) {
	vector<int> V1, V2; int root = vec[0];

	int cnts = 0;
	for (pair<int, int> i : X[root]) {
		if (diameter[i.second] == true) {
			if (cnts == 0) V1.push_back(i.first);
			else V2.push_back(i.first);
			cnts++;
		}
		else {
			V2.push_back(i.first);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (A[i] == root || B[i] == root) continue;
		Y[A[i]].push_back(B[i]);
		Y[B[i]].push_back(A[i]);
	}

	C[root] = 1; vector<int> vecs;
	for (int i = 0; i < V1.size(); i++) {
		int val = dfs2(V1[i], K);
		vecs.push_back(val + 1);
	}
	for (int i = 0; i < V2.size(); i++) {
		int val = dfs3(V2[i], 2);
		vecs.push_back(val + 1);
	}
	sort(vecs.begin(), vecs.end());
	reverse(vecs.begin(), vecs.end());
	if (vecs.size() >= 3 && vecs[0] + vecs[2] + 1 >= K) flag = true;

	if (flag == true) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
		for (int i = 1; i <= N; i++) {
			if (i >= 2) printf(" ");
			printf("%d", C[i]);
		}
		printf("\n");
	}
}

void solve_2(vector<int> vec) {
	for (int i = 1; i <= N; i++) {
		if (A[i] == vec[0] && B[i] == vec[1]) continue;
		if (B[i] == vec[0] && A[i] == vec[1]) continue;
		Y[A[i]].push_back(B[i]);
		Y[B[i]].push_back(A[i]);
	}
	dfs2(vec[0], 1);
	dfs3(vec[1], 2);

	if (flag == true) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
		for (int i = 1; i <= N; i++) {
			if (i >= 2) printf(" ");
			printf("%d", C[i]);
		}
		printf("\n");
	}
}

void dfs4(int pos, int dep) {
	C[pos] = dep;
	for (int i = 0; i < X[pos].size(); i++) {
		if (C[X[pos][i].first] >= 1) continue;
		dfs4(X[pos][i].first, 3 - dep);
	}
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d%d", &A[i], &B[i]);
		X[A[i]].push_back(make_pair(B[i], i));
		X[B[i]].push_back(make_pair(A[i], i));
	}

	if (K == 2) {
		dfs4(1, 1);
		printf("Yes\n");
		for (int i = 1; i <= N; i++) {
			if (i >= 2) printf(" ");
			printf("%d", C[i]);
		}
		printf("\n");
		return 0;
	}

	init();

	if (centroid.size() == 1) {
		solve_1(centroid);
	}

	if (centroid.size() == 2) {
		solve_2(centroid);
	}
	return 0;
}