#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M, Q;
char A[1010][1010];

int B[1010][1010];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<int> qx, qy;

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
	for(int i = 1; i <= N; i++) A[i][0] = A[i][M + 1] = '2';
	for(int i = 1; i <= M; i++) A[0][i] = A[N + 1][i] = '2';

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			for(int d = 0; d < 4; d++) {
				int x = i + dx[d], y = j + dy[d];
				if(A[i][j] == A[x][y]) B[i][j] = 1;
			}

			if(B[i][j]) {
				qx.push(i);
				qy.push(j);
			}
		}
	}

	if(qx.size() == 0) {
		while(Q--) {
			int x, y; ll t; scanf("%d%d%lld", &x, &y, &t);
			printf("%c\n", A[x][y]);
		}
		return 0;
	}

	while(qx.size()) {
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();

		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 1 || nx > N || ny < 1 || ny > M) continue;

			if(B[nx][ny]) continue;
			B[nx][ny] = B[x][y] + 1;
			qx.push(nx);
			qy.push(ny);
		}
	}

	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) B[i][j]--;

	// for(int i = 1; i <= N; i++) {
	// 	for(int j = 1; j <= M; j++) {
	// 		printf("%d ", B[i][j]);
	// 	}
	// 	puts("");
	// }

	while(Q--) {
		int x, y;
		ll t;
		scanf("%d%d%lld", &x, &y, &t);
		if(t <= B[x][y]) {
			printf("%c\n", A[x][y]);
		}
		else {
			ll z = (t - B[x][y]) & 1LL;
			if(z) {
				printf("%c\n", '0' + '1' - A[x][y]);
			}
			else printf("%c\n", A[x][y]);
		}
	}

	return 0;
}