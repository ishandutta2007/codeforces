#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L, R, S, A[10009], B[10009]; bool dp[10009][10009][2];
vector<pair<int, int>>V;

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	for (int i = 0; i < N; i++) { if (B[i] == 1) V.push_back(make_pair(1, A[i])); else V.push_back(make_pair(2, A[i])); }
	sort(V.begin(), V.end());

	dp[N][0][0] = true;
	for (int i = N - 1; i >= 0; i--) {
		int T = 0; if (V[i].first == 1) T = 1;
		for (int j = 0; j <= 10000; j++) {
			if (dp[i + 1][j][0] == true) {
				dp[i][j][T] = true;
				dp[i][j + V[i].second][0] = true;
			}
			if (dp[i + 1][j][1] == true) {
				dp[i][j][1] = true;
				dp[i][j + V[i].second][1] = true;
			}
		}
	}

	int S = 0, maxn = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = L; j <= R - S; j++) {
			if (dp[i][j][0] == true) maxn = max(maxn, i + 0);
			if (dp[i][j][1] == true) maxn = max(maxn, i + 1);
		}
		if (i < N) {
			S += V[i].second;
			if (V[i].first == 2) break;
		}
	}
	cout << min(N, maxn) << endl;
	return 0;
}