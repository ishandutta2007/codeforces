#include<bits/stdc++.h>
using namespace std;
#define MAXN	205
#define INF	1e9
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
struct edge {int dest, flow; unsigned home; };
struct treeedge {int dest, index; };
struct info {int x, y, value; };
int n, m, s, t, ans, tot;
int f[MAXN], x[MAXN], y[MAXN];
int dist[MAXN], p[MAXN], q[MAXN];
unsigned curr[MAXN];
info e[MAXN];
vector <edge> a[MAXN];
vector <treeedge> b[MAXN];
vector <int> Ans[MAXN];
bool bfs() {
	memset(dist, 0, sizeof(dist));
	static int q[MAXN];
	int l = 0, r = 0;
	dist[s] = 1, q[0] = s;
	while (l <= r) {
		int tmp = q[l++];
		for (unsigned i = 0; i < a[tmp].size(); i++)
			if (a[tmp][i].flow != 0 && dist[a[tmp][i].dest] == 0) {
				dist[a[tmp][i].dest] = dist[tmp] + 1;
				q[++r] = a[tmp][i].dest;
			}
	}
	return dist[t] != 0;
}
int dinic(int pos, int limit) {
	if (pos == t) return limit;
	int used = 0, tmp;
	for (unsigned &i = curr[pos]; i < a[pos].size(); i++)
		if (a[pos][i].flow != 0 && dist[pos] + 1 == dist[a[pos][i].dest] && (tmp = dinic(a[pos][i].dest, min(limit - used, a[pos][i].flow)))) {
			used += tmp;
			a[pos][i].flow -= tmp;
			a[a[pos][i].dest][a[pos][i].home].flow += tmp;
			if (used == limit) return limit;
		}
	return used;
}
void addedge(int s, int t, int flow) {
	a[s].push_back((edge) {t, flow, a[t].size()});
	a[t].push_back((edge) {s, flow, a[s].size() - 1});
}
void ClearGraph() {
	for (int i = 1; i <= n; i++)
	for (unsigned j = 0; j < a[i].size(); j++)
		a[i][j].flow = a[a[i][j].dest][a[i][j].home].flow = (a[i][j].flow + a[a[i][j].dest][a[i][j].home].flow ) / 2;
}
void solve(int l, int r) {
	if (l == r) return;
	s = p[l], t = p[r];
	int flow = 0;
	ClearGraph();
	while (bfs()) {
		memset(curr, 0, sizeof(curr));
		flow += dinic(s, INF);
	}
	e[++tot] = (info) {s, t, flow};
	int tl = l - 1, tr = r + 1;
	for (int i = l; i <= r; i++)
		if (dist[p[i]]) q[++tl] = p[i];
		else q[--tr] = p[i];
	for (int i = l; i <= r; i++)
		p[i] = q[i];
	solve(l, tl); solve(tr, r);
}
bool cmp(info a, info b) {
	return a.value > b.value;
}
int F(int x) {
	if (f[x] == x) return x;
	else return f[x] = F(f[x]);
}
void dfs(int pos, int fa) {
	printf("%d ", pos);
	for (unsigned i = 0; i < Ans[pos].size(); i++)
		if (Ans[pos][i] != fa) dfs(Ans[pos][i], pos);
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		read(x), read(y), read(z);
		addedge(x, y, z);
	}
	for (int i = 1; i <= n; i++)
		p[i] = i;
	solve(1, n);
	int ans = 0;
	for (int i = 1; i <= tot; i++)
		ans += e[i].value;
	printf("%d\n", ans);
	sort(e + 1, e + tot + 1, cmp);
	for (int i = 1; i <= n; i++)
		f[i] = x[i] = y[i] = i;
	for (int i = 1; i <= tot; i++) {
		int tx = F(e[i].x);
		int ty = F(e[i].y);
		Ans[y[tx]].push_back(x[ty]);
		Ans[x[ty]].push_back(y[tx]);
		f[ty] = tx;
		y[tx] = y[ty];
	}
	for (int i = 1; i <= n; i++)
		if (Ans[i].size() == 1) {
			dfs(i, 0);
			break;
		}
	printf("\n");
	return 0;
}