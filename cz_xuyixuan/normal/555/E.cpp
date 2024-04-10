#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
vector <pair <int, int>> a[MAXN];
int n, m, q, top, tot, Stack[MAXN], belong[MAXN];
int timer, x[MAXN], y[MAXN], dfn[MAXN], low[MAXN], col[MAXN];
void work(int pos, int fa, int c) {
	Stack[++top] = pos, col[pos] = c;
	dfn[pos] = low[pos] = ++timer;
	for (auto x : a[pos])
		if (dfn[x.first] == 0) {
			work(x.first, x.second, c);
			chkmin(low[pos], low[x.first]);
		} else if (x.second != fa) chkmin(low[pos], dfn[x.first]);
	if (dfn[pos] == low[pos]) {
		int tmp = Stack[top--];
		belong[tmp] = ++tot;
		while (tmp != pos) {
			tmp = Stack[top--];
			belong[tmp] = tot;
		}
	}
}
vector <int> b[MAXN];
int depth[MAXN], father[MAXN][MAXLOG];
void dfs(int pos, int fa) {
	father[pos][0] = fa;
	depth[pos] = depth[fa] + 1;
	for (int i = 1; i < MAXLOG; i++)
		father[pos][i] = father[father[pos][i - 1]][i - 1];
	for (unsigned i = 0; i < b[pos].size(); i++)
		if (b[pos][i] != fa) dfs(b[pos][i], pos);
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
bool vis[MAXN];
int sum[MAXN][2];
void getans(int pos, int fa) {
	vis[pos] = true;
	for (auto x : b[pos])
		if (x != fa) {
			getans(x, pos);
			sum[pos][0] += sum[x][0];
			sum[pos][1] += sum[x][1];
		}
	if (sum[pos][0] && sum[pos][1]) {
		puts("No");
		exit(0);
	}
}
int main() {
	read(n), read(m), read(q);
	for (int i = 1; i <= m; i++) {
		read(x[i]), read(y[i]);
		a[x[i]].emplace_back(y[i], i);
		a[y[i]].emplace_back(x[i], i);
	}
	for (int i = 1, j = 0; i <= n; i++)
		if (dfn[i] == 0) work(i, 0, ++j);
	for (int i = 1; i <= m; i++)
		if (belong[x[i]] != belong[y[i]]) {
			b[belong[x[i]]].push_back(belong[y[i]]);
			b[belong[y[i]]].push_back(belong[x[i]]);
		}
	for (int i = 1; i <= tot; i++)
		if (depth[i] == 0) dfs(i, 0);
	for (int i = 1; i <= q; i++) {
		int x, y; read(x), read(y);
		if (col[x] != col[y]) {
			puts("No");
			return 0;
		}
		x = belong[x], y = belong[y];
		int z = lca(x, y);
		sum[x][0]++, sum[z][0]--;
		sum[y][1]++, sum[z][1]--;
	}
	for (int i = 1; i <= tot; i++)
		if (!vis[i]) getans(i, 0);
	puts("Yes");
	return 0;
}