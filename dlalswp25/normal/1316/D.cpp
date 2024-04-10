#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char ch[4] = {'D', 'R', 'U', 'L'};

int N;
char ans[1010][1010];
int X[1010][1010];
int Y[1010][1010];

int cnt[1010][1010];
bool chk[1010][1010];

void die() {
	puts("INVALID"); exit(0);
}

bool inrange(int x, int y) {
	return 1 <= x && x <= N && 1 <= y && y <= N;
}

void dfs(int x, int y, int px, int py) {
	cnt[px][py]--;
	for(int d = 0; d < 4; d++) {
		int nx = x + dx[d], ny = y + dy[d];
		if(!inrange(nx, ny)) continue;
		if(ans[x][y] == ch[d]) continue;
		if(X[nx][ny] != px || Y[nx][ny] != py) continue;
		if(ans[nx][ny]) continue;

		ans[nx][ny] = ch[d + 2 & 3];
		dfs(nx, ny, px, py);
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) scanf("%d%d", &X[i][j], &Y[i][j]);

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(X[i][j] != -1) cnt[X[i][j]][Y[i][j]]++;
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(!cnt[i][j]) continue;
			if(X[i][j] != i || Y[i][j] != j) die();

			ans[i][j] = 'X';
			dfs(i, j, i, j);
			if(cnt[i][j]) die();
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(X[i][j] != -1) continue;
			if(chk[i][j]) continue;

			for(int d = 0; d < 4; d++) {
				int nx = i + dx[d], ny = j + dy[d];
				if(!inrange(nx, ny)) continue;

				if(X[nx][ny] != -1) continue;
				if(chk[nx][ny]) {
					chk[i][j] = true; ans[i][j] = ch[d]; break;
				}
				chk[i][j] = chk[nx][ny] = true;
				ans[i][j] = ch[d];
				ans[nx][ny] = ch[d + 2 & 3];
				break;
			}

			if(!chk[i][j]) die();
		}
	}

	puts("VALID");
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			printf("%c", ans[i][j]);
		}
		puts("");
	}

	return 0;
}