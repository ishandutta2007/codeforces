#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

const int MAXN = 1010;
const int MAXS = 1 << 12;
const int Dollar1 = 1000000007;
typedef long long LL;
typedef std::vector<int> VI;
typedef std::set<int> SI;
inline int up(int x) { return x -= Dollar1, x + (x >> 31 & Dollar1); }
inline int down(const int x) { return x + (x >> 31 & Dollar1); }
inline void add(int & x, const int y) { x += y - Dollar1, x += x >> 31 & Dollar1; }
inline void dec(int & x, const int y) { x -= y, x += x >> 31 & Dollar1; }
inline int mul(const int x, const int y) {
	return static_cast<LL> (x) * y % Dollar1;
}
inline void mulr(int & x, const int y) {
	x = static_cast<LL> (x) * y % Dollar1;
}
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
inline void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
struct T {
	int head[12], nxt[12 << 1], to[12 << 1], tot;
	T() { memset(head, 0, sizeof head); tot = 0; }
	inline void addedge(int b, int e) {
		nxt[++tot] = head[b]; to[head[b] = tot] = e;
		nxt[++tot] = head[e]; to[head[e] = tot] = b;
	}
} tree;
int fac[20], inv[20];
int ha[13], rdc[13], fa[13];
VI has[13];
int getha(int u, int f) {
	fa[u] = f;
	VI & hal = has[u]; hal.clear();
	for (int i = tree.head[u]; i; i = tree.nxt[i]) if (tree.to[i] != f)
		hal.push_back(getha(tree.to[i], u));
	std::sort(hal.begin(), hal.end());
	int vha = 0, now = 13, lst = -1, cnt = 1, red = 1;
	for (int i : hal) {
		if (i == lst) ++cnt; else mulr(red, inv[cnt]), cnt = 1, lst = i;
		add(vha, mul(now, i)), mulr(now, 41);
	}
	mulr(red, inv[cnt]);
	add(vha, 1); rdc[u] = red;
	// printf("GETHA %d FA %d RDC %d HA %d , LI : ", u, f, rdc[u], vha);
	// for (int i : hal) printf("%d ", i);
	// putchar(10);
	return ha[u] = vha;
}
int n, m, t1, t2;
int dp[MAXN][12];
int cnt[1 << 12];
SI vis;
int ans = 0;
int avai[12], RT;
void DP(int u, int f) {
	for (int i = head[u]; i; i = nxt[i]) if (to[i] != f) DP(to[i], u);
	// printf("DP %d\n", u);
	for (int i = 0; i != m; ++i) {
		memset(avai, -1, sizeof avai);
		int bak = 0;
		for (int j = tree.head[i]; j; j = tree.nxt[j])
			if (tree.to[j] != fa[i]) avai[tree.to[j]] = bak++;
		const int U = 1 << bak;
		memset(cnt, 0, U << 2);
		cnt[0] = 1;
		for (int j = head[u]; j; j = nxt[j]) if (to[j] != f) {
			for (int k = U - 2; k >= 0; --k) if (cnt[k]) {
				for (int l = 0; l != m; ++l)
					if (~avai[l] && !(k >> avai[l] & 1))
						add(cnt[k | 1 << avai[l]], mul(cnt[k], dp[to[j]][l]));
			}
		}
		// printf("DP RT %d : ", i);
		// for (int j = 0; j != m; ++j) if (~avai[j]) prin
		// for (int j = 0; j != U; ++j) printf("%d ", cnt[j]); putchar(10);
		dp[u][i] = mul(cnt[U - 1], rdc[i]);
	}
	// printf("GET : "); for (int i = 0; i != m; ++i) printf("%d ", dp[u][i]);
	// putchar(10);
	add(ans, dp[u][RT]);
}
int main() {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i != 20; ++i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[Dollar1 % i], down(-Dollar1 / i));
	}
	for (int i = 2; i != 20; ++i) mulr(inv[i], inv[i - 1]);
	scanf("%d", &n);
	for (int i = 1; i != n; ++i) {
		scanf("%d%d", &t1, &t2);
		addedge(t1, t2);
	}
	scanf("%d", &m);
	for (int i = 1; i != m; ++i) {
		scanf("%d%d", &t1, &t2);
		tree.addedge(--t1, --t2);
	}
	for (int i = 0; i != m; ++i) {
		int HA = getha(i, -1);
		if (vis.find(HA) != vis.end()) continue;
		vis.insert(HA);
		memset(dp, 0, sizeof dp);
		RT = i;
		DP(1, 0);
	}
	printf("%d\n", ans);
	return 0;
}