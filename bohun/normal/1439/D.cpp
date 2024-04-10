#include <bits/stdc++.h>
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;

const int N = 600;

int n, m, MOD;
ll C[N][N], f[N], g[N], dpf[N][N], dpg[N][N];

ll q(int n) {
	return n * (n + 1) / 2 % MOD;
}

int main() {
	scanf("%d%d%d", &n, &m, &MOD);
	for (int i = 0; i < N; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	
	f[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int m = 1; m <= i; ++m) {
			f[i] = (f[i] + (i + 1) * C[i - 1][m - 1] % MOD * f[m - 1] % MOD * f[i - m]) % MOD;
			g[i] = (g[i] + (i + 1) * C[i - 1][m - 1] % MOD * (g[m - 1] * f[i - m] % MOD + g[i - m] * f[m - 1] % MOD)) % MOD;
			g[i] = (g[i] + C[i - 1][m - 1] * f[m - 1] % MOD * f[i - m] % MOD * (q(m - 1) + q(i - m))) % MOD;
		} 
		dpf[i][i] = f[i];
		dpg[i][i] = g[i];
		//~ cout << g[i] << " " << f[i] << endl;
	}
	
	dpf[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < i; ++j) 
			for (int k = 0; k <= j; ++k) {
				dpf[i][j] = (dpf[i][j] + C[j][k] * f[k] % MOD * dpf[i - k - 1][j - k]) % MOD;
				dpg[i][j] = (dpg[i][j] + C[j][k] * (f[k] * dpg[i - k - 1][j - k] % MOD + g[k] * dpf[i - k - 1][j - k] % MOD)) % MOD;
			}
	printf("%lld\n", dpg[n][m]);	
	return 0;
}