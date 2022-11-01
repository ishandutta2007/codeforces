#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 111;

int n, k;
int p[N];
double f[N][N], g[N][N];

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for(int i = 1; i <= n; i++) {
		f[i][i] = 0;
		for(int j = 1; j <= n; j++) {
			if (i != j) {
				f[i][j] = (p[i] > p[j]);
			}
		}
	}
	/*
	for(int i = 1; i <= n; i++, puts("")) {
		for(int j = 1; j <= n; j++) {
			printf("%f ", f[i][j]);
		}
	}*/

	for(int i = 1; i <= k; i++) {
		memset(g, 0, sizeof(g));
		int total = 0;
		for(int l = 1; l <= n; l++) {
			for(int r = l; r <= n; r++) {
				++total;
			}
		}
		for(int l = 1; l <= n; l++) {
			for(int r = l; r <= n; r++) {
				for(int a = 1; a <= n; a++) {
					for(int b = 1; b <= n; b++) {
						int aa = a;
						if (l <= a && a <= r) {
							aa = (r - (aa - l));
						}
						int bb = b;
						if (l <= b && b <= r) {
							bb = (r - (bb - l));
						}
						if (a != b) {
							g[aa][bb] += f[a][b] * 1. / total;
						}
					}
				}
			}
		}
		for(int a = 1; a <= n; a++) {
			for(int b = 1; b <= n; b++) {
				f[a][b] = g[a][b];
			}
		}

	}
	double answer = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			answer += f[i][j];
		}
	}
	printf("%.12f\n", answer);
	return 0;
}