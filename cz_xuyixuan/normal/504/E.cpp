#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int P = 1e9 + 7;
const int Q = 998244353;
const int MAXLOG = 20;
typedef long long ll;
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
struct ull {int a, b; };
int n, m, depth[MAXN], father[MAXN][MAXLOG];
ull bit[MAXLOG], val[MAXN][MAXLOG][2];
char s[MAXN]; vector <int> a[MAXN];
ull operator + (ull a, ull b) {return (ull) {(a.a + b.a) % P, (a.b + b.b) % Q}; }
ull operator * (ull a, ull b) {return (ull) {(1ll * a.a * b.a) % P, (1ll * a.b * b.b) % Q}; }
bool operator == (ull a, ull b) {return a.a == b.a && a.b == b.b; }
void dfs(int pos, int fa) {
	depth[pos] = depth[fa] + 1;
	father[pos][0] = fa;
	val[pos][0][0] = (ull) {s[pos], s[pos]};
	val[pos][0][1] = (ull) {s[pos], s[pos]};
	for (int i = 1; i < MAXLOG; i++) {
		father[pos][i] = father[father[pos][i - 1]][i - 1];
		val[pos][i][0] = val[pos][i - 1][0] + bit[i - 1] * val[father[pos][i - 1]][i - 1][0];
		val[pos][i][1] = bit[i - 1] * val[pos][i - 1][1] + val[father[pos][i - 1]][i - 1][1];
	}
	for (auto x : a[pos])
		if (x != fa) dfs(x, pos);
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
int up(int x, int y) {
	for (int i = 0; i < MAXLOG; i++)
		if (y & (1 << i)) x = father[x][i];
	return x;
}
int conlcp(int a, int b, int c, int d) {
	int len = depth[a] - depth[b] + 1, ans = 0;
	assert(depth[d] - depth[c] + 1 == len);
	static int x[MAXN]; x[0] = d;
	for (int i = 0, t = 1; i < MAXLOG; i++, t <<= 1) {
		x[i + 1] = x[i];
		if (len & t) x[i + 1] = father[x[i]][i];
	}
	for (int i = MAXLOG - 1, t = 1 << i; i >= 0; i--, t >>= 1) {
		if (len & t) {
			if (val[a][i][0] == val[x[i]][i][1]) ans += t, a = father[a][i];
			else {
				int tmpx = a, tmpy = x[i];
				for (int j = i - 1; j >= 0; j--)
					if (val[tmpx][j][0] == val[father[tmpy][j]][j][1]) ans += 1 << j, tmpx = father[tmpx][j];
					else tmpy = father[tmpy][j];
				return ans;
			}
		}
	}
	return len;
}
int samelcp(int a, int b, int c, int d) {
	int len = depth[b] - depth[a] + 1, ans = 0;
	assert(depth[d] - depth[c] + 1 == len);
	static int x[MAXN], y[MAXN]; x[0] = b, y[0] = d;
	for (int i = 0, t = 1; i < MAXLOG; i++, t <<= 1) {
		x[i + 1] = x[i], y[i + 1] = y[i];
		if (len & t) {
			x[i + 1] = father[x[i]][i];
			y[i + 1] = father[y[i]][i];
		}
	}
	for (int i = MAXLOG - 1, t = 1 << i; i >= 0; i--, t >>= 1) {
		if (len & t) {
			if (val[x[i]][i][0] == val[y[i]][i][0]) ans += t;
			else {
				int tmpx = x[i], tmpy = y[i];
				for (int j = i - 1; j >= 0; j--)
					if (val[father[tmpx][j]][j][0] == val[father[tmpy][j]][j][0]) ans += 1 << j;
					else tmpx = father[tmpx][j], tmpy = father[tmpy][j];
				return ans;
			}
		}
	}
	return len;
}
int main() {
	read(n), scanf("\n%s", s + 1);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	bit[0] = (ull) {256, 256};
	for (int i = 1; i < MAXLOG; i++)
		bit[i] = bit[i - 1] * bit[i - 1];
	dfs(1, 0);
	read(m);
	for (int x = 1; x <= m; x++) {
		int xs, xt, ys, yt;
		read(xs), read(xt);
		read(ys), read(yt);
		int xl = lca(xs, xt), yl = lca(ys, yt), ans = 0;
		for (int i = MAXLOG - 1; i >= 0; i--)
			if (depth[father[xs][i]] >= depth[xl] && depth[father[ys][i]] >= depth[yl] && val[xs][i][0] == val[ys][i][0]) {
				ans += 1 << i;
				xs = father[xs][i];
				ys = father[ys][i];
			}
		if (xl != xs && yl != ys) {
			printf("%d\n", ans);
			continue;
		}
		if (yl != ys) swap(xl, yl), swap(xs, ys), swap(xt, yt);
		int xlen = depth[xs] + depth[xt] - 2 * depth[xl] + 1;
		int ylen = depth[ys] + depth[yt] - 2 * depth[yl] + 1;
		if (ylen >= xlen) yt = up(yt, ylen - xlen), ylen = xlen;
		else {
			if (depth[xt] - depth[xl] >= xlen - ylen) xt = up(xt, xlen - ylen);
			else xl = xt = up(xs, ylen - 1);
			xlen = ylen; 
		}
		if (xs != xl) {
			int tmp = conlcp(xs, up(xs, depth[xs] - depth[xl] - 1), ys, up(yt, ylen - (depth[xs] - depth[xl])));
			ans += tmp;
			if (tmp != depth[xs] - depth[xl]) {
				printf("%d\n", ans);
				continue;
			}
		}
		ans += samelcp(xl, xt, up(yt, ylen - (depth[xs] - depth[xl]) - 1 ), yt);
		printf("%d\n", ans);
	}
	return 0;
}