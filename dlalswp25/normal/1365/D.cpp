#include <bits/stdc++.h>

using namespace std;

char A[55][55];
int B[55][55];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<int> qx;
queue<int> qy;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N, M; scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
		if(A[N][M] == 'B') { puts("No"); continue; }

		bool ok = true;

		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(A[i][j] != 'B') continue;
				for(int d = 0; d < 4; d++) {
					int x = i + dx[d], y = j + dy[d];
					// printf("%d %d -> %d %d\n", i,j , x, y);
					if(x < 1 || x > N || y < 1 || y > M) continue;
					if(A[x][y] == 'G') ok = false;
					else if(A[x][y] == '.') A[x][y] = '#';
				}
			}
		}

		// for(int i = 1; i <= N; i++) {
		// 	printf("%s\n", A[i] + 1);
		// }

		if(!ok) { puts("No"); continue; }

		while(qx.size()) qx.pop();
		while(qy.size()) qy.pop();

		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) B[i][j] = 0;

		if(A[N][M] != '#') {
			qx.push(N);
			qy.push(M);
			B[N][M] = 1;

			while(qx.size()) {
				int x = qx.front(); qx.pop();
				int y = qy.front(); qy.pop();

				for(int d = 0; d < 4; d++) {
					int nx = x + dx[d], ny = y + dy[d];
					if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
					if(B[nx][ny]) continue;
					if(A[nx][ny] != '#') {
						B[nx][ny] = 1;
						qx.push(nx);
						qy.push(ny);
					}
				}
			}
		}

		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(A[i][j] == 'G' && !B[i][j]) ok = false;
			}
		}
		puts(ok ? "Yes" : "No");
	}
	return 0;
}