#include <bits/stdc++.h>

using namespace std;

int ans[55][55];
int N;
int s[55][55];

void ask(int x1, int y1, int x2, int y2) {
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
}

int get() {
	int ret; scanf("%d", &ret);
	if(ret == -1) exit(0);
	return ret;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) ans[i][j] = -1;
	ans[1][1] = 1; ans[N][N] = 0;

	for(int i = 3; i <= N; i += 2) {
		ask(1, i - 2, 1, i);
		int t = get();
		if(t == 1) ans[1][i] = ans[1][i - 2];
		else ans[1][i] = !ans[1][i - 2];
	}
	for(int i = 3; i <= N; i += 2) {
		ask(i - 2, 1, i, 1);
		int t = get();
		if(t == 1) ans[i][1] = ans[i - 2][1];
		else ans[i][1] = !ans[i - 2][1];
	}

	int x = 1, y = 1;
	while(1) {
		x += 1; y += 1;
		if(x >= N || y >= N) break;
		ask(x - 1, y - 1, x, y);
		int t = get();
		if(t == 1) ans[x][y] = ans[x - 1][y - 1];
		else ans[x][y] = !ans[x - 1][y - 1];
	}

	for(int i = 2; i <= N; i++) {
		for(int j = 2; j <= N; j++) {
			if(i == j) continue;
			ask(i - 1, j - 1, i, j);
			s[i][j] = get();
		}
	}

	int sx, sy;

	for(int i = 3; i <= N; i++) {
		if(ans[i][i] == 0 && ans[i - 1][i - 1] == 1 && ans[i - 2][i - 2] == 1) {
			if(s[i - 1][i]) {
				ask(i - 2, i - 2, i - 1, i);
				int t = get();
				ans[i - 2][i - 1] = ans[i - 1][i] = t;
			}
			else {
				ask(i - 2, i - 1, i, i);
				int t = get();
				ans[i - 2][i - 1] = !t; ans[i - 1][i] = t;
			}
			sx = i - 2; sy = i - 1;
			break;
		}
		else if(ans[i][i] == 0 && ans[i - 1][i - 1] == 0 && ans[i - 2][i - 2] == 1) {
			if(s[i - 1][i]) {
				ask(i - 2, i - 1, i, i);
				int t = get();
				ans[i - 2][i - 1] = ans[i - 1][i] = !t;
			}
			else {
				ask(i - 2, i - 2, i - 1, i);
				int t = get();
				ans[i - 2][i - 1] = !t; ans[i - 1][i] = t;
			}
			sx = i - 2; sy = i - 1;
			break;
		}
	}

	x = sx; y = sy;
	while(1) {
		x -= 1; y -= 1;
		if(x < 1) break;
		if(s[x + 1][y + 1]) ans[x][y] = ans[x + 1][y + 1];
		else ans[x][y] = !ans[x + 1][y + 1];
	}

	ask(1, 2, 3, 2);
	int t = get();
	if(t == 1) ans[3][2] = ans[1][2];
	else ans[3][2] = !ans[1][2];

	if(s[3][2]) ans[2][1] = ans[3][2];
	else ans[2][1] = !ans[3][2];

	for(int i = 4; i <= N; i += 2) {
		ask(1, i - 2, 1, i);
		int t = get();
		if(t == 1) ans[1][i] = ans[1][i - 2];
		else ans[1][i] = !ans[1][i - 2];
	}
	for(int i = 4; i <= N; i += 2) {
		ask(i - 2, 1, i, 1);
		int t = get();
		if(t == 1) ans[i][1] = ans[i - 2][1];
		else ans[i][1] = !ans[i - 2][1];
	}

	for(int i = 2; i <= N; i++) {
		for(int j = 2; j <= N; j++) {
			if(i == j) continue;
			if(s[i][j]) ans[i][j] = ans[i - 1][j - 1];
			else ans[i][j] = !ans[i - 1][j - 1];
		}
	}

	printf("!\n");
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			printf("%d", ans[i][j]);
		}
		puts("");
	}
	fflush(stdout);

	return 0;
}