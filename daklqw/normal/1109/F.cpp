#include <bits/stdc++.h>

const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
const int MAXP = 2e5 + 10;

int fa[MAXP], son[MAXP][2];
int get(int x, int b = 1) { return son[fa[x]][b] == x; }
int isroot(int x) { return !(get(x, 0) || get(x, 1)); }
void rotate(int x) {
	int y = fa[x], z = fa[y]; bool b = get(x);
	if (!isroot(y)) son[z][get(y)] = x;
	son[y][b] = son[x][!b]; son[x][!b] = y;
	fa[y] = x; fa[x] = z; if (int t = son[y][b]) fa[t] = y;
}
int tag[MAXP];
void pushdown(int x) {
	if (tag[x]) {
		if (int t = son[x][0]) tag[t] ^= 1;
		if (int t = son[x][1]) tag[t] ^= 1;
		tag[x] = 0;
		std::swap(son[x][0], son[x][1]);
	}
}
void splay(int x) {
	static int st[MAXP], top;
	for (int y = st[top = 1] = x; !isroot(y); st[++top] = y = fa[y]);
	for (; top; --top) pushdown(st[top]);
	for (; !isroot(x); rotate(x)) if (!isroot(fa[x]))
		rotate(get(x) ^ get(fa[x]) ? x : fa[x]);
}
void access(int x) {
	int t = 0;
	while (x) {
		splay(x);
		son[x][1] = t;
		t = x;
		x = fa[x];
	}
}
void mkroot(int x) {
	access(x); splay(x); tag[x] ^= 1;
}
void link(int x, int y) {
	mkroot(x);
	fa[x] = y;
}
void split(int x, int y) {
	mkroot(x), access(y), splay(y);
}
void cut(int x, int y) {
	split(x, y);
	fa[x] = son[y][0] = 0;
}
bool conn(int x, int y) {
	split(x, y);
	while (true) {
		pushdown(y);
		if (son[y][0]) y = son[y][0];
		else break;
	}
	splay(y);
	return x == y;
}
typedef long long LL;
struct info {
	int mi, cnt;
	friend info operator + (info a, info b) {
		info r;
		r.mi = std::min(a.mi, b.mi);
		r.cnt = (a.mi == r.mi) * a.cnt + (b.mi == r.mi) * b.cnt;
		return r;
	}
} tree[MAXP << 2];
int tagadd[MAXP << 2];
void mkadd(int u, int v) {
	tagadd[u] += v;
	tree[u].mi += v;
}
void sgtpushdown(int u) {
	if (int & t = tagadd[u]) {
		mkadd(u << 1, t);
		mkadd(u << 1 | 1, t);
		t = 0;
	}
}
void mdf(int u, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) return mkadd(u, v);
	int mid = l + r >> 1;
	sgtpushdown(u);
	if (L <= mid) mdf(u << 1, l, mid, L, R, v);
	if (mid < R) mdf(u << 1 | 1, mid + 1, r, L, R, v);
	tree[u] = tree[u << 1] + tree[u << 1 | 1];
}
info qry(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tree[u];
	int mid = l + r >> 1;
	sgtpushdown(u);
	info res; res.mi = INF, res.cnt = 0;
	if (L <= mid) res = qry(u << 1, l, mid, L, R);
	if (mid < R) res = res + qry(u << 1 | 1, mid + 1, r, L, R);
	return res;
}
void build(int u, int l, int r) {
	tree[u].cnt = r - l + 1;
	if (l == r) return ;
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
}

int ax[MAXP], ay[MAXP];
int mat[MAXN][MAXN];
int n, m;
std::vector<int> es[MAXP];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			std::cin >> mat[i][j];
			ax[mat[i][j]] = i;
			ay[mat[i][j]] = j;
		}
	const int K = n * m;
	build(1, 1, K);
	LL ans = 0;
	int cur = 1;
	for (int i = 1; i <= K; ++i) {
		mdf(1, 1, K, 1, i, 1);
		const int dx[4] = {1, 0, -1, 0};
		const int dy[4] = {0, 1, 0, -1};
		int x = ax[i], y = ay[i];
		for (int j = 0; j < 4; ++j) {
			int tx = x + dx[j], ty = y + dy[j];
			if (tx < 1 || ty < 1 || tx > n || ty > m)
				continue;
			int v = mat[tx][ty];
			if (v < i) {
				mdf(1, 1, K, 1, v, -1);
				while (conn(v, i)) {
					for (auto t : es[cur]) cut(cur, t);
					++cur;
				}
				if (v >= cur) {
					es[v].emplace_back(i);
					link(v, i);
				}
			}
		}
		info res = qry(1, 1, K, cur, i);
		if (res.mi == 1) ans += res.cnt;
	}
	std::cout << ans << std::endl;
	return 0;
}