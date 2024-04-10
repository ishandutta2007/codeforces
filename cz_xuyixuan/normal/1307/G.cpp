#include<bits/stdc++.h>
using namespace std;
const int MAXN = 55;
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
	const int MAXP = 55;
	const int MAXQ = 2e5 + 5;
	const int INF  = 2e9;
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
	void work(int n, int *res) {
		for (int i = 1; i <= n; i++)
			dist[i] = INF;
		while (spfa()) {
			FlowPath();
			res[flow] = cost;
		}
	}
}
int res[MAXN];
int main() {
	using namespace MincostFlow;
	read(n), read(m), s = 1, t = n;
	for (int i = 1; i <= m; i++) {
		int x, y, z; read(x), read(y), read(z);
		addedge(x, y, 1, z);
	}
	work(n, res);
	int q; read(q);
	while (q--) {
		int c; read(c); double ans = 1e99;
		for (int i = 1; i <= flow; i++)
			chkmin(ans, 1.0 * (c + res[i]) / i);
		printf("%.10lf\n", ans);
	}
	return 0;
}