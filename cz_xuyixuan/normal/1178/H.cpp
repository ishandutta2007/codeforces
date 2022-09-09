#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int INF  = 1e9;
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
int n, a[MAXN], b[MAXN], p[MAXN]; ll value[MAXN];
bool cmp(int x, int y) {
	if (b[x] == b[y]) {
		if (x <= n && y <= n) return value[x] > value[y];
		else return x > y;
	} else return b[x] < b[y];
}
bool cnp(int x, int y) {
	if (value[x] == value[y]) return x > y;
	else return value[x] < value[y];
}
bool check(int mid) {
	for (int i = 1; i <= 2 * n; i++)
		value[i] = b[i] + 1ll * a[i] * mid;
	for (int i = 1; i <= 2 * n; i++) p[i] = i;
	sort(p + 1, p + 2 * n + 1, cmp); ll pre = -1;
	for (int i = 1; i <= 2 * n; i++) {
		int pos = p[i];
		chkmax(pre, b[pos] + 1ll * a[pos] * mid);
		if (pos <= n) value[pos] = pre;
	}
	for (int i = 1; i <= 2 * n; i++) p[i] = i;
	sort(p + 1, p + 2 * n + 1, cnp);
	for (int i = 1, val = 0; i <= 2 * n; i++) {
		int pos = p[i];
		if (pos <= n) val++; else val--;
		if (val > 0) return false; 
	}
	return true;
}
namespace MincostFlow {
	const int MAXP = 12005;
	const int MAXQ = 2e5 + 5;
	struct edge {int dest, flow, pos, cost; };
	vector <edge> a[MAXP];
	int n, m, s, t, tot, flow, cost;
	int dist[MAXP], path[MAXP], home[MAXP];
	void FlowPath() {
		int p = t, ans = INF;
		while (p != s) {
			ans = min(ans, a[path[p]][home[p]].flow);
			p = path[p];
		}
		flow += ans;
		cost += ans * dist[t];
		p = t;
		while (p != s) {
			a[path[p]][home[p]].flow -= ans;
			a[p][a[path[p]][home[p]].pos].flow += ans;
			p = path[p];
		}
	}
	bool spfa() {
		static int q[MAXQ];
		static bool inq[MAXP];
		static int l = 0, r = 0;
		for (int i = 0; i <= r; i++)
			dist[q[i]] = INF;
		q[l = r = 0] = s, dist[s] = 0, inq[s] = true;
		while (l <= r) {
			int tmp = q[l];
			for (unsigned i = 0; i < a[tmp].size(); i++)
				if (a[tmp][i].flow != 0 && dist[tmp] + a[tmp][i].cost < dist[a[tmp][i].dest]) {
					dist[a[tmp][i].dest] = dist[tmp] + a[tmp][i].cost;
					path[a[tmp][i].dest] = tmp;
					home[a[tmp][i].dest] = i;
					if (!inq[a[tmp][i].dest]) {
						q[++r] = a[tmp][i].dest;
						inq[q[r]] = true;
					}
				}
			l++, inq[tmp] = false;
		}
		return dist[t] != INF;
	}
	void addedge(int x, int y, int z, int c) {
		a[x].push_back((edge){y, z, a[y].size(), c});
		a[y].push_back((edge){x, 0, a[x].size() - 1, -c});
	}
	int work(int n) {
		for (int i = 1; i <= n; i++)
			dist[i] = INF;
		while (spfa()) FlowPath();
		return cost;
	}
}
int findans(int mid) {
	MincostFlow :: s = 5 * n + 1;
	MincostFlow :: t = 5 * n + 2;
	for (int i = 1; i <= 2 * n; i++)
		value[i] = b[i] + 1ll * a[i] * mid;
	for (int i = 1; i <= n; i++) {
		MincostFlow :: addedge(MincostFlow :: s, i, 1, 0);
		MincostFlow :: addedge(i + n, MincostFlow :: t, 1, 0);
	}
	for (int i = 1; i <= 2 * n; i++) p[i] = i;
	sort(p + 1, p + 2 * n + 1, cmp);
	int last = 0; ll pre = -1;
	for (int i = 1; i <= 2 * n; i++) {
		int pos = p[i];
		chkmax(pre, b[pos] + 1ll * a[pos] * mid);
		if (pos <= n) {
			if (last != 0) MincostFlow :: addedge(pos, last + n, INF, 1);
			value[pos] = pre;
		} else {
			if (last != 0) MincostFlow :: addedge(pos + n, last + n, INF, 0);
			MincostFlow :: addedge(pos + n, pos, INF, 0);
			last = pos;
		}
	}
	for (int i = 1; i <= 2 * n; i++) p[i] = i;
	sort(p + 1, p + 2 * n + 1, cnp), last = 0;
	for (int i = 1; i <= 2 * n; i++) {
		int pos = p[i];
		if (pos <= n) {
			if (last != 0) MincostFlow :: addedge(pos, last + 2 * n, INF, 2);
		} else {
			if (last != 0) MincostFlow :: addedge(pos + 2 * n, last + 2 * n, INF, 0);
			MincostFlow :: addedge(pos + 2 * n, pos, INF, 0);
			last = pos;
		}
	}
	for (int i = 1; i <= n; i++)
		value[i] = b[i] + 1ll * a[i] * mid;
	for (int i = 1; i <= 2 * n; i++) p[i] = i;
	sort(p + 1, p + 2 * n + 1, cnp), last = 0;
	for (int i = 1; i <= 2 * n; i++) {
		int pos = p[i];
		if (pos <= n) {
			if (last != 0) MincostFlow :: addedge(pos, last + 3 * n, INF, 1);
		} else {
			if (last != 0) MincostFlow :: addedge(pos + 3 * n, last + 3 * n, INF, 0);
			MincostFlow :: addedge(pos + 3 * n, pos, INF, 0);
			last = pos;
		}
	}
	return MincostFlow :: work(5 * n + 2);
}
int main() {
	read(n);
	for (int i = 1; i <= 2 * n; i++)
		read(a[i]), read(b[i]);
	int l = 0, r = 1e9 + 7;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	if (l == 1e9 + 7) {
		writeln(-1);
		return 0;
	}
	printf("%d %d\n", l, findans(l));
	return 0;
}