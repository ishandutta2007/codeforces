#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 18], B[1 << 18]; vector<int>G[1 << 18], H[1 << 18];
tuple<int, int, int> dist[1 << 18]; pair<int, int> dist2[1 << 18]; bool used[1 << 18], forced[1 << 18];
int dp[1 << 18];

void dfs(int pos) {
	used[pos] = true; dist2[pos] = make_pair(0, pos);

	int cntv = 0;
	for (int i = 0; i < G[pos].size(); i++) {
		if (used[G[pos][i]] == true) continue;

		dfs(G[pos][i]);
		if (forced[G[pos][i]] == true) forced[pos] = true;
		dist2[pos] = max(dist2[pos], make_pair(dist2[G[pos][i]].first + 1, dist2[G[pos][i]].second));
		cntv++;
	}
	if (cntv >= 2) forced[pos] = true;
}

void dfs2(int pos, int dep) {
	if (dp[pos] != (1 << 30)) return;
	dp[pos] = dep;
	for (int i = 0; i < G[pos].size(); i++) dfs2(G[pos][i], dep + 1);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d%d", &A[i], &B[i]);
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}
	int root = -1; for (int i = 1; i <= N; i++) { if (G[i].size() >= 3) root = i; }
	dfs(root);

	for (int i = 1; i <= N - 1; i++) {
		if (forced[A[i]] == true && forced[B[i]] == true) {
			H[A[i]].push_back(B[i]);
			H[B[i]].push_back(A[i]);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (H[i].size() != 1) continue;

		vector<pair<int, int>>vec;
		for (int j = 0; j < G[i].size(); j++) {
			if (G[i][j] == H[i][0]) continue;
			vec.push_back(dist2[G[i][j]]);
		}
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		dist[i] = make_tuple(vec[0].first + vec[1].first, vec[0].second, vec[1].second);
	}

	for (int i = 1; i <= N; i++) dp[i] = (1 << 30); dfs2(root, 0);
	pair<int, int> maxn1 = make_pair(-1, -1); int maxid1 = 0;
	for (int i = 1; i <= N; i++) { if (forced[i] == true && maxn1 < make_pair(dp[i], get<0>(dist[i]))) { maxn1 = make_pair(dp[i], get<0>(dist[i])); maxid1 = i; } }

	for (int i = 1; i <= N; i++) dp[i] = (1 << 30); dfs2(maxid1, 0);
	pair<int, int> maxn2 = make_pair(-1, -1); int maxid2 = 0;
	for (int i = 1; i <= N; i++) { if (forced[i] == true && maxn2 < make_pair(dp[i], get<0>(dist[i]))) { maxn2 = make_pair(dp[i], get<0>(dist[i])); maxid2 = i; } }
	
	cout << get<1>(dist[maxid1]) << " " << get<1>(dist[maxid2]) << endl;
	cout << get<2>(dist[maxid1]) << " " << get<2>(dist[maxid2]) << endl;
	return 0;
}