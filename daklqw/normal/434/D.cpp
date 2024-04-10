#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXNode 36000
#define MAXEdge 1000010
#define MAXN 100
#define MAXM 210
#define int long long
#define INF 0x3f3f3f3f3f3f3f3fLL
#define BIG 3000000000
int head[MAXNode], nxt[MAXEdge], val[MAXEdge], to[MAXEdge], tot = 1, dis[MAXNode], S, T,
	a[MAXN], b[MAXN], c[MAXN], l[MAXN], r[MAXN], u[MAXM], v[MAXM], d[MAXM], n, m, cnt[MAXN][MAXM << 1],
	idx;
inline void addedge(int b, int e, int v, int yes = 0) {
	nxt[++tot] = head[b]; head[b] = tot; to[tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; head[e] = tot; to[tot] = b; val[tot] = 0;
}
inline int f(int id, int x) {return a[id] * x * x + b[id] * x + c[id];}
queue<int>q;
bool bfs() {
	for (int i = S + 1; i <= T; ++i) dis[i] = 0;
	dis[S] = 1; q.push(S);
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i = head[t]; i; i = nxt[i]) 
			if (val[i] && !dis[to[i]]) {
				q.push(to[i]);
				dis[to[i]] = dis[t] + 1;
			}
	}
	return dis[T];
}
int dinic(int u, int minv) {
	if (minv == 0 || u == T) return minv;
	int ans = 0, t;
	for (int i = head[u]; i; i = nxt[i])
		if (val[i] && dis[to[i]] == dis[u] + 1 && (t = dinic(to[i], min(minv, val[i])))) {
			val[i] -= t;
			val[i ^ 1] += t;
			minv -= t;
			ans += t;
			if (!minv) break;
		}
	if (!ans) dis[u] = -1;
	return ans;
}
signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i];
	for (int i = 1; i <= m; ++i) cin >> u[i] >> v[i] >> d[i];
	for (int i = 1; i <= n; ++i)
		for (int j = l[i]; j <= r[i] + 1; ++j)
			cnt[i][j - l[i]] = ++idx;
	S = 0; T = ++idx;
	for (int i = 1; i <= n; ++i) {
		addedge(S, cnt[i][0], INF);
		for (int j = l[i]; j <= r[i]; ++j)
			addedge(cnt[i][j - l[i]], cnt[i][j - l[i] + 1], BIG - f(i, j));
		addedge(cnt[i][r[i] - l[i] + 1], T, INF);
	}
	for (int i = 1; i <= m; ++i)
		for (int j = l[u[i]]; j <= r[u[i]]; ++j)
			if (j - d[i] >= l[v[i]] && j - d[i] <= r[v[i]] + 1)
				addedge(cnt[u[i]][j - l[u[i]]], cnt[v[i]][j - d[i] - l[v[i]]], INF);
	int ans = 0;
	while (bfs()) ans += dinic(S, INF);
	if (BIG * n - ans <= -4000000000000000000LL) cout << "Invalid" << endl;
	else cout << BIG * n - ans << endl;
	return 0;
}