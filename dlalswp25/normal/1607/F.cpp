#include <bits/stdc++.h>

using namespace std;

int N, M;
char A[2020][2020];
int ans[2020][2020];
int dep[2020][2020];
bool vst[2020][2020];
bool fin[2020][2020];
char cvt[130];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cyc, cycX, cycY;

int f(short x, short y) {
	if(vst[x][y]) return ans[x][y];
	vst[x][y] = true;
	int nx = x + dx[cvt[A[x][y]]], ny = y + dy[cvt[A[x][y]]];
	if(nx < 1 || nx > N || ny < 1 || ny > M) {
		fin[x][y] = true;
		return ans[x][y] = 1;
	}
	if(vst[nx][ny] && !fin[nx][ny]) {
		cyc = dep[x][y] - dep[nx][ny] + 1;
		cycX = nx; cycY = ny;
		fin[x][y] = true;
		return ans[x][y] = cyc;
	}
	int t;
	if(vst[nx][ny]) t = ans[nx][ny];
	else {
		dep[nx][ny] = dep[x][y] + 1;
		t = f(nx, ny);
	}
	fin[x][y] = true;
	if(cyc) ans[x][y] = cyc;
	else ans[x][y] = t + 1;
	if(cyc && cycX == x && cycY == y) cyc = 0;
	return ans[x][y];
}

int main() {
	cvt['D'] = 0; cvt['R'] = 1; cvt['U'] = 2; cvt['L'] = 3;
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) vst[i][j] = fin[i][j] = false;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				cyc = 0;
				if(!vst[i][j]) {
					dep[i][j] = 1;
					f(i, j);
				}
			}
		}
		int ansX, ansY, mx = 0;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(mx < ans[i][j]) { mx = ans[i][j]; ansX = i; ansY = j; }
			}
		}
		printf("%d %d %d\n", ansX, ansY, mx);
	}
	return 0;
}