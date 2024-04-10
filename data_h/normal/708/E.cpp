#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int N = 2e3 + 7;
const int MOD = 1e9 + 7;

int n, m, k;
int p;
int f[N], sf[N];

int power(int a, int n) {
	if (n < 0) return 0;
	if (n == 0) return 1;
	if (n & 1) return 1LL * a * power(a, n - 1) % MOD;
	return power(1LL * a * a % MOD, n >> 1);
}

int comb(int a, int b) {
	if (b > a) return 0;
	int ret = 1;
	for (int i = 1; i <= b; i++) {
		ret = 1LL * ret * (a - i + 1) % MOD;
		ret = 1LL * ret * power(i, MOD - 2) % MOD;
	}
	return ret;
}

int l[N][N], r[N][N];


int wl[N], wr[N];
int answer = 0;

void dfs(int dep, int prob) {

	if (dep == n + 1) {
		for (int i = 1; i < n; i++) {
			if (wl[i] + wr[i + 1] >= m || wr[i] + wl[i + 1] >= m) return ;
		}
		(answer += prob) %= MOD;
		return ;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; i + j < m; j++) {
			wl[dep] = i, wr[dep] = j;
			dfs(dep + 1, 1LL * prob * f[i] % MOD * f[j] % MOD);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	{
		int a, b;
		scanf("%d %d", &a, &b);
		p = 1LL * a * power(b, MOD - 2) % MOD;
	}
	scanf("%d", &k);
	for (int i = 0; i <= m; i++) {
		f[i] = 1LL * comb(k, i) * power(p, i) % MOD * power((1 - p + MOD) % MOD, k - i) % MOD;
//		printf("f[%d] = %d\n", i, f[i]);
	}
	sf[0] = f[0];
	for (int i = 1; i <= m; i++) {
		sf[i] = (sf[i - 1] + f[i]) % MOD;
	}

	if (n == 1) {
		for (int l = 0; l <= m; l++) {
			for (int r = 0; l + r < m; r++) {
				answer += 1LL * f[l] * f[r] % MOD;
				answer %= MOD;
			}
		}
		printf("%d\n", answer);
		return 0;
	}


	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			if (i == j) {
				l[1][j] = 1LL * f[i - 1] * sf[m - j] % MOD;
			} else {
				r[1][j] += 1LL * f[i - 1] * sf[m - j] % MOD;
				r[1][j] %= MOD;
			}
		}
	}


	for (int i = 2; i <= n; i++) {
		int tot = 0;
		for (int j = 1; j <= m; j++) {
			r[i][j] += 1LL * tot * sf[m - j] % MOD;
			r[i][j] %= MOD;
			tot += 1LL * (l[i - 1][j] + r[i - 1][j]) % MOD * f[j - 1] % MOD; tot %= MOD;

			l[i][j] += 1LL * (r[i - 1][j] + l[i - 1][j]) % MOD * f[j - 1] % MOD * sf[m - j] % MOD;
			l[i][j] %= MOD;
		}
		tot = 0;
		for (int j = m; j >= 1; j--) {
			l[i][j] += 1LL * tot * f[j - 1] % MOD;
			l[i][j] %= MOD;

			tot += 1LL * l[i - 1][j] * sf[m - j] % MOD;
			tot %= MOD;
		}


		tot = 0;
		for (int j = 2; j <= m; j++) {
			r[i][j] += 1LL * tot * sf[m - j] % MOD; r[i][j] %= MOD;
			tot += 1LL * l[i - 1][j] * sf[j - 2] % MOD; tot %= MOD;
		}
		tot = 0;
		for (int j = m; j >= 2; j--) {
			tot += 1LL * sf[m - j] * l[i - 1][j] % MOD; tot %= MOD;
			r[i][j] += 1LL * tot * sf[j - 2] % MOD; r[i][j] %= MOD;
		}

	}

	for (int i = 1; i <= m; i++) {
		answer += 1LL * l[n][i] % MOD;
		answer %= MOD;
	}
/*
	for (int i = 1; i <= n; i++, printf("\n")) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", l[i][j]);
		}
	}
*/
	printf("%d\n", answer);
	// answer = 0;
	// dfs(1, 1);
	// printf("%d\n", answer);
	return 0;
}