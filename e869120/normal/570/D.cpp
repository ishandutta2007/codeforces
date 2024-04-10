#include<iostream>
#include<vector>
#include<string>
using namespace std;
#pragma warning(disable:4996)
vector<int>x[500009]; int n, m, p[500009], depth[500009], ans[500009], bit[26][500009], lc[500009], rc[500009], cnt = 1; string S;
vector<pair<int, int>>c[500009]; vector<int>X[500009];

void dfs(int pos, int dep) {
	depth[pos] = dep; lc[pos] = cnt; cnt++;
	for (int i = 0; i < x[pos].size(); i++)dfs(x[pos][i], dep + 1);
	rc[pos] = cnt;
}
void add(int ty, int p, int x) {
	while (p <= 500000) { bit[ty][p] += x; p += (p&-p); }
}
int sum(int ty, int p) {
	int s = 0;
	while (p >= 1) { s += bit[ty][p]; p -= (p&-p); }
	return s;
}
int main() {
	cin >> n >> m;
	for (int i = 2; i <= n; i++) { scanf("%d", &p[i]); x[p[i]].push_back(i); }
	cin >> S; S = "-" + S;
	for (int i = 1; i <= m; i++) { int a, b; scanf("%d%d", &a, &b); b--; c[b].push_back(make_pair(a, i)); }
	dfs(1, 0); for (int i = 1; i <= n; i++) { X[depth[i]].push_back(i); }
	for (int i = 0; i <= 500000; i++) {
		for (int j : X[i])add(S[j] - 'a', lc[j], 1);
		for (pair<int, int>j : c[i]) {
			int F = 0;
			for (int k = 0; k < 26; k++) {
				int G = sum(k, rc[j.first] - 1) - sum(k, lc[j.first] - 1);
				if (G % 2 == 1)F++;
			}
			if (F <= 1)ans[j.second] = 1;
		}
		for (int j : X[i])add(S[j] - 'a', lc[j], -1);
	}
	for (int i = 1; i <= m; i++) { if (ans[i] == 1)printf("Yes\n"); else printf("No\n"); }
	return 0;
}