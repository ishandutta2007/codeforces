#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define MOD 1000000007
#define MX 350 
using namespace std;

int N, M, X;
long long f[MX][MX], g[MX][MX];

main() {
	
	int i, j, k, l, r;
	scanf("%d%d%d", &N, &M, &X);
	if (N > M) {
		puts("0");
		return 0;
	}
	
	f[0][0] = 1;
	for (i = 1; i <= M; i++) {
		for (j = 0; j <= N; j++) {
			for (k = 0; k <= j; k++) {
				if (i != X) {
					g[j][k] = (g[j][k] + f[j][k]) % MOD;
					if (k) g[j][k - 1] = (g[j][k - 1] + f[j][k]) % MOD;
				}
				g[j + 1][k + 1] = (g[j + 1][k + 1] + f[j][k]) % MOD;
				g[j + 1][k] = (g[j + 1][k] + f[j][k]) % MOD;
			}
		}
		for (j = 0; j <= N; j++) for (k = 0; k <= N; k++) f[j][k] = g[j][k], g[j][k] = 0;
	}
	for (i = 1; i <= N; i++) f[N][0] = f[N][0] * i % MOD;
	printf("%I64d\n", f[N][0]);
}