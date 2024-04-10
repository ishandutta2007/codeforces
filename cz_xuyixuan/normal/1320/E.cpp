#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
int n; vector <int> a[MAXN];
namespace LowestCommonAncestor {
	const int MAXN = 2e5 + 5;
	const int MAXLOG = 20;
	int depth[MAXN], father[MAXN][MAXLOG];
	void work(int pos, int fa) {
		depth[pos] = depth[fa] + 1;
		father[pos][0] = fa;
		for (int i = 1; i < MAXLOG; i++)
			father[pos][i] = father[father[pos][i - 1]][i - 1];
		for (unsigned i = 0; i < a[pos].size(); i++)
			if (a[pos][i] != fa) work(a[pos][i], pos);
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
	int climb(int x, int y) {
		for (int i = 0; y != 0; i++)
			if (y & (1 << i)) {
				y ^= 1 << i;
				x = father[x][i];
			}
		return x;
	}
}
vector <int> b[MAXN];
int q, m, k, u[MAXN], v[MAXN], s[MAXN];
int points[MAXN], cnt, cmt;
int timer, dfn[MAXN], dist[MAXN], home[MAXN];
void addedge(int x, int y) {
	b[x].push_back(y);
	b[y].push_back(x);
}
void build() {
	static int vis[MAXN], task = 0;
	task++, cnt = cmt = 0;
	auto mark = [&] (int x) {
		if (vis[x] != task) {
			vis[x] = task;
			points[++cnt] = x;
		}
	};
	mark(1);
	for (int i = 1; i <= k; i++)
		mark(v[i]);
	for (int i = 1; i <= m; i++)
		mark(u[i]);
	sort(points + 1, points + cnt + 1, [&] (int x, int y) {return dfn[x] < dfn[y];});
	int top = 0; cmt = cnt; static int Stack[MAXN];
	using namespace LowestCommonAncestor;
	for (int i = 1; i <= cnt; i++) {
		int x = points[i];
		while (top >= 2 && depth[lca(x, Stack[top])] <= depth[Stack[top - 1]]) {
			addedge(Stack[top], Stack[top - 1]);
			top--;
		}
		if (top == 0 || lca(x, Stack[top]) == Stack[top]) Stack[++top] = x;
		else {
			int y = lca(x, Stack[top]);
			points[++cmt] = y;
			addedge(Stack[top], y);
			Stack[top] = y;
			Stack[++top] = x;
		}
	}
	while (top >= 2) {
		addedge(Stack[top], Stack[top - 1]);
		top--;
	}
}
void clear() {
	for (int i = 1; i <= cmt; i++)
		b[points[i]].clear();
}
void dfs(int pos, int fa) {
	dfn[pos] = ++timer;
	for (auto x : a[pos])
		if (x != fa) dfs(x, pos);
}
int path(int x, int y) {
	using namespace LowestCommonAncestor; int z = lca(x, y);
	return depth[x] + depth[y] - 2 * depth[z];
}
const int INF = 1e9 + 7;
priority_queue <pair <pair <int, int>, int>, vector <pair <pair <int, int>, int>>, greater <pair <pair <int, int>, int>>> Heap;
void cdist() {
	static int vis[MAXN], task = 0; task++;
	for (int i = 1; i <= cmt; i++) {
		dist[points[i]] = INF;
		home[points[i]] = 0;
	}
	for (int i = 1; i <= k; i++) {
		dist[v[i]] = 0;
		home[v[i]] = i;
		Heap.emplace(make_pair(0, i), v[i]);
	}
	while (!Heap.empty()) {
		pair <pair <int, int>, int> tmp = Heap.top(); Heap.pop();
		if (vis[tmp.second] == task) continue;
		int cur = home[tmp.second];
		for (auto x : b[tmp.second])
			if (vis[x] != task) {
				int len = (path(x, v[cur]) - 1) / s[cur] + 1;
				if (len < dist[x] || len == dist[x] && cur < home[x]) {
					dist[x] = len, home[x] = cur;
					Heap.emplace(make_pair(len, cur), x);
				}
			}
	}
}
int main() {
	read(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	LowestCommonAncestor :: work(1, 0);
	dfs(1, 0), read(q);
	for (int i = 1; i <= q; i++) {
		read(k), read(m);
		for (int i = 1; i <= k; i++)
			read(v[i]), read(s[i]);
		for (int i = 1; i <= m; i++)
			read(u[i]);
		build();
		cdist();
		for (int i = 1; i <= m; i++)
			printf("%d ", home[u[i]]);
		printf("\n");
		clear();
	}
	return 0;
}