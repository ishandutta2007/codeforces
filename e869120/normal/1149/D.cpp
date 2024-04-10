#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int N, M, A, B, U[209], V[209], W[209], col[77], R[77], cnts, cnt1, cnt2; vector<int>G[77]; vector<pair<int, int>>F[77];
int dp[77][1 << 17];

void dfs(int pos) {
	if (col[pos] >= 1) return;
	col[pos] = cnts; cnt2++;
	for (int i = 0; i < G[pos].size(); i++) dfs(G[pos][i]);
}

int main() {
	cin >> N >> M >> A >> B;
	for (int i = 1; i <= M; i++) {
		cin >> U[i] >> V[i] >> W[i];
		if (W[i] == A) { G[U[i]].push_back(V[i]); G[V[i]].push_back(U[i]); }
		F[U[i]].push_back(make_pair(V[i], W[i]));
		F[V[i]].push_back(make_pair(U[i], W[i]));
	}
	for (int i = 1; i <= N; i++) R[i] = -1;
	for (int i = 1; i <= N; i++) {
		if (col[i] >= 1) continue;
		cnts++; cnt2 = 0; dfs(i);
		if (cnt2 >= 4) {
			for (int j = 1; j <= N; j++) { if (col[j] == cnts) R[j] = cnt1; }
			cnt1++;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < (1 << cnt1); j++) dp[i][j] = (1 << 30);
	}
	
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>Q;
	int s1 = 0; if (R[1] >= 0) s1 = (1 << R[1]);
	Q.push(make_tuple(0, 1, s1)); dp[1][s1] = 0;

	while (!Q.empty()) {
		int pos1 = get<1>(Q.top()), pos2 = get<2>(Q.top()); Q.pop();
		for (int i = 0; i < F[pos1].size(); i++) {
			int to = F[pos1][i].first, cost = F[pos1][i].second;
			int s2 = pos2;
			
			if (cost == B) {
				if (col[pos1] == col[to]) continue;
				else if (R[to] >= 0 && (pos2 & (1 << R[to])) >= 1) continue;
				if (R[to] >= 0) s2 = s2 + (1 << R[to]);
			}

			if (dp[to][s2] > dp[pos1][pos2] + cost) {
				dp[to][s2] = dp[pos1][pos2] + cost;
				Q.push(make_tuple(dp[to][s2], to, s2));
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (i >= 2) cout << " ";
		int minx = (1 << 30); for (int j = 0; j < (1 << cnt1); j++) minx = min(minx, dp[i][j]);
		cout << minx;
	}
	cout << endl;
	return 0;
}