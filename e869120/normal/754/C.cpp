#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int Q, N, M; string S[109], V[109]; int t[109], dp[109][109]; bool u[109][109];
void solve() {
	for (int i = 0; i < 109; i++) { S[i] = ""; V[i] = ""; t[i] = 0; for (int j = 0; j < 109; j++) { dp[i][j] = 0; u[i][j] = false; } }
	cin >> N; for (int i = 0; i < N; i++)cin >> S[i];
	cin >> M;
	for (int i = 0; i < M; i++) {
		string T = "", U; while (T == "")getline(cin, T);
		for (int j = 0; j < T.size(); j++) {
			if (T[j] == ':') {
				string W = T.substr(0, j); t[i] = -1;
				for (int k = 0; k < N; k++) { if (S[k] == W)t[i] = k; }
				U = T.substr(j + 1, T.size() - (j + 1));
			}
		}
		V[i] = U;
		U = " " + U + " ";
		for (int j = 1; j < U.size(); j++) {
			string X = "";
			for (int k = j + 1; k < U.size(); k++) {
				X += U[k - 1];
				if ((U[j - 1] >= 'a' && U[j - 1] <= 'z') || (U[k] >= 'a' && U[k] <= 'z'))continue;
				if ((U[j - 1] >= 'A' && U[j - 1] <= 'Z') || (U[k] >= 'A' && U[k] <= 'Z'))continue;
				if ((U[j - 1] >= '0' && U[j - 1] <= '9') || (U[k] >= '0' && U[k] <= '9'))continue;
				for (int l = 0; l < N; l++) { if (X == S[l]) { u[i][l] = true; } }
			}
		}
	}
	for (int i = 0; i <= M; i++) { for (int j = 0; j <= N; j++)dp[i][j] = -1; }
	dp[0][N] = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j <= N; j++) {
			if (dp[i][j] == -1)continue;
			if (t[i] != -1) {
				if (j != t[i])dp[i + 1][t[i]] = j;
			}
			else {
				for (int k = 0; k < N; k++) {
					if (u[i][k] == true || j == k)continue;
					dp[i + 1][k] = j;
				}
			}
		}
	}
	int cx = -1, cy = M; for (int i = 0; i < N; i++) { if (dp[M][i] >= 0)cx = i; }
	if (cx == -1) { cout << "Impossible" << endl; return; }
	vector<int>s;
	while (cx != N) {
		s.push_back(cx); cx = dp[cy][cx]; cy--;
	}
	reverse(s.begin(), s.end());
	for (int i = 0; i < M; i++) {
		cout << S[s[i]] << ":" << V[i] << endl;
	}
}
int main() {
	cin >> Q;
	for (int i = 0; i < Q; i++)solve();
	return 0;
}