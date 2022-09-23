#include <bits/stdc++.h>

using namespace std;

int D[55][55][55][55];
int MXX[55][55][55][55];
int MXY[55][55][55][55];
int MNX[55][55][55][55];
int MNY[55][55][55][55];
int N;

char A[55][55];

int f(int x1, int y1, int x2, int y2) {
	if(x1 > x2 || y1 > y2) return 987654321;
	int& ret = D[x1][y1][x2][y2];
	if(ret != -1) return ret;

	int x3 = MNX[x1][y1][x2][y2];
	int x4 = MXX[x1][y1][x2][y2];
	int y3 = MNY[x1][y1][x2][y2];
	int y4 = MXY[x1][y1][x2][y2];

	if(!x4) return ret = 0;

	ret = max(x4 - x3 + 1, y4 - y3 + 1);

	if(x4 - x3 > y4 - y3) {
		for(int i = x3; i < x4; i++) ret = min(ret, f(x1, y1, i, y2) + f(i + 1, y1, x2, y2));
	}
	else {
		for(int i = y3; i < y4; i++) ret = min(ret, f(x1, y1, x2, i) + f(x1, i + 1, x2, y2));
	}
	//printf("%d %d %d %d %d -> %d %d %d %d\n", x1, y1, x2, y2, ret, x3, y3, x4, y4);
	return ret;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			for(int k = i; k <= N; k++) {
				for(int l = j; l <= N; l++) {
					D[i][j][k][l] = -1;
					int t1, t2;
					t1 = (MNX[i][j][k - 1][l] ? MNX[i][j][k - 1][l] : 987654321);
					t2 = (MNX[i][j][k][l - 1] ? MNX[i][j][k][l - 1] : 987654321);
					MNX[i][j][k][l] = min(t1, t2);

					t1 = (MNY[i][j][k - 1][l] ? MNY[i][j][k - 1][l] : 987654321);
					t2 = (MNY[i][j][k][l - 1] ? MNY[i][j][k][l - 1] : 987654321);
					MNY[i][j][k][l] = min(t1, t2);
					
					if(A[k][l] == '#') {
						MXX[i][j][k][l] = k;
						MXY[i][j][k][l] = l;

						MNX[i][j][k][l] = min(MNX[i][j][k][l], k);
						MNY[i][j][k][l] = min(MNY[i][j][k][l], l);
					}
					else {
						MXX[i][j][k][l] = max(MXX[i][j][k - 1][l], MXX[i][j][k][l - 1]);
						MXY[i][j][k][l] = max(MXY[i][j][k - 1][l], MXY[i][j][k][l - 1]);
					}

					//printf("%d %d %d %d %d\n", i, j, k, l, MXX[i][j][k][l]);
				}
			}
		}
	}

	printf("%d\n", f(1, 1, N, N));

	return 0;
}