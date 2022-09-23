#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<char> A[1010101];
vector<int> B[1010101];
char S[1010101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) {
			A[i].resize(M + 1);
			B[i].resize(M + 1);
		}

		int sx, sy;
		for(int i = 1; i <= N; i++) {
			scanf("%s", S + 1);
			for(int j = 1; j <= M; j++) {
				A[i][j] = S[j];
				if(A[i][j] == 'L') { sx = i; sy = j; }
			}
			for(int j = 1; j <= M; j++) B[i][j] = 0;
		}

		queue<int> qx, qy;

		B[sx][sy] = 1;
		qx.push(sx); qy.push(sy);

		while(qx.size()) {
			int x = qx.front(); qx.pop();
			int y = qy.front(); qy.pop();
			for(int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
				if(B[nx][ny] || A[nx][ny] == '#') continue;
				int cnt = 0;
				for(int j = 0; j < 4; j++) {
					int tx = nx + dx[j], ty = ny + dy[j];
					if(tx < 1 || tx > N || ty < 1 || ty > M) continue;
					if(A[tx][ty] == '.' && !B[tx][ty]) cnt++;
				}
				if(cnt <= 1) {
					B[nx][ny] = 1;
					qx.push(nx);
					qy.push(ny);
				}
			}
		}

		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(A[i][j] == '.' && B[i][j]) printf("+");
				else printf("%c", A[i][j]);
			}
			puts("");
		}
	}
	return 0;
}