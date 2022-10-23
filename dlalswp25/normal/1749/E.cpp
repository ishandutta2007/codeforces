#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pp;

const int INF = 1010101010;

int N, M;
vector<char> A[202020];
vector<int> D[202020];
vector<pii> path[202020];
vector<bool> chk[202020];
char S[202020];

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) {
			A[i].resize(M + 1);
			D[i].resize(M + 1);
			path[i].resize(M + 1);
			chk[i].resize(M + 1);

			for(int j = 1; j <= M; j++) {
				D[i][j] = INF;
				chk[i][j] = false;
			}
		}

		for(int i = 1; i <= N; i++) {
			scanf("%s", S + 1);
			for(int j = 1; j <= M; j++) A[i][j] = S[j];
		}

		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(A[i][j] == '#') {
					for(int d = 0; d < 4; d++) {
						int x = i + dx[d], y = j + dy[d];
						if(x < 1 || x > N || y < 1 || y > M) continue;
						chk[x][y] = true;
					}
				}
			}
		}
		
		priority_queue<pp, vector<pp>, greater<pp>> pq;
		for(int i = 1; i <= N; i++) {
			if(!chk[i][1]) {
				D[i][1] = (A[i][1] != '#');
				pq.emplace(A[i][1] != '#', pii(i, 1));
				path[i][1] = {-1, -1};
			}
		}

		while(pq.size()) {
			int x, y, dist = pq.top().first;
			tie(x, y) = pq.top().second;
			pq.pop();
			if(D[x][y] < dist) continue;

			for(int d = 4; d < 8; d++) {
				int nx = x + dx[d], ny = y + dy[d];
				if(nx < 1 || nx > N || ny < 1 || ny > M || chk[nx][ny]) continue;
				if(D[nx][ny] > dist + (A[nx][ny] != '#')) {
					D[nx][ny] = dist + (A[nx][ny] != '#');
					path[nx][ny] = {x, y};
					pq.emplace(D[nx][ny], pii(nx, ny));
				}
			}
		}

		int ans = INF, x, y;
		for(int i = 1; i <= N; i++) {
			if(ans > D[i][M]) { ans = D[i][M]; x = i; y = M; }
		}
		if(ans == INF) { puts("NO"); continue; }
		while(x != -1) {
			A[x][y] = '#';
			tie(x, y) = path[x][y];
		}
		puts("YES");
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) printf("%c", A[i][j]);
			puts("");
		}
	}
	return 0;
}