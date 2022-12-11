#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXS = 100000;
const int MAXN = MAXS + 10;
const int Dollar1 = 1000000007;
int cnt[MAXN], g[MAXN], pri[MAXN], tot, npri[MAXN], mu[MAXN], pows[MAXN];
inline int up(int x) { return x -= Dollar1, x + (x >> 31 & Dollar1); }
inline int down(const int x) { return x + (x >> 31 & Dollar1); }
inline int mul(const int x, const int y) { return static_cast<long long> (x) * y % Dollar1; }
int main() {
	pows[0] = 1;
	for (int i = 1; i != MAXN; ++i) pows[i] = up(pows[i - 1] << 1);
	int n, t;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &t), ++cnt[t];
	for (int i = 1; i <= MAXS; ++i)
		for (int j = i; j <= MAXS; j += i) 
			g[i] += cnt[j];
	mu[1] = 1;
	for (int i = 2; i <= MAXS; ++i) {
		if (!npri[i]) mu[pri[++tot] = i] = -1;
		for (int j = 1; j <= tot; ++j) {
			int t = i * pri[j];
			if (t > MAXS) break;
			npri[t] = true;
			if (i % pri[j] == 0) { mu[t] = 0; break; }
			mu[t] = -mu[i];
		}
	}
	int ans = 0;
	for (int i = 1; i <= MAXS; ++i) if (g[i] && mu[i])
		ans = up(ans + mul(down(mu[i]), down(pows[g[i]] - 1)));
	printf("%d\n", ans);
	return 0;
}