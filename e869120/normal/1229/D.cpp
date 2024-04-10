#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#pragma warning (disable: 4996)

// 
map<vector<int>, int> Map;
int V[120][5];
int U[120][120];

// 
int N, M, K, P[1 << 18][5];
int A[1 << 18];

// 
int J[1 << 18][120];
bool used[120];

void init() {
	int perm[5] = { 0,1,2,3,4 };
	int cnt = 0;

	do {
		vector<int> vec;
		for (int i = 0; i < K; i++) vec.push_back(perm[i]);
		for (int i = 0; i < K; i++) V[cnt][i] = perm[i];
		Map[vec] = cnt;
		cnt++;
	} while (next_permutation(perm, perm + K));

	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			vector<int> perms(K, 0);
			for (int k = 0; k < K; k++) perms[k] = V[i][V[j][k]];
			U[i][j] = Map[perms];
		}
	}

	M = cnt;
}

long long solve(int pos) {
	for (int i = 0; i < M; i++) used[i] = false;
	used[0] = true;

	vector<int> vec; int cx = pos; long long ret = 0;
	while (true) {
		int minx = N + 1, cnts = 0;
		for (int j = 0; j < M; j++) { if (used[j] == false) minx = min(minx, J[cx][j]);  else cnts++; }
		ret += 1LL * cnts * (minx - cx);
		if (minx == N + 1) break;

		vec.push_back(A[minx]);
		queue<int> Q;
		for (int i = 0; i < M; i++) { if (used[i] == true) Q.push(i); }
		while (!Q.empty()) {
			int pos = Q.front(); Q.pop();
			for (int i : vec) {
				int to = U[pos][i];
				if (used[to] == false) { used[to] = true; Q.push(to); }
			}
		}

		cx = minx;
	}

	return ret;
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < K; j++) { scanf("%d", &P[i][j]); P[i][j]--; }
	}
	init();

	// 
	for (int i = 1; i <= N; i++) {
		vector<int> vec;
		for (int j = 0; j < K; j++) vec.push_back(P[i][j]);
		A[i] = Map[vec];
	}
	for (int i = 1; i <= N + 1; i++) {
		for (int j = 0; j < M; j++) J[i][j] = N + 1;
	}
	for (int i = 1; i <= N; i++) J[i][A[i]] = i;
	for (int i = N; i >= 1; i--) {
		for (int j = 0; j < M; j++) J[i][j] = min(J[i][j], J[i + 1][j]);
	}

	// L 
	long long Answer = 0;
	for (int i = 1; i <= N; i++) Answer += solve(i);

	cout << Answer << endl;
	return 0;
}