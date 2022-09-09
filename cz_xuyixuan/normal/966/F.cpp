#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const long long bnd = 1e8;
const long long INF = 1e18;
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
struct edge {int dest; long long flow; unsigned home; };
vector <edge> a[MAXN];
int s, t, n, m, x[MAXN], y[MAXN], dist[MAXN];
long long lk[MAXN], lb[MAXN], rk[MAXN], rb[MAXN];
unsigned curr[MAXN];
long long dinic(int pos, long long limit) {
	if (pos == t) return limit;
	long long used = 0;
	for (unsigned &i = curr[pos]; i < a[pos].size(); i++)
		if (a[pos][i].flow != 0 && dist[pos] + 1 == dist[a[pos][i].dest]) {
			long long tmp = dinic(a[pos][i].dest, min(limit - used, a[pos][i].flow));
			used += tmp;
			a[pos][i].flow -= tmp;
			a[a[pos][i].dest][a[pos][i].home].flow += tmp;
			if (limit == used) return used;
		}
	return used;
}
bool bfs() {
	static int q[MAXN], l, r;
	for (int i = 0; i <= t; i++)
		dist[i] = 0;
	dist[s] = 1, q[l = r = 0] = s;
	while (l <= r) {
		int tmp = q[l++];
		for (unsigned i = 0; i < a[tmp].size(); i++)
			if (dist[a[tmp][i].dest] == 0 && a[tmp][i].flow != 0) {
				dist[a[tmp][i].dest] = dist[tmp] + 1;
				q[++r] = a[tmp][i].dest;
			}
	}
	return dist[t] != 0;
}
void addedge(int s, int t, long long x) {
	a[s].push_back((edge) {t, x, a[t].size()});
	a[t].push_back((edge) {s, 0, a[s].size() - 1});
}
void addedge(int x, int y, long long l, long long r) {
	addedge(s, y, l);
	addedge(x, y, r - l);
	addedge(x, t, l);
}
long long f(long long val) {
	long long diff = 0;
	s = 0, t = n + 1;
	for (int i = s; i <= t; i++)
		a[i].clear();
	for (int i = 1; i <= m; i++) {
		addedge(x[i], y[i], lk[i] * val + lb[i], rk[i] * val + rb[i]);
		diff += lk[i] * val + lb[i];
	}
	while (bfs()) {
		memset(curr, 0, sizeof(curr));
		diff -= dinic(s, INF);
	}
	return diff;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(x[i]), read(y[i]);
		read(lk[i]), read(lb[i]), lb[i] *= bnd;
		read(rk[i]), read(rb[i]), rb[i] *= bnd;
	}
	long long l = 0, r = bnd;
	while (l + 5 < r) {
		long long ml = (2 * l + r) / 3;
		long long mr = (l + 2 * r) / 3;
		if (f(ml) < f(mr)) r = mr;
		else l = ml; 
	}
	long long mid = l;
	for (int i = l; i <= r; i++)
		if (f(i) == 0) mid = i;
	l = 0, r = mid;
	while (l < r) {
		long long md = (l + r) / 2;
		if (f(md) == 0) r = md;
		else l = md + 1;
	}
	long long ql = l;
	l = mid, r = 1;
	while (l < r) {
		long long md = (l + r + 1) / 2;
		if (f(md) == 0) l = md;
		else r = md - 1;
	}
	long long qr = l;
	printf("%.10lf\n", (double) (qr - ql) / bnd);
	return 0;
}