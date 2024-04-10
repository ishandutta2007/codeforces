#include <bits/stdc++.h>
using namespace std;

const int M = 110000;

const int N = 330;
deque<int> F[N][N], T[N][N];
char str[M];
int d[N][N];

vector<int> V[2];

vector<pair<int, int>> ans;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%s", str);
			int l = strlen(str);
			for (int k = 0; k < l; k++) {
				F[i][j].push_back(str[k] - '0');
			}
			d[i][j] = l;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%s", str);
			int l = strlen(str);
			for (int k = 0; k < l; k++) {
				T[i][j].push_back(str[k] - '0');
			}
		}
	}
	for (int i = 2; i < n; i++) {
		for (int j = 0; j < m; j++) {
			while (F[i][j].size()) {
				int ba = F[i][j].back();
				F[i][j].pop_back();
				F[ba][j].push_front(ba);
				ans.emplace_back(i, j);
				ans.emplace_back(ba, j);
			}
		}
	}
	for (int i : {0, 1}) {
		for (int j = 0; j < m; j++) {
			for (int t = 0; t < d[i][j]; t++) {
				int ba = F[i][j].back();
				F[i][j].pop_back();
				ans.emplace_back(i, j);
				if (ba == i) {
					F[i][(j+1)%m].push_front(ba);
					ans.emplace_back(i, (j+1)%m);
				} else {
					F[ba][j].push_front(ba);
					ans.emplace_back(ba, j);
				}
			}
		}
	}
	for (int i : {0, 1}) {
		for (int j = 0; j < m; j++) {
			for (int x : F[i][j]) {
				assert(x == i);
				V[i].push_back(j);
			}
		}
	}
	for (int i = 2; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (auto it = T[i][j].rbegin(); it != T[i][j].rend(); it++) {
				int x = *it;
				int k = V[x].back();
				V[x].pop_back();
				if (k == j) {
					F[x][j].pop_back();
					F[i][j].push_front(x);
					ans.emplace_back(x, j);
					ans.emplace_back(i, j);
				} else {
					F[x][k].pop_back();
					F[x][j].push_front(x);
					ans.emplace_back(x, k);
					ans.emplace_back(x, j);
					F[x][j].pop_back();
					F[i][j].push_front(x);
					ans.emplace_back(x, j);
					ans.emplace_back(i, j);
				}
			}
		}
	}
	for (int i : {0, 1}) {
		for (int j = 0; j < m; j++) {
			if (i != j) {
				while (F[i][j].size()) {
					F[i][j].pop_back();
					F[i][i].push_front(i);
					ans.emplace_back(i, j);
					ans.emplace_back(i, i);
				}
			}
		}
	}
	for (int i : {0, 1}) {
		for (int j = 2; j < m; j++) {
			for (auto it = T[i][j].rbegin(); it != T[i][j].rend(); it++) {
				int x = *it;
				if (x == i) {
					F[i][i].pop_back();
					F[i][j].push_front(i);
					ans.emplace_back(i, i);
					ans.emplace_back(i, j);
				} else {
					F[x][x].pop_back();
					F[i][x].push_front(x);
					ans.emplace_back(x, x);
					ans.emplace_back(i, x);
					F[i][x].pop_back();
					F[i][j].push_front(x);
					ans.emplace_back(i, x);
					ans.emplace_back(i, j);
				}
			}
		}
	}
	int cnt[2] = {0};
	for (int x : T[0][0]) cnt[x]++;
	for (int x : T[1][1]) cnt[x]++;
	for (int i : {0, 1}) {
		for (int t = 0; t < cnt[i]; t++) {
			F[i][i].pop_back();
			F[i][!i].push_front(i);
			ans.emplace_back(i, i);
			ans.emplace_back(i, !i);
		}
	}
	for (int i : {0, 1}) {
		for (auto it = T[i][!i].rbegin(); it != T[i][!i].rend(); it++) {
			int x = *it;
			F[x][x].pop_back();
			F[i][!i].push_front(x);
			ans.emplace_back(x, x);
			ans.emplace_back(i, !i);
		}
	}
	for (int i : {0, 1}) {
		for (auto it = T[i][i].rbegin(); it != T[i][i].rend(); it++) {
			int x = *it;
			F[x][!x].pop_back();
			F[i][i].push_front(x);
			ans.emplace_back(x, !x);
			ans.emplace_back(i, i);
		}
	}
	printf("%d\n", ans.size() / 2);
	for (int i = 0; i < ans.size(); i+=2) {
		int a = ans[i].first, b = ans[i].second, c = ans[i+1].first, d = ans[i+1].second;
		printf("%d %d %d %d\n", a+1, b+1, c+1, d+1);
	}
}