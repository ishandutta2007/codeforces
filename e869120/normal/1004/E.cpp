#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#pragma warning (disable: 4996)

long long N, K, A[1 << 17], B[1 << 17], C[1 << 17], dist[1 << 17], dist2[1 << 17], dp[1 << 17], deg[1 << 17];
vector<pair<int, long long>> X[1 << 17];
map<pair<int, int>, long long>Map;

void dfs(int pos, long long dep) {
	if (dist[pos] < (1LL << 30)) return;
	dist[pos] = dep;
	for (int i = 0; i < X[pos].size(); i++) dfs(X[pos][i].first, dep + X[pos][i].second);
}

void dfs2(int pos) {
	dp[pos] = 0;
	for (int i = 0; i < X[pos].size(); i++) {
		if (dp[X[pos][i].first] != -(1LL << 30)) continue;
		dfs2(X[pos][i].first);
		dp[pos] = max(dp[pos], dp[X[pos][i].first] + X[pos][i].second);
	}
}

int make_centroid() {
	for (int i = 1; i <= N; i++) dist[i] = (1LL << 30);
	dfs(1, 0);
	pair<int, int> m1 = make_pair(-1, -1); for (int i = 1; i <= N; i++) m1 = max(m1, make_pair((int)dist[i], i));
	for (int i = 1; i <= N; i++) dist[i] = (1LL << 30);
	dfs(m1.second, 0);
	pair<int, int> m2 = make_pair(-1, -1); for (int i = 1; i <= N; i++) m2 = max(m2, make_pair((int)dist[i], i));
	for (int i = 1; i <= N; i++) { dist2[i] = dist[i]; dist[i] = (1LL << 30); }
	dfs(m2.second, 0);

	long long minx = (1LL << 30), minid = -1;
	for (int i = 1; i <= N; i++) {
		long long cost = max(dist[i], dist2[i]);
		if (minx > cost) { minx = cost; minid = i; }
	}
	return minid;
}

bool solve(long long goal) {
	for (int i = 1; i <= N; i++) deg[i] = 0;
	int cnt = 0;
	for (int i = 1; i <= N - 1; i++) {
		long long T = min(dp[A[i]], dp[B[i]]) + Map[make_pair(A[i], B[i])];
		if (T > goal) { deg[A[i]]++; deg[B[i]]++; cnt++; }
	}
	if (cnt > K - 1) return false;

	for (int i = 1; i <= N; i++) { if (deg[i] >= 3) return false; }
	return true;
}

int main() {
	scanf("%lld%lld", &N, &K);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%lld%lld%lld", &A[i], &B[i], &C[i]);
		X[A[i]].push_back(make_pair(B[i], C[i])); Map[make_pair(A[i], B[i])] = C[i];
		X[B[i]].push_back(make_pair(A[i], C[i])); Map[make_pair(A[i], B[i])] = C[i];
	}

	int root = make_centroid();
	for (int i = 1; i <= N; i++) dp[i] = -(1LL << 30);
	dfs2(root);

	long long L = 0, R = (1LL << 30), M, ans = (1LL << 30);
	for (int i = 1; i <= 40; i++) {
		M = (L + R) / 2;
		bool T = solve(M);
		if (T == true) { R = M; ans = min(ans, M); }
		else { L = M; }
	}
	cout << ans << endl;
	return 0;
}