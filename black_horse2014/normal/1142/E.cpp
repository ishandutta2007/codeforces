#include <bits/stdc++.h>
using namespace std;

int n, m;
FILE *fin;

const int N = 110000;
set<int> adj[N];
set<int> con[N];
set<int> radj[N];
set<int> rcon[N];
set<int> G[N];

void input() {
#ifdef ONLINE_JUDGE
	fin = stdin;
#else
    fin = fopen("in.txt", "r");
#endif // ONLINE_JUDGE
    fscanf(fin, "%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v; fscanf(fin, "%d%d", &u, &v);
        adj[u].insert(v);
        radj[v].insert(u);
    }
}

int query(int u, int v) {
	static int q = 0;
	q++;
	if (q > 2 * n) throw;
    int ret;
#ifdef ONLINE_JUDGE
    printf("? %d %d\n", u, v);
    fflush(stdout);
    fscanf(fin, "%d", &ret);
#else
	if (u == v) ret = -1;
	else if (adj[u].count(v) || adj[v].count(u)) ret = -1;
	else if (con[u].count(v) || con[v].count(u)) ret = -1;
    else ret = rand() & 1;
#endif // ONLINE_JUDGE
	if (ret == -1) throw;
    if (!ret) swap(u, v);
    con[u].insert(v);
    rcon[v].insert(u);
    return ret;
}

void answer(int u) {
    vector<int> vis(n + 1, 0);
    vector<int> ret(n + 1, 0);
    function<void(set<int> [], int)> dfs = [&](set<int> adj[], int u) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (!vis[v]) dfs(adj, v);
        }
    };
    dfs(adj, u);
    swap(ret, vis);
    dfs(con, u);
    for (int i = 1; i <= n; i++) {
		ret[i] |= vis[i];
        if (!ret[i]) throw;
    }
#ifdef ONLINE_JUDGE
    printf("! %d\n", u);
    fflush(stdout);
#endif
}

void solve() {
    vector<int> vis(n + 1, 0);
    vector<int> que;
    int T = 0;
	function<void(const set<int> [], vector<int>&, int)> dfs = [&](const set<int> adj[], vector<int> &que, int u) {
		vis[u] = T;
        for (int v : adj[u]) if (!vis[v]) dfs(adj, que, v);
        que.push_back(u);
	};
    for (int i = 1; i <= n; i++) if (!vis[i]) T++, dfs(adj, que, i);
    T = 0;
    for (int i = 1; i <= n; i++) vis[i] = 0;
    vector<int> rque;
    for (int i = n-1; i >= 0; i--) if (!vis[que[i]]) T++, dfs(radj, rque, que[i]);
    vector<vector<int> > V(T + 1);
    for (int i = 1; i <= n; i++) V[vis[i]].push_back(i);
    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            if (vis[i] == vis[j]) continue;
            G[vis[i]].insert(vis[j]);
        }
    }
    vector<int> deg(T + 1, 0);
    for (int i = 1; i <= T; i++) {
        for (int j : G[i]) deg[j]++;
    }
    vector<int> q(T);
    int qn = 0;
    for (int i = 1; i <= T; i++) if (!deg[i]) q[qn++] = i;
    int ans = 0;
    for (int i = 0; i < qn; i++) {
        int cur = q[i];
        while (!V[cur].empty() && !V[ans].empty()) {
            int v = V[cur].back();
            int u = V[ans].back();
            if (query(u, v)) {
                V[cur].pop_back();
            } else {
            	V[ans].pop_back();
            }
        }
        if (V[ans].empty()) swap(ans, cur);
        for (int now : G[cur]) {
            if (--deg[now] == 0) q[qn++] = now;
        }
    }
    answer(V[ans].back());
}

int main() {
    input();
    solve();
	return 0;
}