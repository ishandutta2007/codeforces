#include <bits/stdc++.h>
using namespace std;

const int N = 1<<16;

vector<int> adj[N];

namespace Dinic {
    using F = int;

	const F INF = 1e9+1e8;
	const int N = 222222;
	const int M = 1111111;

	int fst[N], nxt[M], to[M];

	F cap[M];

	int dis[N], q[N], ptr[N];
	int V, E;

	void init() {
		memset(fst, -1, sizeof fst);
		V = E = 0;
	}

	inline int add_node() { V++; return V-1; }

	inline void add_edge(int u, int v, F c) {
		to[E] = v, cap[E] = c, nxt[E] = fst[u], fst[u] = E++;
		to[E] = u, cap[E] = 0, nxt[E] = fst[v], fst[v] = E++;
	}

	inline bool bfs(int S, int T, int n) {
		memset(dis, -1, sizeof(int) * n);
		int h = 0, t = 0;
		dis[S] = 0, q[t++] = S;
		while (h < t) {
			int u = q[h++];
			for (int e = fst[u]; ~e; e = nxt[e]) if (cap[e] > 0 && dis[to[e]] == -1) {
				dis[to[e]] = dis[u] + 1, q[t++] = to[e];
				if (to[e] == T) return 1;
			}
		}
		return (dis[T] != -1);
	}

	F dfs(int u, int T, F f) {
		if (u == T) return f;
		for (int &e = ptr[u]; ~e; e = nxt[e]) if (cap[e] > 0 && dis[to[e]] > dis[u]) {
			F ret = dfs(to[e], T, min(f, cap[e]));
			if (ret > 0) {
				cap[e] -= ret, cap[e ^ 1] += ret;
				return ret;
			}
		}
		return 0;
	}

	F max_flow(int S, int T, int n = V) {
		F ret = 0;
		while (bfs(S, T, n)) {
			memcpy(ptr, fst, sizeof(int) * n);
			for (F cur; (cur = dfs(S, T, INF)) > 0; ret += cur);
		}
		return ret;
	}

    F min_cut(int S, int T, int *ans, int n = V) {
		F ret = max_flow(S, T, n);
		for (int i = 0; i < n; i++) ans[i] = (dis[i] != -1);
		return ret;
	}
}

int a[N], b[N], ans[N], x[N], y[N], sz[N], dp[N], pid[N], st[N], E[N], node[N], qnode[N], edge[N], hd[N], par[N];
const int inf = Dinic::INF;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        a[i] = u, b[i] = v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int u, int p) {
        sz[u] = 1;
        dp[u] = dp[p] + 1;
        par[u] = p;
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            sz[u] += sz[v];
        }
    };
    int T = 0, pn = 0;
    function<void(int, int)> hld = [&](int u, int p) {
        st[u] = ++T;
        if (!hd[pn]) hd[pn] = u;
        pid[u] = pn;
        int w = 0;
        for (int v : adj[u]) {
            if (v == p) continue;
            if (w == 0 || sz[v] > sz[w]) w = v;
        }
        if (w) hld(w, u);
        for (int v : adj[u]) {
            if (v == p || v == w) continue;
            ++pn;
            hld(v, u);
        }
    };
    dfs(1, 0);
    hld(1, 0);
    for (int i = 1; i < n; i++) {
        if (dp[a[i]] < dp[b[i]]) swap(a[i], b[i]);
        E[a[i]] = i;
    }
    Dinic::init();
    int source = Dinic::add_node();
    int sink = Dinic::add_node();
    function<void(int, int, int)> build = [&](int u, int l, int r) {
        node[u] = Dinic::add_node();
        if (l == r) {
            edge[l] = node[u];
            Dinic::add_edge(node[u], sink, 1);
            return;
        }
        int mid = l + r >> 1;
        build(u + u, l, mid);
        build(u + u + 1, mid + 1, r);
        Dinic::add_edge(node[u], node[u + u], inf);
        Dinic::add_edge(node[u], node[u + u + 1], inf);
    };
    build(1, 1, n);
    function<void(int, int, int, int, int, int)> add = [&](int u, int l, int r, int ll, int rr, int x) {
        assert(ll > 1);
        if (ll <= l && r <= rr) {
            Dinic::add_edge(x, node[u], inf);
            return;
        }
        int mid = l + r >> 1;
        if (ll <= mid) add(u + u, l, mid, ll, rr, x);
        if (mid < rr) add(u + u + 1, mid + 1, r, ll, rr, x);
    };
    auto paint = [&](int r, int u, int v) {
        while (pid[u] != pid[v]) {
            int x = hd[pid[u]], y = hd[pid[v]];
            if (dp[x] < dp[y]) swap(u, v), swap(x, y);
            add(1, 1, n, st[x], st[u], r);
            u = par[x];
        }
        if (dp[u] < dp[v]) swap(u, v);
        if (u != v) add(1, 1, n, st[v] + 1, st[u], r);
    };
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        qnode[i] = Dinic::add_node();
        Dinic::add_edge(source, qnode[i], 1);
        paint(qnode[i], x[i], y[i]);
    }
    int ret = Dinic::min_cut(source, sink, ans);
    vector<int> A, B;
    for (int i = 0; i < m; i++) if (!ans[qnode[i]]) A.push_back(i+1);
    for (int i = 1; i <= n; i++) if (ans[edge[st[i]]]) B.push_back(E[i]);
    cout << ret << endl;
    cout << A.size();
    for (int x : A) cout << ' ' << x;
    cout << endl;
    cout << B.size();
    for (int x : B) cout << ' ' << x;
    cout << endl;
    return 0;
}