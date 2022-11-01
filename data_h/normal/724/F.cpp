#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

const int N = 1e3 + 7;
const int D = 12;

int MOD;

int f[N][D], g[N];
int n, d, rev[N];

int power(int a, int n) {
	int ret = 1;
	for (int i = 1; i <= n; i <<= 1) {
		if (n & i) {
			ret = 1LL * ret * a % MOD;
		}
		a = 1LL * a * a % MOD;
	}
	return ret;
}

void add(int &a, int b) {
	if ((a += b) >= MOD) {
		a -= MOD;
	}
}

int comb(int n, int m) {
	assert(n <= MOD && m <= MOD);
	int ret = 1;
	for (int i = 1; i <= m; i++) {
		ret = 1LL * ret * ((n - i + 1 + MOD) % MOD) % MOD;
		ret = 1LL * ret * rev[i] % MOD;
	}
	return ret;
}

int main() {
	scanf("%d %d %d", &n, &d, &MOD);
	if (n <= 2) {
		printf("1\n");
		return 0;
	}
	rev[0] = 1;
	for (int i = 1; i <= d; i++) {
		rev[i] = power(i, MOD - 2) % MOD;
	}
	f[1][0] = 1;
	for (int i = 1; i <= n / 2; i++) {
		if (i == 1) {
			g[1] = 1;
		} else {
			g[i] = f[i][d - 1];
		}
		if (g[i] == 0) continue;
		if ((i - 1) % (d - 1) != 0) assert(g[i] == 0);
		for (int j = n; j >= 1; j--) {
			for (int k = 0; k <= d; k++) {
				if (f[j][k] == 0) {
					continue;
				}
				for (int l = 1; k + l <= d && j + l * i <= n; l++) {
					add(f[j + l * i][k + l], 1LL * f[j][k] * comb(g[i] + l - 1, l) % MOD);
				}
			}
		}
	}
	int ans = f[n][d];
	//printf("%d\n", f[n / 2][d - 1]);
	if (n % 2 == 0) {
		ans += MOD - comb(f[n / 2][d - 1], 2);
		ans %= MOD;
	}
	printf("%d\n", ans);
	return 0;
}