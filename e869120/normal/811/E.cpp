#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning (disable: 4996)

int H, W, Q, c[19][100009], V1[100009], V2[100009], col[19][100009], cnts, L[1000009], R[1000009];

void init() {
	for (int i = 1; i <= H - 1; i++) {
		for (int j = 1; j <= W; j++) { if (c[i][j] == c[i + 1][j]) V1[j]++; }
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W - 1; j++) { if (c[i][j] == c[i][j + 1]) V2[j]++; }
	}
	for (int i = 1; i <= W; i++) { V1[i] += V1[i - 1]; V2[i] += V2[i - 1]; }
}
int getans(int LL, int RR) {
	return ((RR - LL + 1)*H) - ((V1[RR] - V1[LL - 1]) + (V2[RR - 1] - V2[LL - 1]));
}

void dfs(int cx, int cy) {
	if (col[cx][cy] >= 1) return;
	col[cx][cy] = cnts; L[cnts] = min(L[cnts], cy); R[cnts] = max(R[cnts], cy);
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };

	for (int i = 0; i < 4; i++) {
		int fx = cx + dx[i], fy = cy + dy[i];
		if (fx <= 0 || fy <= 0 || fx > H || fy > W || c[cx][cy] != c[fx][fy]) continue;
		dfs(fx, fy);
	}
}

bool used[29][100009], used2[29][200009]; int AL = 0, AR = 0, ML = 0, MR = 0, col2[29][200009], cntw;
vector<int>K[100009]; vector<pair<int, int>>T[100009];

void dfs2(int cx, int cy) {
	if (col2[cx][cy] >= 1) return;
	col2[cx][cy] = cntw; ML = min(ML, cy); MR = max(MR, cy);
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };

	for (int i = 0; i < 4; i++) {
		int fx = cx + dx[i], fy = cy + dy[i];
		if (fx <= 1 || fy < AL * 2 || fx > H * 2 || fy > AR * 2 || used[fx][fy] == true || used2[fx][fy] == true) continue;
		dfs2(fx, fy);
	}
}

void solve(int num) {
	for (int i = 2; i <= 2 * H; i++) {
		for (int j = L[num] * 2; j <= R[num] * 2; j++) { used[i][j] = false; used2[i][j] = false; col2[i][j] = 0; }
	}
	for (int i = 1; i <= H; i++) {
		for (int j = L[num]; j <= R[num]; j++) {
			if (col[i][j] == num) used[i * 2][j * 2] = true;
			if (col[i][j] == num && col[i + 1][j] == num) used[i * 2 + 1][j * 2] = true;
			if (col[i][j] == num && col[i][j + 1] == num) used[i * 2][j * 2 + 1] = true;
		}
	}
	queue<pair<int, int>>Q;
	for (int i = L[num] * 2; i <= R[num] * 2; i++) {
		if (used[1 * 2][i] == false) { Q.push(make_pair(1 * 2, i)); used2[1 * 2][i] = true; }
		if (used[H * 2][i] == false) { Q.push(make_pair(H * 2, i)); used2[H * 2][i] = true; }
	}
	for (int i = 1 * 2; i <= H * 2; i++) {
		if (used[i][L[num] * 2] == false) { Q.push(make_pair(i, L[num] * 2)); used2[i][L[num] * 2] = true; }
		if (used[i][R[num] * 2] == false) { Q.push(make_pair(i, R[num] * 2)); used2[i][R[num] * 2] = true; }
	}

	while (!Q.empty()) {
		int cx = Q.front().first, cy = Q.front().second; Q.pop();
		int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
		for (int i = 0; i < 4; i++) {
			int fx = cx + dx[i], fy = cy + dy[i];
			if (fx <= 1 || fy < L[num] * 2 || fx > H * 2 || fy > R[num] * 2 || used[fx][fy] == true || used2[fx][fy] == true) continue;
			Q.push(make_pair(fx, fy)); used2[fx][fy] = true;
		}
	}

	AL = L[num]; AR = R[num]; cntw = 0;
	for (int i = 1 * 2; i <= H * 2; i++) {
		for (int j = L[num] * 2; j <= R[num] * 2; j++) {
			if (col2[i][j] == 0 && used[i][j] == false && used2[i][j] == false) {
				ML = (1 << 30); MR = -(1 << 30); cntw++; dfs2(i, j);
				K[ML / 2].push_back((MR + 1) / 2);
			}
		}
	}
}

int bit[100009];

void add(int pos, int x) {
	while (pos <= 100008) { bit[pos] += x; pos += (pos&-pos); }
}
int sum(int pos) {
	int s = 0;
	while (pos >= 1) { s += bit[pos]; pos -= (pos&-pos); }
	return s;
}

int ans[100009];

int main() {
	cin >> H >> W >> Q;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) scanf("%d", &c[i][j]);
	}
	init();
	for (int i = 0; i <= 1000000; i++) { L[i] = 1000000; R[i] = -1000000; }
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) { if (col[i][j] == 0) { cnts++; dfs(i, j); } }
	}
	for (int i = 1; i <= cnts; i++) {
		solve(i);
	}
	for (int i = 1; i <= Q; i++) {
		int l, r; scanf("%d%d", &l, &r);
		T[l].push_back(make_pair(r, i));
	}
	for (int i = W; i >= 1; i--) {
		for (int j = 0; j < K[i].size(); j++) add(K[i][j], 1);
		for (int j = 0; j < T[i].size(); j++) {
			ans[T[i][j].second] = sum(T[i][j].first);
			ans[T[i][j].second] += getans(i, T[i][j].first);
		}
	}
	for (int i = 1; i <= Q; i++) printf("%d\n", ans[i]);
	return 0;
}