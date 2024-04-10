#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
const int MAXLOG = 20;
const int MAXM = 1e6 + 5;
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
struct info {int x, y, val; } e[MAXM];
struct edge {int dest, val; };
vector <edge> a[MAXN];
int n, m, k, f[MAXN], depth[MAXN], father[MAXN][MAXLOG], val[MAXN];
bool sel[MAXM], key[MAXN];
int F(int x) {
	if (f[x] == x) return x;
	else return f[x] = F(f[x]);
}
void col(int pos, int lca, int v) {
	pos = F(pos);
	while (depth[pos] > depth[lca]) {
		val[pos] = v;
		f[pos] = F(father[pos][0]);
		pos = F(pos);
	}
}
void dfs(int pos, int fa) {
	father[pos][0] = fa;
	depth[pos] = depth[fa] + 1;
	for (int i = 1; i < MAXLOG; i++)
		father[pos][i] = father[father[pos][i - 1]][i - 1];
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i].dest != fa) {
			if (a[pos][i].val == 0) key[a[pos][i].dest] = true;
			dfs(a[pos][i].dest, pos);
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
bool cmp(info a, info b) {
	return a.val < b.val;
}
int main() {
	read(n), read(k), read(m);
	for (int i = 1; i <= n; i++)
		f[i] = i;
	int tot = 0;
	for (int i = 1; i <= k; i++) {
		int x, y; read(x), read(y);
		e[++tot] = (info) {x, y, 0};
	}
	for (int i = 1; i <= m; i++) {
		int x, y, z; read(x), read(y), read(z);
		e[++tot] = (info) {x, y, z};
	}
	for (int i = 1; i <= n; i++)
		f[i] = i;
	sort(e + 1, e + tot + 1, cmp);
	for (int i = 1; i <= tot; i++) {
		if (F(e[i].x) == F(e[i].y)) continue;
		sel[i] = true;
		f[F(e[i].x)] = F(e[i].y);
		a[e[i].x].push_back((edge) {e[i].y, e[i].val});
		a[e[i].y].push_back((edge) {e[i].x, e[i].val});
	}
	for (int i = 1; i <= n; i++)
		f[i] = i;
	dfs(1, 0);
	for (int i = 1; i <= tot; i++) {
		if (sel[i]) continue;
		int tmp = lca(e[i].x, e[i].y);
		col(e[i].x, tmp, e[i].val);
		col(e[i].y, tmp, e[i].val);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		if (key[i]) {
			if (val[i] == 0) {
				printf("-1\n");
				return 0;
			}
			ans += val[i];
		}
	writeln(ans);
	return 0;
}