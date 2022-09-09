#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXLOG = 20;
const int INF = 1e9;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
struct BinaryIndexTree {
	int n, a[MAXN];
	void init(int x) {
		n = x;
		memset(a, 0, sizeof(a));
	}
	void modify(int x, int d) {
		for (int i = x; i <= n; i += i & -i)
			a[i] += d;
	}
	int query(int l, int r) {
		int ans = 0;
		for (int i = r; i >= 1; i -= i & -i)
			ans += a[i];
		for (int i = l - 1; i >= 1; i -= i & -i)
			ans -= a[i];
		return ans;
	}
} BIT;
vector <int> a[MAXN], b[MAXN];
vector <int> pr[MAXN], home[MAXN], sum[MAXN];
int n, m, q, father[MAXN][MAXLOG], depth[MAXN];
int ans[MAXN], up[MAXN][MAXLOG];
int timer, dfn[MAXN], rit[MAXN];
void work(int pos) {
	for (unsigned i = 0; i < pr[pos].size(); i++)
		sum[pos].push_back(BIT.query(dfn[pr[pos][i]], rit[pr[pos][i]]));
	for (unsigned i = 0; i < b[pos].size(); i++)
		BIT.modify(dfn[b[pos][i]], 1);
	for (unsigned i = 0; i < a[pos].size(); i++)
		work(a[pos][i]);
	for (unsigned i = 0; i < pr[pos].size(); i++)
		if (sum[pos][i] != BIT.query(dfn[pr[pos][i]], rit[pr[pos][i]])) ans[home[pos][i]]--;
}
int steps(int pos, int dest) {
	if (pos == dest) return 0;
	int ans = 0;
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (up[pos][i] > dest) {
			pos = up[pos][i];
			ans += 1 << i;
		}
	if (up[pos][0] > dest) return INF;
	else return ans + 1;
}
int climb(int pos, int cnt) {
	for (int i = 0; i < MAXLOG; i++)
		if (cnt & (1 << i)) pos = up[pos][i];
	return pos;
}
void getup(int pos) {
	for (unsigned i = 0; i < a[pos].size(); i++) {
		getup(a[pos][i]);
		chkmin(up[pos][0], up[a[pos][i]][0]);
	}
}
int lca(int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (depth[father[x][i]] >= depth[y]) x = father[x][i];
	if (x == y) return x;
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (father[x][i] != father[y][i]) {
			x = father[x][i];
			y = father[y][i];
		}
	return father[x][0];
}
void dfs(int pos) {
	for (int i = 1; i < MAXLOG; i++)
		father[pos][i] = father[father[pos][i - 1]][i - 1];
	dfn[pos] = ++timer;
	for (unsigned i = 0; i < a[pos].size(); i++) {
		depth[a[pos][i]] = depth[pos] + 1;
		dfs(a[pos][i]);
	}
	rit[pos] = timer;
}
int main() {
	read(n);
	for (int i = 2; i <= n; i++) {
		read(father[i][0]);
		for (int j = 1; j < MAXLOG; j++)
			father[i][j] = father[father[i][j - 1]][j - 1];
		a[father[i][0]].push_back(i);
	}
	depth[1] = 1; dfs(1);
	read(m);
	for (int i = 1; i <= n; i++)
		up[i][0] = i;
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		b[x].push_back(y);
		b[y].push_back(x);
		int z = lca(x, y);
		chkmin(up[x][0], z);
		chkmin(up[y][0], z);
	}
	getup(1);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j < MAXLOG; j++)
		up[i][j] = up[up[i][j - 1]][j - 1];
	read(q);
	for (int i = 1; i <= q; i++) {
		int x, y; read(x), read(y);
		int z = lca(x, y);
		if (z == x) ans[i] = steps(y, z);
		else if (z == y) ans[i] = steps(x, z);
		else {
			int cx = steps(x, z);
			int cy = steps(y, z);
			ans[i] = cx + cy;
			int tx = climb(x, cx - 1);
			int ty = climb(y, cy - 1);
			pr[tx].push_back(ty);
			home[tx].push_back(i);
		}
	}
	BIT.init(n);
	work(1);
	for (int i = 1; i <= q; i++)
		if (ans[i] >= INF) writeln(-1);
		else writeln(ans[i]);
	return 0;
}