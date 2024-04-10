#include <bits/stdc++.h>

using namespace std;

char A[1010][1010];
int N, M;

bool vst[1010][1010];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<int> qx;
queue<int> qy;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);

	bool nr = false, nc = false;

	for(int i = 1; i <= N; i++) {
		int c = 0;
		for(int j = 1; j <= M; j++) {
			if(A[i][j] == '#') {
				if(A[i][j - 1] != '#') c++;
			}
		}

		if(!c) nr = true;
		if(c > 1) { puts("-1"); return 0; }
	}

	for(int j = 1; j <= M; j++) {
		int c = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i][j] == '#') {
				if(A[i - 1][j] != '#') c++;
			}
		}

		if(!c) nc = true;
		if(c > 1) { puts("-1"); return 0; }
	}

	if((nr && !nc) || (nc && !nr)) { puts("-1"); return 0; }

	int ans = 0;

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(vst[i][j]) continue;
			if(A[i][j] == '#') {
				ans++;
				qx.push(i);
				qy.push(j);
				vst[i][j] = true;

				while(qx.size()) {
					int x = qx.front(); qx.pop();
					int y = qy.front(); qy.pop();

					for(int d = 0; d < 4; d++) {
						int nx = x + dx[d], ny = y + dy[d];
						if(vst[nx][ny]) continue;
						if(A[nx][ny] == '#') {
							qx.push(nx);
							qy.push(ny);
							vst[nx][ny] = true;
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;

	return 0;
}