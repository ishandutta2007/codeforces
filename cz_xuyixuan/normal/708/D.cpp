#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int INF  = 1e9 + 7;
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
namespace MincostFlow {
	const int MAXP = 505;
	const int MAXQ = 2e5 + 5;
	const int INF  = 2e9;
	struct edge {int dest, flow, pos, cost; };
	vector <edge> a[MAXP];
	int n, m, s, t, tot, flow; ll cost;
	int dist[MAXP], path[MAXP], home[MAXP];
	void FlowPath() {
		int p = t, ans = INF;
		while (p != s) {
			ans = min(ans, a[path[p]][home[p]].flow);
			p = path[p];
		}
		flow += ans;
		cost += 1ll * ans * dist[t];
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
	ll work(int n, int x, int y) {
		s = x, t = y;
		for (int i = 1; i <= n; i++)
			dist[i] = INF;
		while (spfa()) FlowPath();
		return cost;
	}
}
int n, m, x[MAXN], y[MAXN], d[MAXN], c[MAXN], f[MAXN];
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(x[i]), read(y[i]);
		read(c[i]), read(f[i]);
		d[x[i]] -= f[i];
		d[y[i]] += f[i];
	}
	int s = n + 1, t = n + 2;
	MincostFlow :: addedge(n, 1, INF, 0);
	for (int i = 1; i <= n; i++) {
		if (d[i] > 0) MincostFlow :: addedge(s, i, d[i], 0);
		else MincostFlow :: addedge(i, t, -d[i], 0);
	}
	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		if (f[i] <= c[i]) {
			MincostFlow :: addedge(y[i], x[i], f[i], 1);
			MincostFlow :: addedge(x[i], y[i], c[i] - f[i], 1);
			MincostFlow :: addedge(x[i], y[i], INF, 2);
		} else {
			ans += f[i] - c[i];
			MincostFlow :: addedge(y[i], x[i], c[i], 1);
			MincostFlow :: addedge(y[i], x[i], f[i] - c[i], 0);
			MincostFlow :: addedge(x[i], y[i], INF, 2);
		}
	}
	cout << ans + MincostFlow :: work(n + 2, s, t) << endl;
	return 0;
}