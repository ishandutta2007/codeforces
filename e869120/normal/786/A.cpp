#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

int N, S1, S2, dp[7009][2], cnts[7009][2]; vector<int>X1, X2;
queue<pair<int, int>>Q;

string str[3] = { "Loop", "Lose", "Win" };

int main() {
	cin >> N;
	cin >> S1; for (int i = 1; i <= S1; i++) { int G; cin >> G; X1.push_back(G); }
	cin >> S2; for (int i = 1; i <= S2; i++) { int G; cin >> G; X2.push_back(G); }

	// 1: Lose, 2: Win
	dp[0][0] = 1; Q.push(make_pair(0, 0));
	dp[0][1] = 1; Q.push(make_pair(0, 1));

	while (!Q.empty()) {
		int p1 = Q.front().first, p2 = Q.front().second; Q.pop();
		
		if (dp[p1][p2] == 1) {
			if (p2 == 1) {
				for (int i = 0; i < X1.size(); i++) {
					int s = (p1 - X1[i] + N) % N;
					if (dp[s][0] == 0) { dp[s][0] = 2; Q.push(make_pair(s, 0)); }
				}
			}
			if (p2 == 0) {
				for (int i = 0; i < X2.size(); i++) {
					int s = (p1 - X2[i] + N) % N;
					if (dp[s][1] == 0) { dp[s][1] = 2; Q.push(make_pair(s, 1)); }
				}
			}
		}
		if (dp[p1][p2] == 2) {
			if (p2 == 1) {
				for (int i = 0; i < X1.size(); i++) {
					int s = (p1 - X1[i] + N) % N; cnts[s][0]++;
					if (dp[s][0] == 0 && cnts[s][0] == X1.size()) { dp[s][0] = 1; Q.push(make_pair(s, 0)); }
				}
			}
			if (p2 == 0) {
				for (int i = 0; i < X2.size(); i++) {
					int s = (p1 - X2[i] + N) % N; cnts[s][1]++;
					if (dp[s][1] == 0 && cnts[s][1] == X2.size()) { dp[s][1] = 1; Q.push(make_pair(s, 1)); }
				}
			}
		}
	}

	for (int i = 1; i < N; i++) { if (i >= 2) cout << " "; cout << str[dp[i][0]]; } cout << endl;
	for (int i = 1; i < N; i++) { if (i >= 2) cout << " "; cout << str[dp[i][1]]; } cout << endl;
	return 0;
}