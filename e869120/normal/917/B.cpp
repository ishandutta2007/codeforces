#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
#pragma warning (disable: 4996)

int N, M, A[10009], B[10009], dist[10009]; char C[10009]; vector<pair<int, char>>X[10009];
int dp[109][109][27];

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) { cin >> A[i] >> B[i] >> C[i]; X[A[i]].push_back(make_pair(B[i], C[i])); }
	for (int i = 0; i < N * 2; i++) {
		for (int j = 0; j < M; j++) dist[B[j]] = max(dist[B[j]], dist[A[j]] + 1);
	}
	vector<tuple<int, int, int>>V;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) V.push_back(make_tuple(dist[i] + dist[j], i, j));
	}
	sort(V.begin(), V.end());

	// 1 : Win, 2 : Lose
	for (int i = V.size() - 1; i >= 0; i--) {
		int t1 = get<1>(V[i]), t2 = get<2>(V[i]);
		for (int k = 0; k < 26; k++) {
			dp[t1][t2][k] = 2;
			for (int l = 0; l < X[t1].size(); l++) {
				if ((X[t1][l].second - 'a') < k) continue;

				int pos1 = X[t1][l].first, pos2 = t2;
				if (dp[pos2][pos1][X[t1][l].second - 'a'] == 2) dp[t1][t2][k] = 1;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dp[i][j][0] == 1) cout << "A";
			else cout << "B";
		}
		cout << endl;
	}
	return 0;
}