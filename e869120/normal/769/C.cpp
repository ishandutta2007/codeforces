#include <iostream>
#include <queue>
#include <string>
using namespace std;
int H, W, q, sx, sy; char c[1009][1009]; int dist[1009][1009];
int main() {
	cin >> H >> W >> q;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> c[i][j]; dist[i][j] = 1000000007;
			if (c[i][j] == 'X') { c[i][j] = '.'; sx = i; sy = j; }
		} 
	}
	queue<pair<int, int>>Q; Q.push(make_pair(sx, sy)); dist[sx][sy] = 0;
	while (!Q.empty()) {
		int a1 = Q.front().first, a2 = Q.front().second; Q.pop();
		int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
		for (int i = 0; i < 4; i++) {
			int cx = a1 + dx[i], cy = a2 + dy[i];
			if (cx < 0 || cy < 0 || cx >= H || cy >= W || c[cx][cy] == '*')continue;
			if (dist[cx][cy] > dist[a1][a2] + 1) {
				dist[cx][cy] = dist[a1][a2] + 1; Q.push(make_pair(cx, cy));
			}
		}
	}
	int dy[4] = { 0,-1,1,0 }, dx[4] = { 1,0,0,-1 }; char c[5] = "DLRU";
	string S = "";
	for (int i = q - 1; i >= 0; i--) {
		bool flag = false;
		for (int j = 0; j < 4; j++) {
			int cx = sx + dx[j], cy = sy + dy[j];
			if (cx < 0 || cy < 0 || cx >= H || cy >= W || dist[cx][cy] > i)continue;
			S += c[j]; sx = cx; sy = cy; flag = true; break;
		}
		if (flag == false) { cout << "IMPOSSIBLE" << endl; return 0; }
	}
	cout << S << endl;
	return 0;
}