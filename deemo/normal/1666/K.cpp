#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2000 + 20;
const int MAXE = 1e6 + 10;

int from[MAXE], to[MAXE], prv[MAXE], head[MAXN], pt[MAXN], ec;
ll cap[MAXE];

int n, m, col[MAXN];

void add_edge(int u, int v, ll uv, ll vu = 0) {
    from[ec] = u, to[ec] = v, cap[ec] = uv, prv[ec] = head[u], head[u] = ec++;
    from[ec] = v, to[ec] = u, cap[ec] = vu, prv[ec] = head[v], head[v] = ec++;
}

int lv[MAXN], q[MAXN];
bool bfs(int source, int sink) {
    memset(lv, 63, sizeof(lv));
    int h = 0, t = 0;
    lv[source] = 0;
    q[t++] = source;
    while (h < t) {
        int v = q[h++];
        for (int e = head[v]; ~e; e = prv[e])
            if (cap[e] && lv[to[e]] > 1e8) {
                lv[to[e]] = lv[v] + 1;
                q[t++] = to[e];
            }
    }
    return lv[sink] < 1e8;
}

ll dfs(int v, int sink, ll f = 1e17) {
    if (v == sink || f == 0)
        return f;

    ll res = 0;
    for (int &e = pt[v]; ~e; e = prv[e])
        if (cap[e] && lv[v] + 1 == lv[to[e]]) {
            auto tmp = dfs(to[e], sink, min(f, cap[e]));
            cap[e] -= tmp;
            cap[e^1] += tmp;
            res += tmp;
            f -= tmp;
            if (!f)
                break;
        }
    return res;
}

void visit(int v) {
    col[v] = 1;
    for (int e = head[v]; ~e; e = prv[e])
        if (cap[e] && !col[to[e]])
            visit(to[e]);
}

ll dinic(int source, int sink) {
    ll res = 0;
    while (bfs(source, sink)) {
        memcpy(pt, head, sizeof(head));
        res += dfs(source, sink);
    }
    return res;
}

int main() {
    memset(head, -1, sizeof(head));
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int source = n*2, sink = n*2+1;
    int A, B; cin >> A >> B; A--, B--;
    ll INF = 1e17;
    add_edge(source, A<<1, INF, INF);
    add_edge(A<<1^1, sink, INF, INF);
    add_edge(source, B<<1^1, INF, INF);
    add_edge(sink, B<<1, INF, INF);
    while (m--) {
        int u, v, w; cin >> u >> v >> w, u--, v--;
        add_edge(u<<1, v<<1^1, w, w);
        add_edge(u<<1^1, v<<1, w, w);
    }
    cout << dinic(source, sink) << "\n";
    visit(source);
    for (int v = 0; v < n; v++)
        if (col[v<<1] && !col[v<<1^1])
            cout << "A";
        else if (col[v<<1^1] && !col[v<<1])
            cout << "B";
        else
            cout << "C";
    cout << "\n";
    return 0;
}