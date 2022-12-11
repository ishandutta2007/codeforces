#include <bits/stdc++.h>

const int mod = 998244353;
const int MAXN = 200010;
typedef long long LL;
int deg[MAXN], fac[MAXN], n, t1, t2;
int main() {
	scanf("%d", &n);
	for (int i = 1; i != n; ++i) {
		scanf("%d%d", &t1, &t2);
		++deg[t1]; ++deg[t2];
	}
	fac[0] = fac[1] = 1;
	for (int i = 2; i <= n; ++i) fac[i] = (LL) fac[i - 1] * i % mod;
	int ans = n;
	for (int i = 1; i <= n; ++i)
		ans = (LL) ans * fac[deg[i]] % mod;
	printf("%d\n", ans);
	return 0;
}