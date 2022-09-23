#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
char A[2020][2020];
int B[2020][2020];
int D[2020][2020];

queue<int> qx;
queue<int> qy;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

ll ans;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) {
		scanf("%s", A[i] + 1);
	}

	ans = N * M;
	for(int i = 2; i < N; i++) {
		for(int j = 2; j < M; j++) {
			B[i][j] = 1;
			for(int d = 0; d < 4; d++) {
				if(A[i][j] != A[i + dx[d]][j + dy[d]]) B[i][j] = 0;
			}
		}
	}

	// for(int i = 1; i <= N; i++) {
	// 	for(int j = 1; j <= M; j++) printf("%d ", B[i][j]); puts("");
	// }

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(B[i][j]) {
				int c = 0;
				for(int d = 0; d < 4; d++) {
					c += B[i + dx[d]][j + dy[d]];
				}

				if(c < 4) {
					D[i][j] = 1;
					qx.push(i);
					qy.push(j);
				}
			}
		}
	}

	while(qx.size()) {
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();

		// printf("%d %d\n", x, y);
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(!B[nx][ny] || D[nx][ny]) continue;
			D[nx][ny] = D[x][y] + 1;
			qx.push(nx);
			qy.push(ny);
		}
	}

	// for(int i = 1; i <= N; i++) {
	// 	for(int j = 1; j <= M; j++) printf("%d ", D[i][j]); puts("");
	// }

	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) ans += D[i][j];
	printf("%lld\n", ans);

	return 0;
}