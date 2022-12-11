#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int Dollar1 = 1000000007;
const int MAXN = 100010;
const int MAXM = 200010;
typedef long long LL;
int head[MAXN], nxt[MAXM << 1], to[MAXM << 1], tot = 1;
LL val[MAXM << 1];
inline int up(int x) { return x -= Dollar1, x + (x >> 31 & Dollar1); }
inline int mul(const int x, const int y) { return static_cast<LL> (x) * y % Dollar1; }
inline void addedge(int b, int e, LL v) {
	nxt[++tot] = head[b]; head[b] = tot; to[tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; head[e] = tot; to[tot] = b; val[tot] = v;
}
struct Base {
	LL a[64];
	int rnk;
	void clear() {
		for (int i = 62; ~i; --i) a[i] = 0;
		rnk = 0;
	}
	void insert(LL x) {
		for (int i = 62; ~i; --i) if (x >> i & 1)
			if (a[i]) x ^= a[i];
			else { a[i] = x; ++rnk; break; }
	}
} base;
LL dis[MAXN], t3;
bool vis[MAXN];
int t1, t2, c0[64], c1[64];
void dfs(int u, int fa) {
	vis[u] = true;
	for (int i = 62; ~i; --i)
		if (dis[u] >> i & 1) ++c1[i];
		else ++c0[i];
	for (int i = head[u]; i; i = nxt[i]) if (i != fa) {
		if (vis[to[i]]) {
			base.insert(dis[u] ^ dis[to[i]] ^ val[i]);
		} else {
			dis[to[i]] = dis[u] ^ val[i];
			dfs(to[i], i ^ 1);
		}
	}
}
int pow2[128];
int n, m;
inline int C(int x) { return static_cast<LL> (x) * (x - 1) / 2 % Dollar1; }
int main() {
	*pow2 = 1;
	for (int i = 1; i != 128; ++i) pow2[i] = up(pow2[i - 1] << 1);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%lld", &t1, &t2, &t3);
		addedge(t1, t2, t3);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) if (!vis[i]) {
		base.clear();
		for (int j = 0; j != 63; ++j) c0[j] = c1[j] = 0;
		dfs(i, 0);
		LL able = 0;
		for (int j = 0; j != 63; ++j) able |= base.a[j];
		for (int j = 0; j != 63; ++j) {
			ans = up(ans + mul(mul(c0[j], c1[j]), pow2[j + base.rnk - (able >> j & 1)]));
			if (able >> j & 1) {
				ans = up(ans + mul(C(c0[j]), pow2[j + base.rnk - 1]));
				ans = up(ans + mul(C(c1[j]), pow2[j + base.rnk - 1]));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}