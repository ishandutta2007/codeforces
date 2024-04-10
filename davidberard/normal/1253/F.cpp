#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

struct edge {
    int u, v;
    ll cost;
    edge() {}
    edge(int a, int b, ll c) : u(a), v(b), cost(c) {}
    bool operator < (const edge& o) const {
        return cost < o.cost;
    }
};

const ll INFLL = 0x3f3f3f3f3f3f3f3f;

ll ans[300300];

vector<pii> adj[100100];
vector<edge> edges;
int n, m, k, q;
ll dist[100100];

void dijkstra() {
    memset(dist, INFLL, sizeof dist);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i=1; i<=k; ++i) {
        dist[i] = 0;
        pq.push(pii(0, i));
    }
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int u = p.second;
        ll dst = p.first;
        if (dst > dist[u]) continue;
        for (auto& q : adj[u]) {
            int v = q.first;
            ll c = q.second;
            ll ndst = dst + c;
            if (ndst < dist[v]) {
                dist[v] = ndst;
                pq.push(pii(dist[v], v));
            }
        }
    }
}

int par[100100];
unordered_set<int> have[100100];

void setup() {
    for (int i=0; i<100100; ++i) {
        par[i] = -1;
    }
}

int FIND(int u) {
    if (par[u] == -1) return u;
    return par[u] = FIND(par[u]);
}

void UNION(int u, int v, ll cost) {
    if (FIND(u) == FIND(v)) return;
    if (have[FIND(u)].size() < have[FIND(v)].size()) swap(u, v);
    int uu = FIND(u), vv = FIND(v);

    for (auto& x : have[vv]) {
        if (have[uu].count(x)) {
            have[uu].erase(x);
            assert(ans[x] == 0);
            ans[x] = cost;
        } else {
            have[uu].insert(x);
        }
    }

    par[vv] = uu;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    cin >> n >> m >> k >> q;
    for (int i=0; i<m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.emplace_back(u, v, c);
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }
    for (int i=0; i<q; ++i) {
        int a, b;
        cin >> a >> b;
        have[a].insert(i);
        have[b].insert(i);
    }

    dijkstra();
    for (int i=0; i<m; ++i) {
        edges[i].cost += dist[edges[i].u] + dist[edges[i].v];
    }
    sort(edges.begin(), edges.end());

    for (auto& e : edges) {
        UNION(e.u, e.v, e.cost);
    }

    for (int i=0; i<q; ++i) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}