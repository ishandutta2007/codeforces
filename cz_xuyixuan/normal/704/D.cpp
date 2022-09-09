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
namespace NetworkFlow {
	const int INF  = 1e9 + 7;
	const int MAXP = 2e5 + 5;
	struct edge {
		int dest, flow;
		unsigned pos;
	}; vector <edge> a[MAXP];
	int tot, s, t, dist[MAXP];
	unsigned curr[MAXP];
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
	int flow(int x, int y) {
		s = x, t = y;
		int ans = 0;
		while (bfs()) {
			memset(curr, 0, sizeof(curr));
			ans += dinic(s, INF);
		}
		return ans;
	}
}
int n, m, r, b, x[MAXN], y[MAXN];
int cntx[MAXN], cnty[MAXN];
int limx[MAXN], limy[MAXN];
map <int, int> homex, homey;
int main() {
	read(n), read(m), read(r), read(b);
	for (int i = 1; i <= n; i++) {
		int tx, ty; read(tx), read(ty);
		if (homex.count(tx)) x[i] = homex[tx];
		else x[i] = homex[tx] = i;
		if (homey.count(ty)) y[i] = homey[ty];
		else y[i] = homey[ty] = i;
		cntx[x[i]]++, cnty[y[i]]++;
	}
	for (int i = 1; i <= n; i++)
		limx[i] = limy[i] = INF;
	for (int i = 1; i <= m; i++) {
		int opt, l, d; read(opt), read(l), read(d);
		if (opt == 1) chkmin(limx[homex[l]], d);
		else chkmin(limy[homey[l]], d);
	}
	int goal = 0;
	int os = 2 * n + 1, ot = 2 * n + 2;
	int us = 2 * n + 3, ut = 2 * n + 4;
	NetworkFlow :: addedge(ot, os, INF);
	for (int i = 1; i <= n; i++) {
		int l = cntx[i] / 2, r = cntx[i] - cntx[i] / 2, d = limx[i];
		if (cntx[i] & 1) d--; if (d & 1) d--;
		if (d < 0) {
			puts("-1");
			return 0;
		}
		l -= d / 2, r += d / 2;
		chkmax(l, 0), chkmin(r, cntx[i]);
		goal += l;
		NetworkFlow :: addedge(os, i, r - l);
		NetworkFlow :: addedge(us, i, l);
		NetworkFlow :: addedge(os, ut, l);
		
		l = cnty[i] / 2, r = cnty[i] - cnty[i] / 2, d = limy[i];
		if (cnty[i] & 1) d--; if (d & 1) d--;
		if (d < 0) {
			puts("-1");
			return 0;
		}
		l -= d / 2, r += d / 2;
		chkmax(l, 0), chkmin(r, cnty[i]);
		goal += l;
		NetworkFlow :: addedge(i + n, ot, r - l);
		NetworkFlow :: addedge(us, ot, l);
		NetworkFlow :: addedge(i + n, ut, l);
	}
	static unsigned home[MAXN];
	for (int i = 1; i <= n; i++) {
		home[i] = NetworkFlow :: a[x[i]].size();
		NetworkFlow :: addedge(x[i], y[i] + n, 1);
	}
	if (NetworkFlow :: flow(us, ut) < goal) {
		puts("-1");
		return 0;
	}
	cout << 1ll * max(r, b) * n - 1ll * abs(r - b) * NetworkFlow :: flow(os, ot) << endl;
	for (int i = 1; i <= n; i++) {
		bool flg = true;
		if (NetworkFlow :: a[x[i]][home[i]].flow) flg = false;
		else flg = true;
		if (flg ^ (r > b)) putchar('r');
		else putchar('b');
	}
	putchar('\n');
	return 0;
}