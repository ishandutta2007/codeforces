#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
char x[50][50]; int H, W, K, col[50][50], cnt = 0, g[3000]; vector<pair<int, int>>J;
int main() {
	cin >> H >> W >> K; cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)cin >> x[i][j];
	}
	queue<pair<int, int>>Q;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && x[i][j] == '.') {
				Q.push(make_pair(i, j)); col[i][j] = -1;
			}
		}
	}
	int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
	while (!Q.empty()) {
		int a1 = Q.front().first, a2 = Q.front().second; Q.pop();
		for (int i = 0; i < 4; i++) {
			int cx = a1 + dx[i], cy = a2 + dy[i];
			if (cx < 0 || cy < 0 || cx >= H || cy >= W)continue;
			if (x[cx][cy] == '*' || col[cx][cy] == -1)continue;
			Q.push(make_pair(cx, cy)); col[cx][cy] = -1;
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (col[i][j] != 0 || x[i][j] == '*')continue;
			Q.push(make_pair(i, j)); cnt++; col[i][j] = cnt;
			while (!Q.empty()) {
				int a1 = Q.front().first, a2 = Q.front().second; Q.pop();
				for (int k = 0; k < 4; k++) {
					int cx = a1 + dx[k], cy = a2 + dy[k];
					if (cx < 0 || cy < 0 || cx >= H || cy >= W)continue;
					if (x[cx][cy] == '*' || col[cx][cy] != 0)continue;
					Q.push(make_pair(cx, cy)); col[cx][cy] = cnt;
				}
			}
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) { if (col[i][j] >= 1)g[col[i][j]]++; }
	}
	for (int i = 1; i <= cnt; i++)J.push_back(make_pair(g[i], i));
	sort(J.begin(), J.end());
	int ret = 0;
	for (int i = 0; i < (cnt - K); i++) {
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				if (col[j][k] == J[i].second) { ret++; x[j][k] = '*'; }
			}
		}
	}
	cout << ret << endl;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)cout << x[i][j]; cout << endl;
	}
	return 0;
}