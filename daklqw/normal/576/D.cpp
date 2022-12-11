#include <bits/stdc++.h>

const int MAXN = 151;
const int INF = std::numeric_limits<int>::max();
int n, m;
typedef std::bitset<MAXN> B;
struct mat {
	B a[MAXN];
	mat operator * (mat b) {
		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j) {
				int x = b.a[i][j];
				b.a[i][j] = b.a[j][i];
				b.a[j][i] = x;
			}
		mat res;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				res.a[i][j] = (a[i] & b.a[j]).any();
		return res;
	}
} ;
struct e {
	int x, y, v;
	bool operator < (e b) const { return v < b.v; }
} es[MAXN];

mat res, a;
int head[MAXN], nxt[MAXN], to[MAXN], tot;
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
}
void fastpow(int v, int b, mat & res) {
	for (int i = 1; i <= n; ++i) a.a[i].reset();
	for (int i = 1; i <= m && es[i].v <= v; ++i)
		a.a[es[i].x][es[i].y] = 1;
	for (; b; b >>= 1, b && (a = a * a, 0)) if (b & 1)
		res = res * a;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		std::cin >> es[i].x >> es[i].y >> es[i].v;
	std::sort(es + 1, es + 1 + m);
	for (int i = 1; i <= n; ++i) res.a[i][i] = 1;
	int ans = INF;
	for (int i = 1; i <= m; ++i) {
		fastpow(es[i].v - 1, es[i].v - es[i - 1].v, res);
		addedge(es[i].x, es[i].y);
		static int vis[MAXN];
		std::queue<int> q;
		for (int j = 1; j <= n; ++j) if (res.a[1][j]) {
			memset(vis, 0, n + 1 << 2);
			vis[j] = 1; q.push(j);
			while (!q.empty()) {
				int t = q.front(); q.pop();
				for (int i = head[t]; i; i = nxt[i])
					if (!vis[to[i]]) {
						vis[to[i]] = vis[t] + 1;
						q.push(to[i]);
					}
			}
			if (vis[n]) ans = std::min(ans, es[i].v + vis[n] - 1);
		}
	}
	if (ans == INF) std::cout << "Impossible" << std::endl;
	else std::cout << ans << std::endl;
	return 0;
}