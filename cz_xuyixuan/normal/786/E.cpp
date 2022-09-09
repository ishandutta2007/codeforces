#include<bits/stdc++.h>
using namespace std;
const int MAXP = 4e5 + 5;
const int MAXN = 2e4 + 5;
const int MAXLOG = 16;
const int INF = 2e9;
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
struct edge {int dest, flow; unsigned pos; };
vector <edge> a[MAXP];
int n, m, s, t, dist[MAXP];
unsigned curr[MAXP];
vector <int> b[MAXN], home[MAXN];
int tot, point[MAXN][MAXLOG], pos[MAXN];
int depth[MAXN], father[MAXN][MAXLOG];
void addedge(int x, int y, int z) {
	a[x].push_back((edge) {y, z, a[y].size()});
	a[y].push_back((edge) {x, 0, a[x].size() - 1});
}
int dinic(int pos, int limit) {
	if (pos == t) return limit;
	int used = 0, tmp;
	for (unsigned &i = curr[pos]; i < a[pos].size(); i++)
		if (a[pos][i].flow != 0 && dist[pos] + 1 == dist[a[pos][i].dest] && (tmp = dinic(a[pos][i].dest, min(limit - used, a[pos][i].flow)))) {
			used += tmp;
			a[pos][i].flow -= tmp;
			a[a[pos][i].dest][a[pos][i].pos].flow += tmp;
			if (used == limit) return used;
		}
	return used;
}
bool bfs() {
	static int q[MAXP];
	int l = 0, r = 0;
	memset(dist, 0, sizeof(dist));
	dist[s] = 1, q[0] = s;
	while (l <= r) {
		int tmp = q[l];
		for (unsigned i = 0; i < a[tmp].size(); i++)
			if (dist[a[tmp][i].dest] == 0 && a[tmp][i].flow != 0) {
				q[++r] = a[tmp][i].dest;
				dist[q[r]] = dist[tmp] + 1;
			}
		l++;
	}
	return dist[t] != 0;
}
void work(int pos, int fa) {
	depth[pos] = depth[fa] + 1;
	father[pos][0] = fa;
	for (int i = 1; i < MAXLOG; i++) {
		father[pos][i] = father[father[pos][i - 1]][i - 1];
		if (father[pos][i]) {
			point[pos][i] = ++tot;
			addedge(point[pos][i], point[pos][i - 1], INF);
			addedge(point[pos][i], point[father[pos][i - 1]][i - 1], INF);
		}
	}
	for (unsigned i = 0; i < b[pos].size(); i++)
		if (b[pos][i] != fa) {
			point[b[pos][i]][0] = home[pos][i];
			work(b[pos][i], pos);
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
int main() {
	read(n), read(m);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		b[x].push_back(y);
		home[x].push_back(i);
		b[y].push_back(x);
		home[y].push_back(i);
	}
	s = 0, tot = n - 1;
	work(1, 0);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		int z = lca(x, y);
		pos[i] = ++tot;
		addedge(s, pos[i], 1);
		for (int j = MAXLOG - 1; j >= 0; j--)
			if (depth[father[x][j]] >= depth[z]) {
				addedge(pos[i], point[x][j], INF);
				x = father[x][j];
			}
		for (int j = MAXLOG - 1; j >= 0; j--)
			if (depth[father[y][j]] >= depth[z]) {
				addedge(pos[i], point[y][j], INF);
				y = father[y][j];
			}
	}
	t = ++tot;
	for (int i = 1; i <= n - 1; i++)
		addedge(i, t, 1);
	int ans = 0;
	while (bfs()) {
		memset(curr, 0, sizeof(curr));
		ans += dinic(s, INF);
	}
	printf("%d\n", ans);
	bfs(); int size = 0;
	for (int i = 1; i <= m; i++)
		if (dist[pos[i]] == 0) size++;
	printf("%d ", size);
	for (int i = 1; i <= m; i++)
		if (dist[pos[i]] == 0) printf("%d ", i);
	printf("\n");
	size = 0;
	for (int i = 1; i <= n - 1; i++)
		if (dist[i] != 0) size++;
	printf("%d ", size);
	for (int i = 1; i <= n - 1; i++)
		if (dist[i] != 0) printf("%d ", i);
	printf("\n");
	return 0;
}