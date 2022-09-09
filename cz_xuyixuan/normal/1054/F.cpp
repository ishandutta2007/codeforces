#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;
const int MAXP = 2e3 + 5;
const int INF = 1e9;
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
vector <edge> a[MAXP]; unsigned curr[MAXP];
int tot, s, t, dist[MAXP];
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
int n, x[MAXN], y[MAXN], r[MAXN], d[MAXN];
int pd[MAXN], pr[MAXN];
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(x[i]), read(y[i]);
	s = 0, t = tot = 1;
	int ans = n * 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i] == x[j] && y[j] < y[i] && (d[i] == 0 || y[j] > y[d[i]])) d[i] = j;
			if (y[i] == y[j] && x[j] > x[i] && (r[i] == 0 || x[j] < x[r[i]])) r[i] = j;
		}
		if (d[i]) pd[i] = ++tot, ans--, addedge(s, tot, 1);
		if (r[i]) pr[i] = ++tot, ans--, addedge(tot, t, 1);
	}
	for (int i = 1; i <= n; i++) {
		if (!d[i]) continue;
		for (int j = 1; j <= n; j++) {
			if (!r[j]) continue;
			int px = x[i], py = y[j];
			if (px > x[j] && px < x[r[j]] && py > y[d[i]] && py < y[i]) addedge(pd[i], pr[j], INF);
		}
	}
	while (bfs()) {
		memset(curr, 0, sizeof(curr));
		ans += dinic(s, INF);
	}
	cerr << ans << endl;
	static vector <pair <int, int> > from, to;
	static bool head[MAXN];
	memset(head, true, sizeof(head));
	from.clear(), to.clear();
	for (int i = 1; i <= n; i++) {
		if (r[i] && dist[pr[i]] != 0) r[i] = 0;
		if (r[i]) head[r[i]] = false;
	}
	for (int i = 1; i <= n; i++) {
		if (!head[i]) continue;
		int pos = i;
		while (r[pos]) pos = r[pos];
		from.emplace_back(x[i], y[i]);
		to.emplace_back(x[pos], y[pos]);
	}
	writeln(from.size());
	for (unsigned i = 0; i < from.size(); i++)
		printf("%d %d %d %d\n", from[i].first, from[i].second, to[i].first, to[i].second);
	memset(head, true, sizeof(head));
	from.clear(), to.clear();
	for (int i = 1; i <= n; i++) {
		if (d[i] && dist[pd[i]] == 0) d[i] = 0;
		if (d[i]) head[d[i]] = false;
	}
	for (int i = 1; i <= n; i++) {
		if (!head[i]) continue;
		int pos = i;
		while (d[pos]) pos = d[pos];
		from.emplace_back(x[i], y[i]);
		to.emplace_back(x[pos], y[pos]);
	}
	writeln(from.size());
	for (unsigned i = 0; i < from.size(); i++)
		printf("%d %d %d %d\n", from[i].first, from[i].second, to[i].first, to[i].second);
	return 0;
}