#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N, M;

vector<int> A[1010101];
vector<int> B[1010101];
vector<int> D[1010101];
vector<int> E[1010101];
char S[1010101];

queue<int> qx;
queue<int> qy;

bool inrange(int x, int y) {
	return 1 <= x && x <= N && 1 <= y && y <= M;
}

bool solve(int v) {
	while(qx.size()) qx.pop();
	while(qy.size()) qy.pop();

	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) {
		if(A[i][j] && E[i][j] >= v) { B[i][j] = v + 1; qx.push(i); qy.push(j); }
		else B[i][j] = 0;
	}

	// printf("%d\n", v);
	// for(int i = 1; i <= N; i++) {
	// 	for(int j = 1; j <= M; j++) {
	// 		printf("%d ", B[i][j]);
	// 	}
	// 	puts("");
	// }

	while(qx.size()) {
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();
		if(B[x][y] == 1) continue;

		for(int d = 0; d < 8; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if(!inrange(nx, ny)) continue;
			if(B[nx][ny]) continue;
			B[nx][ny] = B[x][y] - 1;
			qx.push(nx);
			qy.push(ny);
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if((B[i][j] > 0) != A[i][j]) return false;
		}
	}
	return true;
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 0; i <= M + 1; i++) {
		A[0].push_back(0);
		A[N + 1].push_back(0);
	}

	for(int i = 1; i <= N; i++) {
		scanf("%s", S + 1);
		for(int j = 0; j <= M + 1; j++) {
			if(S[j] == 'X') A[i].push_back(1);
			else A[i].push_back(0);
			B[i].push_back(0);
			D[i].push_back(0);
			E[i].push_back(0);
		}
	}

	for(int i = 1; i <= M; i++) D[1][i] = A[1][i];
	for(int i = 1; i <= N; i++) D[i][1] = A[i][1];

	for(int i = 2; i <= N; i++) {
		for(int j = 2; j <= M; j++) {
			if(!A[i][j]) continue;

			if(D[i - 1][j] == D[i][j - 1]) {
				int x = D[i - 1][j];
				D[i][j] = x + A[i - x][j - x];
			}
			else {
				D[i][j] = min(D[i - 1][j], D[i][j - 1]) + 1;
			}
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(!A[i][j]) continue;

			int l = 0, r = min(N, M);

			while(l <= r) {
				int m = l + r >> 1;
				int x = i + m, y = j + m;
				if(!inrange(x, y)) { r = m - 1; continue; }
				if(D[x][y] >= 2 * m + 1) l = m + 1;
				else r = m - 1;
			}
			E[i][j] = r;
		}
	}

	int l = 0, r = min(N, M);

	while(l <= r) {
		int m = l + r >> 1;
		if(solve(m)) l = m + 1;
		else r = m - 1;
	}

	printf("%d\n", r);

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(A[i][j] && E[i][j] >= r) printf("X");
			else printf(".");
		}
		puts("");
	}

	return 0;
}