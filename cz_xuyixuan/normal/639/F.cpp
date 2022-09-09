#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
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
vector <int> a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int n, m, q, f[MAXN], x[MAXN], y[MAXN];
int father[MAXN][MAXLOG], depth[MAXN];
int timer, dfn[MAXN], cnt, num[MAXN];

bool instack[MAXN]; ll online;
int Timer, Dfn[MAXN], Low[MAXN];
int top, Stack[MAXN], tot, belong[MAXN];
void tarjan(int pos, int fa) {
	Low[pos] = Dfn[pos] = ++Timer;
	Stack[++top] = pos;
	instack[pos] = true;
	for (unsigned i = 0; i < c[pos].size(); i++) {
		if (d[pos][i] == fa) continue;
		if (Dfn[c[pos][i]] == 0) {
			tarjan(c[pos][i], d[pos][i]);
			Low[pos] = min(Low[pos], Low[c[pos][i]]);
		} else if (instack[c[pos][i]]) Low[pos] = min(Low[pos], Dfn[c[pos][i]]);
	}
	if (Low[pos] == Dfn[pos]) {
		int tmp = Stack[top--];
		belong[tmp] = ++tot;
		instack[tmp] = false;
		while (tmp != pos) {
			tmp = Stack[top--];
			belong[tmp] = tot;
			instack[tmp] = false;
		}
	}
}

int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
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
void addedge(int x, int y) {
	static int ind = 0; ind++;
	c[x].push_back(y);
	d[x].push_back(ind);
	c[y].push_back(x);
	d[y].push_back(ind);
}
inline int func(int x) {
	x = (x + online) % n;
	if (x == 0) x = n;
	return x;
}
void solve(int task) {
	static int vis[MAXN], points[MAXN];
	static int pos[MAXN], x[MAXN], y[MAXN];
	int n, m, cnt = 0; read(n), read(m);
	auto mark = [&] (int x) {
		if (vis[x] != task) {
			vis[x] = task;
			points[++cnt] = x;
		}
		if (vis[num[x]] != task) {
			vis[num[x]] = task;
			points[++cnt] = num[x];
		}
	};
	for (int i = 1; i <= n; i++) {
		read(pos[i]), pos[i] = func(pos[i]);
		mark(pos[i] = find(pos[i]));
	}
	for (int i = 1; i <= m; i++) {
		read(x[i]), read(y[i]);
		x[i] = func(x[i]);
		y[i] = func(y[i]);
		mark(x[i] = find(x[i]));
		mark(y[i] = find(y[i]));
	}
	sort(points + 1, points + cnt + 1, [&] (int x, int y) {return dfn[x] < dfn[y];});
	int top = 0, cmt = cnt; static int Stack[MAXN];
	for (int i = 1; i <= cnt; i++) {
		int x = points[i];
		if (num[points[i - 1]] != num[points[i]]) {
			while (top >= 2) {
				addedge(Stack[top], Stack[top - 1]);
				top--;
			}
			Stack[top = 1] = x;
		} else {
			while (top >= 2 && depth[lca(x, Stack[top])] <= depth[Stack[top - 1]]) {
				addedge(Stack[top], Stack[top - 1]);
				top--;
			}
			if (lca(x, Stack[top]) == Stack[top]) Stack[++top] = x;
			else {
				int y = lca(x, Stack[top]);
				points[++cmt] = y;
				addedge(Stack[top], y);
				Stack[top] = y;
				Stack[++top] = x;
			}
		}
	}
	while (top >= 2) {
		addedge(Stack[top], Stack[top - 1]);
		top--;
	}
	for (int i = 1; i <= m; i++)
		addedge(x[i], y[i]);
	for (int i = 1; i <= cnt; i++)
		if (Dfn[points[i]] == 0) tarjan(points[i], 0);
	bool ans = true;
	for (int i = 1; i <= n; i++)
		ans &= belong[pos[i]] == belong[pos[1]];
	if (ans) puts("YES"), online += task;
	else puts("NO");
	
	tot = Timer = 0;
	for (int i = 1; i <= cmt; i++) {
		c[points[i]].clear();
		d[points[i]].clear();
		Dfn[points[i]] = 0;
	}
}
void dfs(int pos, int fa) {
	father[pos][0] = fa;
	depth[pos] = depth[fa] + 1;
	for (auto x : a[pos])
		if (x != fa) dfs(x, pos);
}
void work(int pos, int fa, int cur) {
	depth[pos] = depth[fa] + 1;
	father[pos][0] = fa;
	dfn[pos] = ++timer, num[pos] = cur;
	for (int i = 1; i < MAXLOG; i++)
		father[pos][i] = father[father[pos][i - 1]][i - 1];
	for (unsigned i = 0; i < b[pos].size(); i++)
		if (b[pos][i] != fa) work(b[pos][i], pos, cur);
}
int main() {
	read(n), read(m), read(q);
	for (int i = 1; i <= n; i++)
		f[i] = i;
	static bool non[MAXN];
	for (int i = 1; i <= m; i++) {
		read(x[i]), read(y[i]);
		int tx = find(x[i]);
		int ty = find(y[i]);
		if (tx == ty) non[i] = true;
		else {
			f[tx] = ty;
			a[x[i]].push_back(y[i]);
			a[y[i]].push_back(x[i]);
		}
	}
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= n; i++)
		if (father[i][0] == 0) dfs(i, 0);
	for (int i = 1; i <= m; i++)
		if (non[i]) {
			int tx = find(x[i]), ty = find(y[i]);
			while (tx != ty) {
				if (depth[tx] < depth[ty]) swap(tx, ty);
				f[tx] = find(father[tx][0]), tx = find(tx);
			}
		}
	for (int i = 1; i <= n; i++)
	for (auto x : a[i]) if (find(i) != find(x)) b[find(i)].push_back(find(x));
	for (int i = 1; i <= n; i++)
		if (find(i) == i && dfn[i] == 0) {
			work(i, 0, i);
		}
	for (int i = 1; i <= q; i++)
		solve(i);
	return 0;
}