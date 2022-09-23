#include <bits/stdc++.h>

using namespace std;

int D[50][1010][1010];
int A[1010][1010];
int N, M, K, Q;

bool vst[1010][1010];
bool chk[50];
queue<int> qx;
queue<int> qy;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> cx[50];
vector<int> cy[50];

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) {
		scanf("%d", &A[i][j]);
		cx[A[i][j]].push_back(i);
		cy[A[i][j]].push_back(j);
	}

	for(int k = 1; k <= K; k++) {
		for(int i = 1; i <= K; i++) chk[i] = false;
		chk[k] = true;
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) vst[i][j] = false;
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) {
			if(A[i][j] == k) {
				qx.push(i);
				qy.push(j);
				vst[i][j] = true;
			}
		}

		while(qx.size()) {
			int x = qx.front(); qx.pop();
			int y = qy.front(); qy.pop();
			int c = A[x][y];

			if(!chk[c]) {
				chk[c] = true;
				for(int i = 0; i < cx[c].size(); i++) {
					int tx = cx[c][i], ty = cy[c][i];
					if(!vst[tx][ty]) {
						// printf("%d / %d %d -> %d %d\n", k, x, y, tx, ty);
						D[k][tx][ty] = D[k][x][y] + 1;
						vst[tx][ty] = true;
						qx.push(tx);
						qy.push(ty);
					}
				}
			}

			for(int d = 0; d < 4; d++) {
				int nx = x + dx[d], ny = y + dy[d];
				if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
				if(chk[A[nx][ny]]) continue;
				if(vst[nx][ny]) continue;
				// printf("%d / %d %d -> %d %d\n", k, x, y, nx, ny);
				D[k][nx][ny] = D[k][x][y] + 1;
				vst[nx][ny] = true;
				qx.push(nx);
				qy.push(ny);
			}
		}
	}

	// for(int i = 1; i <= N; i++) {
	// 	for(int j = 1; j <= M; j++) printf("%d ", D[1][i][j]); puts("");
	// }

	scanf("%d", &Q);
	while(Q--) {
		int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int ans = abs(x1 - x2) + abs(y1 - y2);
		for(int i = 1; i <= K; i++) {
			ans = min(ans, D[i][x1][y1] + D[i][x2][y2] + 1);
			// printf("%d %d\n", i, ans);
		}
		printf("%d\n", ans);
	}

	return 0;
}