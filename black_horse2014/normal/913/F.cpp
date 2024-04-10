#include <bits/stdc++.h>
using namespace std;

const int N = 2200;
const int P = 998244353;

int modExp(int a, int n, int mo) {
	int ret = 1;
	for (; n; n >>= 1, a = 1LL * a * a % mo) if (n & 1) ret = ret * 1LL * a % mo;
	return ret;
}

int ai[N], bi[N], cp[N], dp[N], sum[N][N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, a, b; cin >> n >> a >> b;
	a = a * 1LL * modExp(b, P - 2, P) % P;
	b = (P + 1 - a) % P;
	ai[0] = bi[0] = 1;
	for (int i = 1; i <= n; i++) ai[i] = ai[i - 1] * 1LL * a % P, bi[i] = bi[i - 1] * 1LL * b % P;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j + i <= n; j++) if (i * j == 0) sum[i][j] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j + i <= n; j++) sum[i][j] = (1LL * bi[j] * sum[i - 1][j] + 1LL * ai[i] * sum[i][j - 1]) % P;
		cp[i] = 1;
		for (int j = 1; j < i; j++) cp[i] = (cp[i] + P - 1LL * cp[j] * sum[j][i - j] % P) % P;
		dp[i] = 1LL * i * (i - 1) / 2 % P;
		for (int j = 1; j < i; j++) dp[i] = (dp[i] + 1LL * cp[j] * sum[j][i - j] % P * (((dp[j] + dp[i - j] - 1LL * (i - j) * (i - j - 1) / 2) % P + P) % P)) % P; 
		dp[i] = dp[i] * 1LL * modExp(1 + P - cp[i], P - 2, P) % P;
	}
	cout << dp[n] << endl;
	return 0;
}