#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
char A[505][505];
int B[505][505];
bool vst[505][505];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<pii> adj[505][505];
bool chk[10];

void dfs(int x, int y, int c) {
	if(vst[x][y]) return;
	vst[x][y] = true;
	B[x][y] = c;
	for(auto &i : adj[x][y]) {
		if(vst[i.first][i.second]) continue;
		dfs(i.first, i.second, 5 - c);
	}
}

void add(int x1, int y1, int x2, int y2) {
	adj[x1][y1].emplace_back(x2, y2);
	adj[x2][y2].emplace_back(x1, y1);
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);

	bool ok = true;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(A[i][j] == '.') continue;
			int c = 0;
			for(int d = 0; d < 4; d++) {
				chk[d] = false;
				int x = i + dx[d], y = j + dy[d];
				if(A[x][y] == '.') { chk[d] = true; c++; }
			}
			if(c & 1) ok = false;
			else if(c) {
				int f = -1, bef = 0;
				for(int d = 0; d < 4; d++) {
					if(chk[d]) {
						if(f == -1) f = d;
						else {
							add(i + dx[d], j + dy[d], i + dx[bef], j + dy[bef]);
						}
						bef = d;
					}
				}
				add(i + dx[bef], j + dy[bef], i + dx[f], j + dy[f]);
			}
		}
	}

	if(!ok) { puts("NO"); return 0; }

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(vst[i][j] || A[i][j] == 'X') continue;
			dfs(i, j, 1);
		}
	}

	puts("YES");

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(A[i][j] == 'X') {
				int s = 0;
				for(int d = 0; d < 4; d++) s += B[i + dx[d]][j + dy[d]];
				printf("%d ", s);
			}
			else printf("%d ", B[i][j]);
		}
		puts("");
	}

	return 0;
}