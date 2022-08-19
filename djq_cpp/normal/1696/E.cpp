#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;
const int M = 400000;

int n, a[200005];
int fac[400005], ifac[400005], inv[400005];
int comb(int a, int b)
{
	return 1ULL * ifac[a] * ifac[b] % MOD * fac[a + b] % MOD;
}

int main()
{
	fac[0] = 1;
	rep1(i, M) fac[i] = 1ULL * fac[i - 1] * i % MOD;
	rep1(i, M) inv[i] = i == 1 ? 1 : MOD - 1ULL * inv[MOD % i] * (MOD / i) % MOD;
	ifac[0] = 1;
	rep1(i, M) ifac[i] = 1ULL * ifac[i - 1] * inv[i] % MOD;
	
	scanf("%d", &n); n ++;
	rep(i, n) scanf("%d", &a[i]);
	int ans = a[0] == 0 ? 0 : MOD - 1;
	rep(i, n) {
		if(a[i] > 0) ans = (ans + comb(i, a[i] - 1)) % MOD;
		for(int j = a[i] - 1; j >= a[i + 1]; j --) ans = (ans + comb(i, j)) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}