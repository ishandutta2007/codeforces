#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const long long INF = (1LL << 50);

const int N = 30000 + 10, K = 200 + 5;

//               pre nxt ing 
long long f[N][K][2][2][2], sum[N];
// 1 --> 1     -1 ---> 0
int v[N];
int n, C;

__inline void fresh(long long &a, long long b) {
	a = max(a, b);
}

int main() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < K; j++) {
			for(int k = 0; k < 2; k++) {
				for(int l = 0; l < 2; l++) {
					for(int p = 0; p < 2; p++) {
						f[i][j][k][l][p] = -INF;
					}
				}
			}
		}
	}
	scanf("%d %d", &n, &C);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
		sum[i] = sum[i - 1] + v[i];
	}
	f[0][0][0][0][0] = 0;
	f[0][0][0][1][0] = 0;
	for(int k = 0; k < C; k++) {
		for(int i = 0; i <= n; i++) {
			for(int a = 0; a < 2; a++) {
				for(int b = 0; b < 2; b++) {
					for(int c = 0; c < 2; c++) {
						int sign = 0;
						if (k > 0) {
							if (a == 1) {
								sign--;
							} else {
								sign++;
							}
						}
						if (k + 1 < C) {
							if (b == 1) {
								sign++;
							} else {
								sign--;
							}
						}
						long long t = f[i][k][a][b][c];
						if (c == 0) {
							if (i < n) {
								fresh(f[i + 1][k][a][b][0], t);
								fresh(f[i + 1][k][a][b][1], t - sign * sum[i]);
								fresh(f[i + 1][k + 1][b][0][0], t + sign * (sum[i + 1] - sum[i]));
								fresh(f[i + 1][k + 1][b][1][0], t + sign * (sum[i + 1] - sum[i]));
							}
						} else {
							if (i < n) {
								fresh(f[i + 1][k][a][b][1], t);
								fresh(f[i + 1][k + 1][b][0][0], t + sign * sum[i + 1]);
								fresh(f[i + 1][k + 1][b][1][0], t + sign * sum[i + 1]);
							}
						}
					}
				}
			}
		}
	}
	long long answer = -INF;
	for(int i = 1; i <= n; i++) {
		for(int a = 0; a < 2; a++)
			for(int b = 0; b < 2; b++) {
				answer = max(answer, f[i][C][a][b][0]);
			}
	}
	cout << answer << endl;
	return 0;
}