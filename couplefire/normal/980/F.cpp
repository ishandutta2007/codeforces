#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define pii pair<int, int>
#define fi first
#define sc second

const int N = 5e5 + 5;

int n, m;
vector< pii > *g;
vector< vector<int> > cir;
int cis[N], maxl[N], L[N], Z[N];
boolean vis[N], ib[N << 1];	// is it a bridge

inline void init() {
	scanf("%d%d", &n, &m);
	g = new vector<pii>[(n + 1)];
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		g[u].push_back(pii(v, i));
		g[v].push_back(pii(u, i));
	}
}

int ts = 0;
int dfn[N], low[N];
void tarjan(int p, int fa) {
	dfn[p] = low[p] = ++ts;
	for (int i = 0; i < g[p].size(); i++) {
		pii e = g[p][i];
		if (e.fi == fa)	continue;
		if (!dfn[e.fi]) {
			tarjan(e.fi, p);
			low[p] = min(low[p], low[e.fi]);
			if (low[e.fi] == dfn[e.fi])
				ib[e.sc] = true;
		} else
			low[p] = min(low[p], dfn[e.fi]);
	}
}

void dfs(int p) {
	vis[p] = true;
	cir.back().push_back(p);
	cis[p] = (signed) cir.size() - 1;
	for (int i = 0; i < g[p].size(); i++) {
		pii e = g[p][i];	
		if (!vis[e.fi] && !ib[e.sc])
			dfs(e.fi);
	}
}

queue<int> que;
void bfs(int s) {
	int tp = 0;
	int *tr = new int[(n + 1)];
	int *par = new int[(n + 1)];
	que.push(s);
	memset(vis, false, sizeof(vis));
	tr[++tp] = s, par[s] = 0, vis[s] = true;
	while (!que.empty()) {
		int e = que.front();
		que.pop();
		for (int i = 0; i < g[e].size(); i++) {
			pii eu = g[e][i];
			if (vis[eu.fi])	continue;
			vis[eu.fi] = true;
			tr[++tp] = eu.fi, par[eu.fi] = e;
			assert(eu.fi != s);
			que.push(eu.fi);
		}
	}
	
	for (int i = n; i > 1; i--) {
		int p = tr[i];
		for (int j = 0; j < g[p].size(); j++) {
			pii e = g[p][j];
			if (e.fi == par[p]) {
				maxl[e.fi] = max(maxl[e.fi], maxl[p] + 1);
				if (ib[e.sc])
					L[e.fi] = max(L[e.fi], maxl[p] + 1);
				break;
			}
		}
	}
	delete[] tr;
	delete[] par;
}

int ql, qr;
pii ar[N << 1];
void deal(int p, int fa, int upval) {
	L[p] = max(L[p], upval);
	vector<int> &circ = cir[cis[p]];
	int k = (signed) circ.size(), lim = k >> 1;
	for (int it = 0; it < 2; it++) {
		ql = 1, qr = 0;
		for (int i = 0, e; i < 2 * k; i++) {
			e = circ[i % k];
			while (ql <= qr && i - ar[ql].sc > lim)
				ql++;
			if (ql <= qr)
				Z[e] = max(Z[e], i + ar[ql].fi);
			while (ql <= qr && ar[qr].fi <= L[e] - i)
				qr--;
			ar[++qr] = pii(L[e] - i, i);
		}
		reverse(circ.begin(), circ.end());
	}
	
	for (int i = 0; i < circ.size(); i++) {
		int u = circ[i];
		int fiv = 0, scv = 0;
		for (int j = 0; j < g[u].size(); j++) {
			pii e = g[u][j];
			if (e.fi != fa && ib[e.sc]) {
				if (maxl[e.fi] + 1 > fiv)
					scv = maxl[e.fi] + 1, swap(scv, fiv);
				else if (maxl[e.fi] + 1 > scv)
					scv = maxl[e.fi] + 1;
			}
		}
		
		for (int j = 0; j < g[u].size(); j++) {
			pii e = g[u][j];
			if (e.fi != fa && ib[e.sc]) {
				int pv = max(Z[u], upval), val = maxl[e.fi] + 1;
				if (val == fiv)
					pv = max(pv, scv);
				else
					pv = max(pv, fiv);
				deal(e.fi, u, pv + 1);
			}	
		}
	}
}

inline void solve() {
	tarjan(1, 0);
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			cir.push_back(vector<int>());
			dfs(i);
		}
	bfs(1);
	deal(1, 0, 0);
	for (int i = 1; i <= n; i++)
		printf("%d ", max(L[i], Z[i]));
}

int main() {
	init();
	solve();
	return 0;
}