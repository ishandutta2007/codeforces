#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define V vector
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "LINE(" << __LINE__ << ") ->" << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 4e5 + 7;

vi G[N];
int d[N], p[N], pa[N][20], vis[N];

void dfs(int u, int parent = 0, int depth = 0) {
    pa[u][0] = parent, d[u] = depth;
    for(int i = 1; i < 20; i++)
        pa[u][i] = pa[pa[u][i - 1]][i - 1];
    for(int v:G[u]) if(v != parent)
        dfs(v, u, depth + 1);
}

int lca(int x, int y) {
    if(d[x] > d[y]) swap(x, y);
    for(int i = 0; i < 20; i++)
        if((d[y] - d[x]) >> i & 1) {
            y = pa[y][i];
        }
    if(x == y) return x;
    for(int i = 19; i >= 0; i--)
        if(pa[x][i] != pa[y][i])
            x = pa[x][i], y = pa[y][i];
    assert(x != y && pa[x][0] == pa[y][0]);
    return pa[x][0];
}

int dist(int x, int y) {
    int z = lca(x, y);
    return d[x] - d[z] + d[y] - d[z];
}

int up(int x, int k) {
    assert(k <= d[x]);
    for(int i = 0; i < 20; i++)
        if(k >> i & 1)
            x = pa[x][i];
    return x;
}

int walk(int x, int y, int k) { // walk from x toward y k steps
    int z = lca(x, y);
    if(z == x) {
        assert(d[y] - d[x] >= k);
        return up(y, d[y] - d[x] - k);
    }
    if(z == y)
        return up(x, k);
    if(d[x] - d[z] >= k) return up(x, k);
    return walk(z, y, k - (d[x] - d[z]));
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);

    int n, k, r;
    cin >> n >> k >> r;
    auto add_edge = [&] (int a, int b) {
        G[a].PB(b);
        G[b].PB(a);
    };
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        int s = n + i;
        add_edge(u, s);
        add_edge(v, s);
    }

    dfs(1);

    queue<int> q;
    memset(vis, -1, sizeof vis);
    for(int i = 0; i < r; i++) {
        int u;
        cin >> u;
        q.push(u);
        vis[u] = 0;
    }

    function<int(int)> find = [&] (int u) {
        return p[u] == u ? u : p[u] = find(p[u]);
    };
    auto unite = [&] (int x, int y) {
        int rx = find(x), ry = find(y);
        if(rx == ry) return;
        p[rx] = ry;
    };
    for(int i = 1; i <= n * 2 - 1; i++) p[i] = i;

    while(q.size()) {
        int u = q.front(); q.pop();
        if(vis[u] == k) break;
        for(int v:G[u]) {
            unite(u, v);
            if(vis[v] == -1) {
                vis[v] = vis[u] + 1;
                q.push(v);
            }
        }
    }

    int v;
    cin >> v;
    while(v--) {
        int a, b;
        cin >> a >> b;
        if(dist(a, b) <= 2 * k) cout << "YES\n";
        else if(find(walk(a, b, k)) == find(walk(b, a, k))) cout << "YES\n";
        else cout << "NO\n";
    }


}