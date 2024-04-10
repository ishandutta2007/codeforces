#include<iostream>
#include<algorithm>
#include<tuple>
#include<queue>
using namespace std;
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int dp[1004][1004][4], H, W, gx, gy, x[1004][1004];
queue<tuple<int, int, int>>Q;
int main() {
	cin >> H >> W;
	for (int i = 0; i < 1004; i++) { for (int j = 0; j < 1004; j++) { x[i][j] = 1; for (int k = 0; k < 4; k++)dp[i][j][k] = 999999999; } }
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			char c; cin >> c;
			if (c == 'S') { for (int k = 0; k < 4; k++) { dp[i][j][k] = 0; Q.push(make_tuple(i, j, k)); } x[i][j] = 0; }
			if (c == 'T') { gx = i; gy = j; x[i][j] = 0; }
			if (c == '.') { x[i][j] = 0; }
		}
	}
	while (!Q.empty()) {
		int a1 = get<0>(Q.front()), a2 = get<1>(Q.front()), a3 = get<2>(Q.front()); Q.pop();
		for (int i = 0; i < 4; i++) {
			int cx = a1 + dx[i], cy = a2 + dy[i], C = 1;
			if (a3 == i)C = 0;
			if (x[cx][cy] == 0 && dp[cx][cy][i] > dp[a1][a2][a3] + C) {
				dp[cx][cy][i] = dp[a1][a2][a3] + C;
				Q.push(make_tuple(cx, cy, i));
			}
		}
	}
	int minx = 99999999; for (int i = 0; i < 4; i++)minx = min(minx, dp[gx][gy][i]);
	if (minx <= 2)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}