#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXM = 15;
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
	const int MAXP = 1e2 + 5;
	struct edge {
		int dest, flow;
		unsigned pos;
	}; vector <edge> a[MAXP];
	int cntp, s, t, dist[MAXP];
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
	int flow() {
		int ans = 0;
		while (bfs()) {
			memset(curr, 0, sizeof(curr));
			ans += dinic(s, INF);
		}
		return ans;
	}
}
bool vis[MAXM]; int tot, a[MAXM];
int n, m, bits[MAXN], x[MAXM], y[MAXM];
int Min[MAXM], Max[MAXM], cnt[MAXM], cnte[MAXM][MAXM], num[MAXM][MAXM];
vector <pair <int, int>> ans;
void dfs(int pos, int nxt, int cur) {
	if (cur == m) {
		for (int i = 1; i <= m - 1; i++) {
			if (x[i] > y[i]) swap(x[i], y[i]);
			if (cnte[x[i]][y[i]] == 0) return;
		}
		for (int i = 1; i <= m - 1; i++)
			cnte[x[i]][y[i]]--;
		
		using namespace NetworkFlow;
		s = 0, cntp = m; int goal = 0;
		for (int i = 0; i <= m; i++)
			NetworkFlow :: a[i].clear();
		for (int i = 1; i <= m; i++) {
			addedge(s, i, cnt[i] - 1);
			goal += cnt[i] - 1;
		}
		for (int i = 1; i <= m; i++)
		for (int j = i + 1; j <= m; j++) {
			num[i][j] = ++cntp;
			NetworkFlow :: a[cntp].clear();
			addedge(i, cntp, INF);
			addedge(j, cntp, INF);
		}
		t = ++cntp, NetworkFlow :: a[t].clear();
		for (int i = 1; i <= m; i++)
		for (int j = i + 1; j <= m; j++)
			addedge(num[i][j], t, cnte[i][j]);
		if (flow() == goal) {
			for (int i = 1; i <= m - 1; i++)
				ans.emplace_back(Min[x[i]], Min[y[i]]);
			for (int i = 1; i <= m; i++)
			for (int j = i + 1; j <= m; j++) {
				int p = num[i][j];
				for (auto x : NetworkFlow :: a[p])
					if (x.dest <= m) {
						int used = x.flow, k = (x.dest == i) ? j : i;
						while (used--) ans.emplace_back(Min[k], Max[x.dest]--);
					}
			}
			for (auto x : ans)
				printf("%d %d\n", x.first, x.second);
			exit(0);
		}
		
		for (int i = 1; i <= m - 1; i++)
			cnte[x[i]][y[i]]++;
	} else {
		while (pos <= cur) {
			while (nxt <= m) {
				if (!vis[nxt]) {
					vis[nxt] = true;
					a[++tot] = nxt;
					x[cur] = a[pos];
					y[cur] = nxt;
					dfs(pos, nxt, cur + 1);
					a[tot--] = 0;
					vis[nxt] = false;
				}
				nxt++;
			}
			nxt = 1, pos++;
		}
	}
}
int main() {
	read(n), bits[1] = Min[1] = Max[1] = cnt[1] = 1;
	for (int i = 2; i <= n; i++) {
		bits[i] = bits[i - 1];
		if (bits[i] == bits[i / 10]) {
			bits[i]++;
			Min[bits[i]] = i;
		}
		cnt[bits[i]]++;
		Max[bits[i]] = i;
	} m = bits[n];
	for (int i = 1; i <= n - 1; i++) {
		static char s[MAXM], t[MAXM];
		scanf("\n%s %s", s, t);
		int x = strlen(s);
		int y = strlen(t);
		if (x > y) swap(x, y);
		cnte[x][y]++;
	}
	for (int i = 1; i <= m; i++) {
		while (cnte[i][i]--) {
			if (cnt[i] <= 1) {
				puts("-1");
				return 0;
			}
			cnt[i]--, Max[i]--;
			ans.emplace_back(Max[i], Max[i] + 1);
		}
	}
	vis[1] = true;
	a[tot = 1] = 1;
	dfs(1, 1, 1);
	puts("-1");
	return 0;
}