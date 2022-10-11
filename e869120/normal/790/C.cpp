#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[103][103][103][3];
int N, C[103];
string S; vector<int>V[3];

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'V') { C[i] = 0; V[0].push_back(i); }
		else if (S[i] == 'K') { C[i] = 1; V[1].push_back(i); }
		else { C[i] = 2; V[2].push_back(i); }
	}

	for (int i = 0; i < 103; i++) { for (int j = 0; j < 103; j++) { for (int k = 0; k < 103; k++) { dp[i][j][k][0] = (1 << 30); dp[i][j][k][1] = (1 << 30); dp[i][j][k][2] = (1 << 30); } } }
	
	dp[0][0][0][2] = 0;
	for (int i = 0; i <= V[0].size(); i++) {
		for (int j = 0; j <= V[1].size(); j++) {
			for (int k = 0; k <= V[2].size(); k++) {
				for (int l = 0; l < 3; l++) {
					if (dp[i][j][k][l] == (1 << 30)) continue;

					if (i < V[0].size()) {
						int cnt = 0;
						for (int pos = 0; pos < i; pos++) { if (V[0][pos] > V[0][i]) cnt++; }
						for (int pos = 0; pos < j; pos++) { if (V[1][pos] > V[0][i]) cnt++; }
						for (int pos = 0; pos < k; pos++) { if (V[2][pos] > V[0][i]) cnt++; }
						dp[i + 1][j][k][0] = min(dp[i + 1][j][k][0], dp[i][j][k][l] + cnt);
					}
					if (j < V[1].size() && l != 0) {
						int cnt = 0;
						for (int pos = 0; pos < i; pos++) { if (V[0][pos] > V[1][j]) cnt++; }
						for (int pos = 0; pos < j; pos++) { if (V[1][pos] > V[1][j]) cnt++; }
						for (int pos = 0; pos < k; pos++) { if (V[2][pos] > V[1][j]) cnt++; }
						dp[i][j + 1][k][1] = min(dp[i][j + 1][k][1], dp[i][j][k][l] + cnt);
					}
					if (k < V[2].size()) {
						int cnt = 0;
						for (int pos = 0; pos < i; pos++) { if (V[0][pos] > V[2][k]) cnt++; }
						for (int pos = 0; pos < j; pos++) { if (V[1][pos] > V[2][k]) cnt++; }
						for (int pos = 0; pos < k; pos++) { if (V[2][pos] > V[2][k]) cnt++; }
						dp[i][j][k + 1][2] = min(dp[i][j][k + 1][2], dp[i][j][k][l] + cnt);
					}
				}
			}
		}
	}
	int X = V[0].size(), Y = V[1].size(), Z = V[2].size();
	cout << min({ dp[X][Y][Z][0], dp[X][Y][Z][1], dp[X][Y][Z][2] }) << endl;
	return 0;
}