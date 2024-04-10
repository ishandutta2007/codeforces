#include <bits/stdc++.h>

using namespace std;

int X[32] = {0, 1, 4, 1, 16, 1, 4, 1, 64, 1, 4, 1, 16, 1, 4, 1, 256, 1, 4, 1, 16, 1, 4, 1, 64, 1, 4, 1, 16, 1, 4, 1};
int Y[32];
int SX[32];
int SY[32];

int calc(int x1, int y1, int x2, int y2) {
	return SX[x2 - 1] ^ SX[x1 - 1] ^ SY[y2 - 1] ^ SY[y1 - 1];
}

int main() {
	for(int i = 0; i < 32; i++) Y[i] = X[i] * 2;
	for(int i = 1; i < 32; i++) SX[i] = SX[i - 1] ^ X[i];
	for(int i = 1; i < 32; i++) SY[i] = SY[i - 1] ^ Y[i];
	int N, K; scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j < N; j++) printf("%d ", X[j]); puts("");
	}
	for(int i = 1; i < N; i++) {
		for(int j = 1; j <= N; j++) printf("%d ", Y[i]); puts("");
	}
	fflush(stdout);

	int x = 1, y = 1;
	for(int i = 0; i < K; i++) {
		int v; scanf("%d", &v);

		int ansx, ansy;
		for(int j = 1; j <= N; j++) {
			for(int k = 1; k <= N; k++) {
				if(calc(x, y, j, k) == v) {
					ansx = j; ansy = k;
				}
			}
		}
		printf("%d %d\n", ansy, ansx);
		x = ansx; y = ansy;
		fflush(stdout);
	}
	return 0;
}