#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int H, W, a[103][103], sx, sy, dist[103][103]; queue<pair<int, int>>Q;
int main() {
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			char c; cin >> c;
			if (c == '*')a[i][j] = 1;
			if (c == 'F') { sx = i; sy = j; }
		}
	}
	for (int i = 0; i < 102; i++) { for (int j = 0; j < 102; j++)dist[i][j] = 1e9; }
	Q.push(make_pair(1, 1)); dist[1][1] = 0;
	while (!Q.empty()) {
		int a1 = Q.front().first, a2 = Q.front().second; Q.pop();
		int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
		for (int i = 0; i < 4; i++) {
			int cx = a1 + dx[i], cy = a2 + dy[i];
			if (cx <= 0 || cy <= 0 || cx > H || cy > W || a[cx][cy] == 1)continue;
			if (dist[cx][cy] > dist[a1][a2] + 1) {
				dist[cx][cy] = dist[a1][a2] + 1; Q.push(make_pair(cx, cy));
			}
		}
	}
	vector<pair<int, int>>X; int a1 = sx, a2 = sy; X.push_back(make_pair(sx, sy));
	while (a1 >= 2 || a2 >= 2) {
		int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
		for (int i = 0; i < 4; i++) {
			int cx = a1 + dx[i], cy = a2 + dy[i];
			if (cx <= 0 || cy <= 0 || cx > H || cy > W || a[cx][cy] == 1)continue;
			if (dist[cx][cy] == dist[a1][a2] - 1) {
				a1 = cx; a2 = cy; X.push_back(make_pair(a1, a2)); break;
			}
		}
	}
	reverse(X.begin(), X.end()); int p1 = -1, p2 = -1;
	for (int i = 0; i < X.size() - 1; i++) {
		bool OK = false;
		if (X[i].first != X[i + 1].first && p1 == -1) {
			cout << "U" << endl; int px, py; cin >> px >> py;
			if (px == 1)p1 = 0; else p1 = 1, OK = true;
		}
		if (X[i].second != X[i + 1].second && p2 == -1) {
			cout << "L" << endl; int px, py; cin >> px >> py;
			if (py == 1)p2 = 0; else p2 = 1, OK = true;
		}
		if (OK == true)continue;
		if (X[i].first == X[i + 1].first) {
			int G = (X[i].second < X[i + 1].second); G += p2; G %= 2;
			if (G == 0)cout << "L" << endl; else cout << "R" << endl; int px, py; cin >> px >> py;
		}
		else {
			int G = (X[i].first < X[i + 1].first); G += p1; G %= 2;
			if (G == 0)cout << "U" << endl; else cout << "D" << endl; int px, py; cin >> px >> py;
		}
	}
	return 0;
}