#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
const int MAXLOG = 20;
const int INF = 1e9;
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
struct info {int d, y; };
struct segment {int x, l, r; };
struct point {int x, y, belong; };
void chkmax(int &x, int y) {x = max(x, y); }
void chkmin(int &x, int y) {x = min(x, y); }
struct BinaryIndexTree {
	int n, pl, pr;
	vector <int> pre, suf;
	void init(int l, int r) {
		n = r - l + 1; pl = l, pr = r;
		for (int i = 0; i <= n; i++) {
			pre.push_back(INF);
			suf.push_back(INF);
		}
	}
	void modify(info x) {
		int pos = x.y - pl + 1, val = x.d - x.y;
		for (int i = pos; i <= n; i += i & -i)
			chkmin(pre[i], val);
		pos = pr - x.y + 1, val = x.d + x.y;
		for (int i = pos; i <= n; i += i & -i)
			chkmin(suf[i], val);
	}
	int query(info x) {
		int ans = INF;
		for (int i = x.y - pl + 1; i != 0; i -= i & -i)
			chkmin(ans, pre[i] + x.y);
		for (int i = pr - x.y + 1; i != 0; i -= i & -i)
			chkmin(ans, suf[i] - x.y);
		return ans + x.d;
	} 
} bit[MAXN];
bool vis[MAXN], used[MAXN];
int n, m, root, Root;
int size[MAXN], weight[MAXN];
int father[MAXN], depth[MAXN];
point a[MAXN];
segment b[MAXN];
info c[MAXN][MAXLOG];
map <int, int> index[MAXN];
map <int, bool> exist[MAXN];
vector <int> t[MAXN], e[MAXN], cx[MAXN], cy[MAXN];
bool cmpx(int x, int y) {return a[x].x < a[y].x; }
bool cmpy(int x, int y) {return a[x].y < a[y].y; }
void getroot(int pos, int fa, int tot) {
	size[pos] = 1; weight[pos] = 0;
	for (unsigned i = 0; i < t[pos].size(); i++)
		if (t[pos][i] != fa && !vis[t[pos][i]]) {
			getroot(t[pos][i], pos, tot);
			size[pos] += size[t[pos][i]];
			chkmax(weight[pos], size[t[pos][i]]);
		}
	chkmax(weight[pos], tot - size[pos]);
	if (weight[pos] < weight[root]) root = pos;
}
void gsize(int pos, int fa) {
	size[pos] = 1;
	for (unsigned i = 0; i < t[pos].size(); i++)
		if (t[pos][i] != fa && !vis[t[pos][i]]) {
			gsize(t[pos][i], pos);
			size[pos] += size[t[pos][i]];
		}
}
void work(int pos, int dep, int fa) {
	depth[pos] = dep;
	father[pos] = fa;
	vis[pos] = true;
	bit[pos].init(b[pos].l, b[pos].r);
	static int q[MAXN];
	int l = 0, r = -1;
	for (int i = b[pos].l; i <= b[pos].r; i++) {
		int tmp = index[b[pos].x][i];
		used[tmp] = true; q[++r] = tmp;
		c[tmp][dep] = (info) {0, i}; 
	}
	while (l <= r) {
		int tmp = q[l++];
		for (unsigned i = 0; i < e[tmp].size(); i++)
			if (!used[e[tmp][i]] && c[e[tmp][i]][dep].d == 0) {
				c[e[tmp][i]][dep] = (info) {c[tmp][dep].d + 1, c[tmp][dep].y};
				q[++r] = e[tmp][i];
			}
	}
	gsize(pos, 0);
	for (unsigned i = 0; i < t[pos].size(); i++)
		if (!vis[t[pos][i]]) {
			root = 0;
			getroot(t[pos][i], 0, size[t[pos][i]]);
			work(root, dep + 1, pos);
		}
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i].x), read(a[i].y);
		index[a[i].x][a[i].y] = i;
		cx[a[i].x].push_back(i);
		cy[a[i].y].push_back(i);
	}
	for (int i = 1; i < MAXN; i++) {
		sort(cx[i].begin(), cx[i].end(), cmpy);
		for (unsigned j = 0, last = 0; j < cx[i].size(); j++) {
			if (j != cx[i].size() - 1 && a[cx[i][j]].y + 1 == a[cx[i][j + 1]].y) {
				e[cx[i][j]].push_back(cx[i][j + 1]);
				e[cx[i][j + 1]].push_back(cx[i][j]);
				continue;
			}
			b[++m] = (segment) {i, a[cx[i][last]].y, a[cx[i][j]].y};
			for (unsigned k = last; k <= j; k++)
				a[cx[i][k]].belong = m;
			last = j + 1;
		}
	}
	for (int i = 1; i < MAXN; i++) {
		sort(cy[i].begin(), cy[i].end(), cmpx);
		for (unsigned j = 0; j < cy[i].size(); j++)
			if (j != cy[i].size() - 1 && a[cy[i][j]].x + 1 == a[cy[i][j + 1]].x) {
				e[cy[i][j]].push_back(cy[i][j + 1]);
				e[cy[i][j + 1]].push_back(cy[i][j]);
				int x = a[cy[i][j]].belong, y = a[cy[i][j + 1]].belong;
				if (!exist[x][y]) {
					exist[x][y] = exist[y][x] = true;
					t[x].push_back(y);
					t[y].push_back(x);
				}
			}
	}
	weight[root = 0] = m + 1;
	getroot(1, 0, m);
	work(Root = root, 1, 0);
	int q; read(q);
	while (q--) {
		int opt, x, y;
		read(opt), read(x), read(y);
		int id = index[x][y], p = a[id].belong;
		if (opt == 1) {
			while (p) {
				bit[p].modify(c[id][depth[p]]);
				p = father[p];
			}
		} else {
			int ans = INF;
			while (p) {
				chkmin(ans, bit[p].query(c[id][depth[p]]));
				p = father[p];
			}
			if (ans > n) writeln(-1);
			else writeln(ans);
		}
	}
	return 0;
}