#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N, K, V, S, A[100009];
int dp[5009][5009], pre[5009][5009];
bool used[5009];

int main() {
	cin >> N >> K >> V;
	for (int i = 1; i <= N; i++) { cin >> A[i]; S += A[i]; }
	for (int i = 0; i <= N; i++) { for (int j = 0; j < K; j++) dp[i][j] = -(1 << 30); }

	dp[0][0] = 0;
	for (int i = 0; i < N; i++) {
		int P1 = A[i + 1] % K;
		int P2 = A[i + 1] - P1;
		for (int j = 0; j < K; j++) {
			if (dp[i][j] == -(1 << 30)) continue;
			int E = (j + P1) % K;
			if (dp[i + 1][j] < dp[i][j] + P2) { dp[i + 1][j] = dp[i][j] + P2; pre[i + 1][j] = 0; }
			if (dp[i + 1][E] < dp[i][j] + A[i + 1]) { dp[i + 1][E] = dp[i][j] + A[i + 1]; pre[i + 1][E] = 1; }
		}
	}

	if (dp[N][V%K] == -(1 << 30) || S < V) {
		cout << "NO" << endl;
		return 0;
	}
	
	vector<tuple<int, int, int>>vec;

	if (V%K == 0) {
		for (int i = 2; i <= N; i++) vec.push_back(make_tuple(1000000000, i, 1));
		if (V > 0) vec.push_back(make_tuple(V / K, 1, 2));
	}
	else {
		int cx = V % K, T = 0;
		for (int i = N; i >= 1; i--) {
			if (pre[i][cx] == 1) { used[i] = true; T = i; cx = (cx - (A[i] % K) + K) % K; }
		}
		if (T == 0) { used[1] = true; T = 1; }

		int pr = -1, B1 = A[T], B2 = 0;
		for (int i = 1; i <= N; i++) {
			if (i == T) continue;
			if (used[i] == true) { vec.push_back(make_tuple(1000000000, i, T)); B1 += A[i]; }
			else {
				if (pr == -1) { pr = i; B2 += A[i]; }
				else { vec.push_back(make_tuple(1000000000, i, pr)); B2 += A[i]; }
			}
		}
		if (B2 >= K) { vec.push_back(make_tuple(B2 / K, pr, T)); B1 += (B2 / K) * K; }

		int st = 1; if (T == 1) st = 2;
		if (B1 != V) vec.push_back(make_tuple((B1 - V) / K, T, st));
	}

	cout << "YES" << endl;
	for (int i = 0; i < vec.size(); i++) cout << get<0>(vec[i]) << " " << get<1>(vec[i]) << " " << get<2>(vec[i]) << endl;
	return 0;
}