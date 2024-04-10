#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 5100;

int f[N][N];

int modExp(int a, int n, int p) {
	int ret = 1;
	for (; n; n >>= 1, a = 1LL * a * a % p) if (n & 1) ret = 1LL * ret * a % p;
	return ret;
}

int main() {

	int n, m; cin >> n >> m;
	f[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= i; j++) {
			f[i][j] = (f[i-1][j-1] + 1LL * f[i-1][j] * j) % MOD;
		}
	}
	int ans = 0, cur = 1, mul = modExp(2, n, MOD), R = (MOD + 1) / 2;
	for (int i = 1; i <= m; i++) {
		cur = 1LL * cur * (n - i + 1) % MOD;
		mul = 1LL * mul * R % MOD;
		ans = (ans + 1LL * f[m][i] * cur % MOD * mul) % MOD;
	}
	cout << (ans % MOD + MOD) % MOD << endl;
	return 0;
}