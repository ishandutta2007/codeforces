#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, pii> pp;

const ll INF = 1LL << 60;

int N, M, P, Q;
vector<char> A[303030];
vector<ll> D[303030];
char B[303030];

int dx[8] = {1, 1, -1, -1, 2, 0, -2, 0};
int dy[8] = {1, -1, 1, -1, 0, 2, 0, -2};

int main() {
	scanf("%d%d%d%d", &N, &M, &P, &Q);
	for(int i = 1; i <= N; i++) {
		A[i].resize(M + 1);
		D[i].resize(M + 1);
		scanf("%s", B + 1);
		for(int j = 1; j <= M; j++) A[i][j] = B[j];
		for(int j = 1; j <= M; j++) D[i][j] = INF;
	}

	priority_queue<pp, vector<pp>, greater<pp>> pq;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(A[i][j] == '.') {
				D[i][j] = 0;
				pq.emplace(0, pii(i, j));
			}
		}
	}
	while(pq.size()) {
		int x, y; ll d = pq.top().first;
		tie(x, y) = pq.top().second;
		pq.pop();
		if(D[x][y] < d) continue;

		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
			char c = A[nx][ny];
			bool chkx, chky;
			if(dx[i] == 1) chkx = (c == 'D');
			else chkx = (c == 'U');
			if(dy[i] == 1) chky = (c == 'R');
			else chky = (c == 'L');
			if(!chkx && !chky) continue;
			if(D[nx][ny] > d + P) {
				D[nx][ny] = d + P;
				pq.emplace(D[nx][ny], pii(nx, ny));
			}
		}
		for(int i = 4; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
			char c = A[nx][ny];
			bool chk;
			if(dx[i] == 2) chk = (c == 'D');
			else if(dx[i] == -2) chk = (c == 'U');
			else if(dy[i] == 2) chk = (c == 'R');
			else chk = (c == 'L');
			if(!chk) continue;
			if(D[nx][ny] > d + Q) {
				D[nx][ny] = d + Q;
				pq.emplace(D[nx][ny], pii(nx, ny));
			}
		}
	}

	ll ans = INF;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(i < N) ans = min(ans, D[i][j] + D[i + 1][j]);
			if(j < M) ans = min(ans, D[i][j] + D[i][j + 1]);
		}
	}
	printf("%lld\n", ans == INF ? -1 : ans);
	return 0;
}