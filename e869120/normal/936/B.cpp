#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, S, dp[100009][2], nex[100009][2], dist[100009]; vector<int>X[100009], R[100009];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int G; cin >> G;
		for (int j = 0; j < G; j++) { int F; cin >> F; X[i].push_back(F); R[F].push_back(i); }
	}
	cin >> S;
	queue<pair<int, int>>Q;
	for (int i = 1; i <= N; i++) {
		if (X[i].size() == 0) { dp[i][0] = 1; Q.push(make_pair(i, 0)); }
	}
	while (!Q.empty()) {
		int pos1 = Q.front().first, pos2 = Q.front().second; Q.pop();
		for (int i : R[pos1]) {
			if (dp[i][pos2 ^ 1] == 0) {
				dp[i][pos2 ^ 1] = 1; nex[i][pos2 ^ 1] = pos1;
				Q.push(make_pair(i, pos2 ^ 1));
			}
		}
	}
	for (int i = 0; i < 100009; i++) dist[i] = -(1 << 30);
	dist[S] = 0;

	queue<int>que; que.push(S);
	int itrs = 0;
	while (!que.empty()) {
		int pos = que.front(); que.pop();
		for (int i : X[pos]) {
			itrs++;
			if (dist[i] < dist[pos] + 1) {
				dist[i] = dist[pos] + 1; que.push(i);
			}
		}
		if (itrs >= 20000000) break;
	}
	if (dp[S][1] == 1) {
		cout << "Win" << endl;
		vector<int>D; int cx = S, cy = 1; D.push_back(cx);
		while (nex[cx][cy] != 0) {
			cx = nex[cx][cy]; cy ^= 1;
			D.push_back(cx);
		}
		for (int i = 0; i < D.size(); i++) { if (i)cout << " "; cout << D[i]; } cout << endl;
	}
	else if (itrs >= 20000000) {
		cout << "Draw" << endl;
	}
	else {
		cout << "Lose" << endl;
	}
	return 0;
}