#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int Dollar1 = 1000000007;
const int MAXS = 1000000;
const int MAXN = 1000010;
int pow2[MAXN], pri[MAXN], npri[MAXN], mu[MAXN], phi[MAXN], tot, f[MAXN];
typedef long long LL;
inline int down(const int x) { return x + (x >> 31 & Dollar1); }
inline int mul(const int x, const int y) { return static_cast<LL> (x) * y % Dollar1; }
inline int up(int x) { return x -= Dollar1, x + (x >> 31 & Dollar1); }
void sieve() {
	phi[1] = mu[1] = 1;
	for (int i = 2; i <= MAXS; ++i) {
		if (!npri[i]) pri[++tot] = i, phi[i] = i - 1, mu[i] = -1;
		for (int j = 1; j <= tot; ++j) {
			int t = i * pri[j];
			if (t > MAXS) break;
			npri[t] = true;
			if (i % pri[j] == 0) { mu[t] = 0; phi[t] = phi[i] * pri[j]; break; }
			mu[t] = -mu[i]; phi[t] = phi[i] * (pri[j] - 1);
		}
	}
	for (int i = 1; i <= MAXS; ++i) f[i] = down(phi[i] - mu[i]);
}
int cnt[MAXN], g[MAXN];
int n, t;
int main() {
	sieve();
	pow2[0] = 1;
	for (int i = 1; i != MAXS; ++i) pow2[i] = up(pow2[i - 1] << 1);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t);
		++cnt[t];
	}
	for (int i = 1; i <= MAXS; ++i)
		for (int j = i; j <= MAXS; j += i)
			g[i] += cnt[j];
	int ans = 0;
	for (int i = 1; i <= MAXS; ++i) if (g[i])
		ans = up(ans + mul(f[i], mul(g[i], pow2[g[i] - 1])));
	printf("%d\n", ans);
	return 0;
}