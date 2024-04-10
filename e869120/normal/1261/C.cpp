#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = (1 << 20);

int H, W;
vector<char> G[MAX_N];
vector<int> dist[MAX_N];
vector<int> val[MAX_N];
queue<pair<int, int>> Q;

int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };

bool solve(int c) {
	for (int i = 0; i <= H + 1; i++) {
		for (int j = 0; j <= W + 1; j++) val[i][j] = 0;
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (dist[i][j] <= c) continue;
			int lx = i - c; lx = max(lx, 1);
			int rx = i + c; rx = min(rx, H);
			int ly = j - c; ly = max(ly, 1);
			int ry = j + c; ry = min(ry, W);
			val[lx][ly]++;
			val[rx + 1][ry + 1]++;
			val[lx][ry + 1]--;
			val[rx + 1][ly]--;
		}
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) val[i][j] += val[i][j - 1];
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) val[i][j] += val[i - 1][j];
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (val[i][j] == 0 && G[i][j] == 'X') return false;
		}
	}
	return true;
}

int main() {
	cin >> H >> W;
	for (int i = 0; i <= H + 1; i++) {
		G[i].resize(W + 2, '.');
		val[i].resize(W + 2, 0);
		dist[i].resize(W + 2, 0);
	}
	for (int i = 1; i <= H; i++) {
		string str; cin >> str;
		for (int j = 0; j < W; j++) G[i][j + 1] = str[j];
	}

	for (int i = 0; i <= H + 1; i++) {
		for (int j = 0; j <= W + 1; j++) { 
			dist[i][j] = (1 << 30);
			if (G[i][j] == '.') { dist[i][j] = 0; Q.push(make_pair(i, j)); }
		}
	}
	while (!Q.empty()) {
		int px = Q.front().first, py = Q.front().second; Q.pop();
		for (int i = 0; i < 8; i++) {
			int ex = px + dx[i], ey = py + dy[i];
			if (ex >= 1 && ey >= 1 && ex <= H && ey <= W && dist[ex][ey] == (1 << 30)) {
				dist[ex][ey] = dist[px][py] + 1;
				Q.push(make_pair(ex, ey));
			}
		}
	}

	int cl = 0, cr = (1 << 20), cm, maxn = -(1 << 30);
	for (int i = 0; i < 23; i++) {
		cm = (cl + cr) / 2;
		bool I = solve(cm);
		if (I == true) { maxn = max(maxn, cm); cl = cm; }
		else { cr = cm; }
	}

	cout << maxn << endl;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (dist[i][j] > maxn) printf("X");
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}