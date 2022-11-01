#include <cstdio>
#include <cstdlib> 
#include <algorithm>
using namespace std;

const int MOD = (int)(1e9 + 7);
const int N = 1111;

long long f[N][N][4], result[N], C[N][N];
int n, kk;

inline void add(long long &a, const long long &b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
}

int main() {
	scanf("%d %d", &n, &kk);
	for(int i = 0; i <= n; i++) {
		C[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	}
	f[0][0][1] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= n; j++) {
			for(int k = 0; k < 4; k++)
				for(int l = 0; l < 4; l++) {
					if ((l >> 1) != (k & 1))
						continue;
					if ((k >> 1)) {
						if (j)
							add(f[i][j][k], f[i - 1][j - 1][l]);
					} else {
						add(f[i][j][k], f[i - 1][j][l]);
						if ((l & 1) == 0 && j)
							add(f[i][j][k], f[i - 1][j - 1][l]);
					}
				}
		}
	for(int i = n; i >= kk; i--) {
		for(int j = 0; j < 2; j++)
			add(result[i], f[n][i][j]);
		for(int j = 1; j <= n - i; j++)
			result[i] = (result[i] * j) % MOD;
		for(int j = n; j > i; j--) {
			add(result[i], (MOD - result[j] * C[j][i] % MOD));
		}
	}
	printf("%I64d\n", result[kk]);
	return 0;
}