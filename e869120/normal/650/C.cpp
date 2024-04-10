#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
int H, W, ex[1000000], ey[1000000], cnt, maxx[1000009];
vector<vector<int>>U, V, col; vector<int> x[1000009], y[1000009]; vector<int>X; map<int, vector<pair<int, int>>>M;
vector<vector<vector<pair<int, int>>>>D; vector<pair<int, int>>DD[1000009];
void dfs(int pos1, int pos2) {
	if (col[pos1][pos2] >= 1)return;
	col[pos1][pos2] = cnt; DD[cnt].push_back(make_pair(pos1, pos2)); maxx[cnt] = max(maxx[cnt], max(ex[pos1], ey[pos2]));
	for (pair<int, int>i : D[pos1][pos2]) { dfs(i.first, i.second); }
}
int main() {
	cin >> H >> W; for (int i = 0; i < H; i++) { vector<int>I(W, 0); vector<vector<pair<int, int>>>II(W); D.push_back(II); U.push_back(I); V.push_back(I); col.push_back(I); }
	for (int i = 0; i < H; i++) { for (int j = 0; j < W; j++) { scanf("%d", &U[i][j]); X.push_back(U[i][j]); M[U[i][j]].push_back(make_pair(i, j)); } }
	sort(X.begin(), X.end()); X.erase(unique(X.begin(), X.end()), X.end());
	for (int h = 0; h < X.size(); h++) {
		vector<int>CX, CY; vector<pair<int, int>>Z = M[X[h]];
		for (pair<int, int>i : Z) { CX.push_back(i.first); CY.push_back(i.second); x[i.first].push_back(i.second); y[i.second].push_back(i.first); }
		sort(CX.begin(), CX.end()); CX.erase(unique(CX.begin(), CX.end()), CX.end());
		sort(CY.begin(), CY.end()); CY.erase(unique(CY.begin(), CY.end()), CY.end());
		for (int i : CX) { sort(x[i].begin(), x[i].end()); }
		for (int i : CY) { sort(y[i].begin(), y[i].end()); }
		for (int i : CX) {
			for (int j = 0; j < x[i].size() - 1; j++) { D[i][x[i][j]].push_back(make_pair(i, x[i][j + 1])); D[i][x[i][j + 1]].push_back(make_pair(i, x[i][j])); }
		}
		for (int i : CY) {
			for (int j = 0; j < y[i].size() - 1; j++) { D[y[i][j]][i].push_back(make_pair(y[i][j + 1], i)); D[y[i][j + 1]][i].push_back(make_pair(y[i][j], i)); }
		}
		cnt = 0;
		for (pair<int, int>i : Z) {
			int fx = i.first, fy = i.second;
			if (col[fx][fy] == 0) {
				cnt++; dfs(fx, fy); maxx[cnt]++;
				for (pair<int, int>j : DD[cnt]) { V[j.first][j.second] = maxx[cnt]; ex[j.first] = maxx[cnt]; ey[j.second] = maxx[cnt]; }
			}
		}
		for (int i : CX) { x[i].clear(); }
		for (int i : CY) { y[i].clear(); }
		for (pair<int, int>i : Z) { D[i.first][i.second].clear(); col[i.first][i.second] = 0; }
		for (int i = 1; i <= cnt; i++) { maxx[i] = 0; DD[i].clear(); }
		/*for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) { if (j)cout << " "; cout << V[i][j]; }cout << endl;
		}
		cout << "===================" << endl;*/
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) { if (j)cout << " "; cout << V[i][j]; }cout << endl;
	}
	return 0;
}