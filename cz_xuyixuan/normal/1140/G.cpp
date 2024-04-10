#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int MAXLOG = 20;
const long long INF = 1e18;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
struct state {ll dp[2][2]; };
state operator + (state a, state b) {
	state ans;
	for (int i = 0; i <= 1; i++)
	for (int j = 0; j <= 1; j++)
		ans.dp[i][j] = min(a.dp[i][0] + b.dp[0][j], a.dp[i][1] + b.dp[1][j]);
	return ans;
}
state dp[MAXN][MAXLOG], mid[MAXN];
ll val[MAXN], down[MAXN], up[MAXN];
int n, q, depth[MAXN], father[MAXN][MAXLOG];
vector <pair <int, pair <ll, ll>>> a[MAXN];
void getans(int pos, int fa, ll va, ll vb) {
	mid[pos].dp[0][1] = mid[pos].dp[1][0] = val[pos];
	if (fa) {
		dp[pos][0].dp[0][0] = va;
		dp[pos][0].dp[1][1] = vb;
		dp[pos][0].dp[0][1] = INF;
		dp[pos][0].dp[1][0] = INF;
	}
	for (int i = 1; i < MAXLOG; i++)
		dp[pos][i] = dp[pos][i - 1] + mid[father[pos][i - 1]] + dp[father[pos][i - 1]][i - 1];
	for (auto x : a[pos])
		if (x.first != fa) getans(x.first, pos, x.second.first, x.second.second);
}
void dfs(int pos, int fa) {
	depth[pos] = depth[fa] + 1;
	father[pos][0] = fa;
	for (int i = 1; i < MAXLOG; i++)
		father[pos][i] = father[father[pos][i - 1]][i - 1];
	down[pos] = val[pos];
	for (auto x : a[pos])
		if (x.first != fa) {
			dfs(x.first, pos);
			chkmin(down[pos], down[x.first] + x.second.first + x.second.second);
		}
}
void ufs(int pos, int fa) {
	ll Min = INF, Nin = INF;
	chkmin(up[pos], val[pos]);
	val[pos] = min(down[pos], up[pos]);
	for (auto x : a[pos])
		if (x.first != fa) {
			ll tmp = down[x.first] + x.second.first + x.second.second;
			if (tmp < Min) {
				Nin = Min;
				Min = tmp;
			} else chkmin(Nin, tmp);
		}
	for (auto x : a[pos])
		if (x.first != fa) {
			ll tmp = down[x.first] + x.second.first + x.second.second;
			if (tmp == Min) up[x.first] = min(Nin, up[pos]) + x.second.first + x.second.second;
			else up[x.first] = min(Min, up[pos]) + x.second.first + x.second.second;
			ufs(x.first, pos);
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
state unit() {
	state ans;
	ans.dp[0][0] = ans.dp[1][1] = 0;
	ans.dp[0][1] = ans.dp[1][0] = INF;
	return ans;
}
state gpath(int x, int y) {
	int z = lca(x, y), tx = x, ty = y;
	state ansx = unit(), ansy = unit();
	for (int i = 0; i < MAXLOG; i++) {
		if ((depth[x] - depth[z]) & (1 << i)) {
			ansx = ansx + mid[tx] + dp[tx][i];
			tx = father[tx][i];
		}
		if ((depth[y] - depth[z]) & (1 << i)) {
			ansy = ansy + mid[ty] + dp[ty][i];
			ty = father[ty][i];
		}
	}
	swap(ansy.dp[0][1], ansy.dp[1][0]);
	return ansx + mid[z] + ansy;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(val[i]);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; ll val, vbl;
		read(x), read(y), read(val), read(vbl);
		a[x].emplace_back(y, make_pair(val, vbl));
		a[y].emplace_back(x, make_pair(val, vbl));
	}
	dfs(1, 0);
	up[1] = val[1];
	ufs(1, 0);
	getans(1, 0, 0, 0);
	read(q);
	for (int i = 1; i <= q; i++) {
		int x, y; read(x), read(y);
		state tmp = gpath((x + 1) / 2, (y + 1) / 2);
		x = (x & 1) ^ 1, y = (y & 1) ^ 1;
		writeln(tmp.dp[x][y]);
	}
	return 0;
}