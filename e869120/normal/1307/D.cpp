#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, M, K;
long long A[1 << 18], B[1 << 18];
bool used[1 << 18];

vector<int> X[1 << 18];
long long dist1[1 << 18], dist2[1 << 18];

vector<pair<int, int>> G[1 << 18];

bool solve(int border) {
	for (int i = 1; i <= N; i++) {
		if (used[i] == false) continue;
		int r = border - 1 - dist2[i];
		int s = border - 1 - dist1[i];
		if (r < 0) r = 0;
		for (int j = 0; j < G[r].size(); j++) {
			if (G[r][j].second != i && G[r][j].first >= s) return true;
		}
	}
	return false;
}

int main() {
	scanf("%lld%lld%lld", &N, &M, &K);
	for (int i = 1; i <= K; i++) {
		long long c; scanf("%lld", &c);
		used[c] = true;
	}
	for (int i = 1; i <= M; i++) {
		scanf("%lld%lld", &A[i], &B[i]);
		X[A[i]].push_back(B[i]);
		X[B[i]].push_back(A[i]);
	}
	for (int i = 1; i <= N; i++) dist1[i] = (1LL << 60);
	for (int i = 1; i <= N; i++) dist2[i] = (1LL << 60);

	// 
	queue<int> Q;
	Q.push(1); dist1[1] = 0;
	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		for (int i : X[pos]) {
			if (dist1[i] > dist1[pos] + 1) {
				dist1[i] = dist1[pos] + 1;
				Q.push(i);
			}
		}
	}
	Q.push(N); dist2[N] = 0;
	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		for (int i : X[pos]) {
			if (dist2[i] > dist2[pos] + 1) {
				dist2[i] = dist2[pos] + 1;
				Q.push(i);
			}
		}
	}

	// 
	for (int i = 1; i <= N; i++) {
		if (used[i] == false) continue;
		G[dist1[i]].push_back(make_pair(dist2[i], i));
	}
	for (int i = N; i >= 0; i--) {
		for (int j = 0; j < G[i + 1].size(); j++) G[i].push_back(G[i + 1][j]);
		sort(G[i].begin(), G[i].end());
		reverse(G[i].begin(), G[i].end());
		while (G[i].size() > 2) G[i].pop_back();
	}

	// 
	int cl = 0, cr = N + 1, cm, maxn = -(1 << 30);
	for (int i = 0; i < 22; i++) {
		cm = (cl + cr) / 2; 
		bool I = solve(cm);
		if (I == true) { maxn = max(maxn, cm); cl = cm; }
		else { cr = cm; }
	}
	cout << min(1LL * maxn, dist1[N]) << endl;
	return 0;
}