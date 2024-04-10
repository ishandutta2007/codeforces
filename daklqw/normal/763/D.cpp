#include <bits/stdc++.h>

std::mt19937 rd(time(0));
const int MAXN = 100010;
const int mod = 1004535809;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}

int func[MAXN], sz[MAXN];
int f[MAXN], n;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
inline int tr(int x, int s) { return (LL) func[s] * x % mod; }
std::unordered_map<int, int> M;
int ans, rt, rtv = -1;
void add(int x) { ans += ++M[x] == 1; }
void dec(int x) { ans -= --M[x] == 0; }
void dfs(int u, int fa = 0) {
	sz[u] = f[u] = 1;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			dfs(to[i], u), sz[u] += sz[to[i]];
			reduce(f[u] += tr(f[to[i]], sz[to[i]]) - mod);
		}
	add(f[u]);
}
void dfs2(int u, int up = 0, int fa = 0) {
	int dup = tr(up, n - sz[u]);
	int full = (f[u] + dup) % mod;
	if (fa) add(up);
	add(full), dec(f[u]);
	if (ans > rtv) rtv = ans, rt = u;
	dec(full);
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			int t = ((LL) dup + f[u] - tr(f[to[i]], sz[to[i]]) + mod) % mod;
			dfs2(to[i], t, u);
		}
	add(f[u]);
	if (fa) dec(up);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, b, e; i < n; ++i)
		std::cin >> b >> e, adde(b, e);
	for (int i = 1; i <= n; ++i) func[i] = rd() % mod;
	dfs(1); dfs2(1);
	std::cout << rt << std::endl;
	return 0;
}