#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char c[509][509];
int N, K, col[509][509], F[250009], G[250009], cnts;

void dfs(int px, int py) {
	if (col[px][py] >= 1) return;
	col[px][py] = cnts; F[cnts]++;

	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
	for (int i = 0; i < 4; i++) {
		int cx = px + dx[i], cy = py + dy[i];
		if (cx <= 0 || cy <= 0 || cx > N || cy > N || c[cx][cy] == 'X') continue;
		dfs(cx, cy);
	}
}

bool used[509][509]; vector<int>vec;

void putv(int px, int py) {
	if (used[px][py] == false && col[px][py] >= 1) {
		vec.push_back(col[px][py]); used[px][py] = true;
	}
}
void delv(int px, int py) {
	used[px][py] = false;
}

int solve(int px, int py) {
	vec.clear();
	for (int i = px; i < px + K; i++) putv(i, py - 1);
	for (int i = px; i < px + K; i++) putv(i, py + K);
	for (int i = py; i < py + K; i++) putv(px - 1, i);
	for (int i = py; i < py + K; i++) putv(px + K, i);

	sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = px; i < px + K; i++) { delv(i, py - 1); delv(i, py + K); }
	for (int i = py; i < py + K; i++) { delv(px - 1, i); delv(px + K, i); }

	int sum = 0; for (int i = 0; i < vec.size(); i++) sum += F[vec[i]];
	return sum;
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> c[i][j];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (col[i][j] == 0 && c[i][j]=='.') { cnts++; dfs(i, j); }
		}
	}
	int maxn = 0;
	for (int i = 1; i <= cnts; i++) { maxn = max(maxn, F[i]); G[i] = F[i]; }

	for (int i = 1; i <= N - K + 1; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < K - 1; k++) F[col[j + i][k + 1]]--;
		}
		for (int j = 1; j <= N - K + 1; j++) {
			for (int k = 0; k < K; k++) F[col[k + i][j + K - 1]]--;

			int E = solve(i, j); maxn = max(maxn, E + K * K);

			for (int k = 0; k < K; k++) F[col[k + i][j]]++;
		}
		for (int j = 1; j <= cnts; j++) F[j] = G[j];
	}
	cout << maxn << endl;
	return 0;
}