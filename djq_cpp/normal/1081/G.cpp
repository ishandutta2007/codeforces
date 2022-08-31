#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define rep1(i, n) for(int i = 1; i <= (n); i ++)

typedef long long LL;
typedef pair<int, int> PII;
int MOD;

int inv[200005];
void gen_inv(int maxa)
{
	inv[1] = 1;
	for(int i = 2; i <= maxa; i ++) inv[i] = MOD - 1LL * inv[MOD % i] * (MOD / i) % MOD;
}

int getans(int u, int v)
{
	int ans = 0;
	for(int i = 2; i <= u + v; i ++)
	ans = (ans + 1LL * (min(u, i - 1) - max(1, i - v) + 1) * inv[i]) % MOD;
	return ans;
}

int main()
{
	int n, k;
	scanf("%d%d%d", &n, &k, &MOD);
	k --;
	gen_inv(2 * n);
	int ans = 1LL * n * (n - 1) / 2 % MOD * inv[2] % MOD;
	if(k <= 20 && (n >> k)) {
		int c0 = n >> k, c1 = c0 + 1;
		int tot1 = n & (1 << k) - 1, tot0 = (1 << k) - tot1;
		ans = (ans - 1LL * tot0 * (tot0 - 1) / 2 % MOD * getans(c0, c0) % MOD + MOD) % MOD;
		ans = (ans - 1LL * tot1 * (tot1 - 1) / 2 % MOD * getans(c1, c1) % MOD + MOD) % MOD;
		ans = (ans - 1LL * tot0 * tot1 % MOD * getans(c0, c1) % MOD + MOD) % MOD;
	} else ans = 0;
	printf("%d\n", ans);
	return 0;
}