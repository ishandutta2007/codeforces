#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 300010
#define MAXS 15000010
int n, sums[MAXN], hav[MAXS], fac[MAXS], tot, maxn, pri[MAXS / 10], pre[MAXS];
bool npri[MAXS], vis[MAXS];

void sieve() {
	for (int i = 2; i <= maxn; ++i) {
		if (!npri[i]) fac[pri[++tot] = i] = i;
		for (int j = 1; j <= tot; ++j) {
			int t = i * pri[j];
			if (t > maxn) break;
			npri[t] = true; fac[t] = pri[j];
			if (i % pri[j] == 0) break;
		}
	}
}
int li[MAXN], cnt[MAXN], bak;
void dfs(int s, int now, int p) {
	if (s == bak + 1) return (void) (hav[now] += p);
	for (int i = 0; i <= cnt[s]; ++i, now *= li[s]) dfs(s + 1, now, p);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &sums[i]), maxn = max(maxn, sums[i]), ++pre[sums[i]];
	sieve();
	for (int i = 1; i <= n; ++i) {
		int t = sums[i], t2; bak = 0;
		if (vis[t]) continue;
		vis[t] = true;
		while (t != 1) {
			li[++bak] = t2 = fac[t]; cnt[bak] = 0;
			while (t % t2 == 0) ++cnt[bak], t /= t2;
		}
		dfs(1, 1, pre[sums[i]]);
	}
	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= maxn; ++i) 
		if (hav[i] == n) ans = 0x3f3f3f3f;
		else if (hav[i]) ans = min(ans, n - hav[i]);
	if (ans == 0x3f3f3f3f) puts("-1"); else printf("%d\n", ans);
	return 0;
}