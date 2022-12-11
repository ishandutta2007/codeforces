#include <bits/stdc++.h>

typedef long long LL;
const int MAXN = 500010;
const LL INF = std::numeric_limits<LL>::max();
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int n, sz[MAXN];
LL Ans, f[MAXN];
void gmi(LL & x, LL y) { x > y ? x = y : 0; }
LL pw(int x) { return (LL) x * x; }
struct vec {
	int x; LL y;
	int id;
	vec() { x = y = 0; }
	vec(int a, LL b) { x = a, y = b; }
	bool operator < (vec b) const {
		return x == b.x ? y < b.y : x < b.x;
	}
	vec operator - (vec b) const {
		return vec(x - b.x, y - b.y);
	}
	LL operator () (int a) { return (LL) a * x + y; }
} li[MAXN];
typedef long double db;
bool crossu(vec x, vec y, vec z) {
	y = y - x, z = z - x;
	db rx = (db) y.x * z.y - (db) y.y * z.x;
	return rx >= -1e-8;
}
void dfs(int u, int fa = 0) {
	sz[u] = 1;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			dfs(to[i], u);
			sz[u] += sz[to[i]];
		}
	f[u] = pw(sz[u]);
	int bak = 0;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			gmi(Ans, f[to[i]] + pw(n - sz[to[i]]));
			gmi(f[u], f[to[i]] + pw(sz[u] - sz[to[i]]));
			li[++bak] = vec(-sz[to[i]] * 2, f[to[i]] + pw(sz[to[i]]));
			li[bak].id = to[i];
		}
	std::sort(li + 1, li + 1 + bak);
	static vec st[MAXN]; int top = 0;
	for (int i = 1; i <= bak; ++i) {
		if (top) {
			int at = n + li[i].x / 2;
			LL res = st[1](at);
			int l = 1, r = top - 1;
			while (l <= r) {
				int mid = l + r >> 1;
				LL lh = st[mid](at), rh = st[mid + 1](at);
				gmi(res, lh), gmi(res, rh);
				if (lh > rh) l = mid + 1;
				else r = mid - 1;
			}
			gmi(Ans, res + pw(at) + f[li[i].id]);
		}
		while (top > 1 && crossu(st[top - 1], st[top], li[i])) --top;
		st[++top] = li[i];
	}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, b, e; i < n; ++i)
		std::cin >> b >> e, adde(b, e);
	Ans = INF;
	dfs(1);
	Ans = 2ll * n * n - n - Ans;
	Ans /= 2;
	std::cout << Ans << std::endl;
	return 0;
}