#include <bits/stdc++.h>

const int LIM = 15;
const int MAXN = 300010;
typedef long long LL;
char buf[MAXN];
int n;
bool judge(int * buf, int len) {
	for (int i = 0; i != len; ++i)
		for (int k = 1; i + k * 2 < len; ++k)
			if (buf[i] == buf[i + k] && buf[i] == buf[i + k * 2])
				return true;
	return false;
}
bool f[LIM + 1][1 << LIM];
int li[LIM + 1];
void dfs(int u, int S) {
	f[u][S] = judge(li, u);
	if (u < LIM) {
		li[u] = 0; dfs(u + 1, S << 1);
		li[u] = 1; dfs(u + 1, S << 1 | 1);
	}
}
int main() {
	dfs(0, 0);
	scanf("%s", buf);
	n = strlen(buf);
	LL ans = n * (n + 1ll) >> 1;
	for (int i = 0; i < n; ++i) {
		const int UP = std::min(n, i + LIM);
		int now = 0;
		for (int r = i; r < UP; ++r) {
			now = now << 1 | (buf[r] & 1);
			ans -= !f[r - i + 1][now];
		}
	}
	printf("%lld\n", ans);
	return 0;
}