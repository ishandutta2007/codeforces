#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
const int MAXLOG = 20;
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
	int query(int x) {
		int ans = 0;
		for (int i = x; i >= 1; i -= i & -i)
			ans += a[i];
		return ans;
	}
	int query(int l, int r) {
		int ans = 0;
		for (int i = r; i >= 1; i -= i & -i)
			ans += a[i];
		for (int i = l - 1; i >= 1; i -= i & -i)
			ans -= a[i];
		return ans;
	}
	int nxt(int x) {
		int sum = query(x), ans = 0;
		if (sum == 0) return 0;
		for (int i = MAXLOG, p = 1 << i; i >= 0; i--, p >>= 1)
			if (ans + p <= n && a[ans + p] < sum) {
				ans += p;
				sum -= a[ans];
			}
		return ans + 1;
	}
} BIT;
ll ans, sum[MAXN], res[MAXN];
int n, m, c[MAXN]; vector <int> a[MAXN];
int father[MAXN][MAXLOG], depth[MAXN], size[MAXN], son[MAXN];
int timer, dfn[MAXN], rit[MAXN], home[MAXN], up[MAXN];
vector <pair <int, pair <int, bool>>> q[MAXN];
int findnxt(int pos) {
	while (pos != 0) {
		int tmp = BIT.nxt(dfn[pos]);
		if (tmp >= dfn[up[pos]]) return home[tmp];
		pos = father[up[pos]][0];
	}
	return 0;
}
int converge(int from, int to) {
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (depth[father[from][i]] > depth[to]) from = father[from][i];
	return from;
}
void addpoint(int pos) {
	int nxt = converge(pos, findnxt(father[pos][0]));
	int delta = size[pos] - BIT.query(dfn[pos], rit[pos]);
	BIT.modify(dfn[pos], delta), ans += sum[pos];
	if (son[pos]) {
		int tmp = size[son[pos]] - BIT.query(dfn[son[pos]], rit[son[pos]]);
		ans += 1ll * tmp * tmp;
	}
	int tmp = size[nxt] - BIT.query(dfn[nxt], rit[nxt]);
	ans += 1ll * tmp * tmp - 1ll * (tmp + delta) * (tmp + delta);
	if (father[nxt][0] != 0) BIT.modify(dfn[father[nxt][0]], -delta);
	pos = up[pos];
	while (depth[pos] >= depth[nxt]) {
		int tmp = size[pos] - BIT.query(dfn[pos], rit[pos]);
		sum[father[pos][0]] += 1ll * tmp * tmp - 1ll * (tmp + delta) * (tmp + delta);
		pos = up[father[pos][0]];
	}
}
void delpoint(int pos) {
	int nxt = converge(pos, findnxt(father[pos][0]));
	int delta = BIT.query(dfn[pos], dfn[pos]);
	BIT.modify(dfn[pos], -delta), ans -= sum[pos];
	if (son[pos]) {
		int tmp = size[son[pos]] - BIT.query(dfn[son[pos]], rit[son[pos]]);
		ans -= 1ll * tmp * tmp;
	}
	int tmp = size[nxt] - BIT.query(dfn[nxt], rit[nxt]);
	ans += 1ll * tmp * tmp - 1ll * (tmp - delta) * (tmp - delta);
	if (father[nxt][0] != 0) BIT.modify(dfn[father[nxt][0]], delta);
	pos = up[pos];
	while (depth[pos] >= depth[nxt]) {
		int tmp = size[pos] - BIT.query(dfn[pos], rit[pos]);
		sum[father[pos][0]] += 1ll * tmp * tmp - 1ll * (tmp - delta) * (tmp - delta);
		pos = up[father[pos][0]];
	}
}
void dfs(int pos, int fa) {
	size[pos] = 1;
	father[pos][0] = fa;
	depth[pos] = depth[fa] + 1;
	for (int i = 1; i < MAXLOG; i++)
		father[pos][i] = father[father[pos][i - 1]][i - 1];
	for (auto x : a[pos])
		if (x != fa) {
			dfs(x, pos);
			size[pos] += size[x];
			if (size[x] > size[son[pos]]) son[pos] = x;
		}
}
void efs(int pos, int fa, int from) {
	up[pos] = from;
	dfn[pos] = ++timer;
	home[timer] = pos;
	if (son[pos]) efs(son[pos], pos, from);
	for (auto x : a[pos])
		if (x != fa && x != son[pos]) {
			efs(x, pos, x);
			sum[pos] += 1ll * size[x] * size[x];
		}
	rit[pos] = timer;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(c[i]);
		q[c[i]].emplace_back(0, make_pair(i, true));
	}
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	efs(1, 0, 1);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		q[c[x]].emplace_back(i, make_pair(x, false));
		q[c[x] = y].emplace_back(i, make_pair(x, true));
	}
	for (int i = 1; i <= n; i++)
		q[c[i]].emplace_back(m + 1, make_pair(i, false));
	BIT.init(n);
	ans = 1ll * n * n;
	for (int i = 1; i <= n; i++) {
		for (auto x : q[i]) {
			res[x.first] -= 1ll * n * n - ans;
			if (x.second.second) addpoint(x.second.first);
			else delpoint(x.second.first);
			res[x.first] += 1ll * n * n - ans;
		}
	}
	for (int i = 0; i <= m; i++) {
		if (i != 0) res[i] += res[i - 1];
		writeln(res[i]);
	}
	return 0;
}