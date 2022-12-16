#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 500500;
int cn = 0;
vector<int> adj[N];
vector<int> in[N];
int comp[N];

int upd[N];
int ans[N];
int f[N];
int vis[N];
int par[N];

int n, m;

void dfs_build(int u, int p) {
    ////cerr << " par " << u << " = " << p << endl;
    par[u] = p;
    vis[u] = 1;
    for (auto& v : adj[u]) {
        if (v == p || comp[v]) continue;
        if (vis[v]) { // cactus!
            int tc = ++cn;
            comp[v] = tc;
            in[tc].push_back(v);
            int x = u;
            while (x != v) {
                comp[x] = tc;
                in[tc].push_back(x);
                x = par[x];
            }
        } else {
            dfs_build(v, u);
        }
    }
}

void cact_react(int tc) {
    int k = in[tc].size();
    priority_queue<pair<int, int>> pq;

    for (int i=0; i<k; ++i) {
        upd[in[tc][i]] = 0;
    }

    //////cerr << endl;
    for (int i=0; i<k*2; ++i) {
        const int &q = in[tc][i%k];
        while (pq.size() && pq.top().second > 2*k-i+k/2) {
            pq.pop();
        }
        //////cerr << " cr " << q << " updw " << pq.top().first-2*k+i << endl;
        if (pq.size()) {
            upd[q] = max(upd[q], pq.top().first-2*k+i);
        }
        pq.push(pair<int, int>(f[q]+2*k-i, 2*k-i));
    }

    pq = priority_queue<pair<int, int>>();
    //////cerr << endl;

    for (int i=0; i<k*2; ++i) {
        const int &q = in[tc][(3*k-i)%k];
        while (pq.size() && pq.top().second > 2*k-i+k/2) {
            pq.pop();
        }
        //////cerr << " cr " << q << " updw " << pq.top().first-2*k+i << endl;
        if (pq.size()) {
            upd[q] = max(upd[q], pq.top().first-2*k+i);
        }
        pq.push(pii(f[q]+2*k-i, 2*k-i));
    }

    for (int i=0; i<k; ++i) {
        ////cerr << " cr " << in[tc][i] << ": " << upd[in[tc][i]] << endl;
    }

    ////cerr << endl;
}

void dfs_below(int u, int p, int cl) {
    vis[u] = 1;
    for (auto& v : adj[u]) {
        if (vis[v]) continue;
        dfs_below(v, u, comp[u]);
    }
    if (cl != comp[u] && comp[u]) {
        cact_react(comp[u]);
        f[u] = upd[u];
    }
    for (auto& v : adj[u]) {
        if (v == p || (comp[u] && comp[u] == comp[v])) continue;
        ////cerr << " marking " << u << " from " << v << endl;
        f[u] = max(f[u], f[v]+1);
    }
    //cerr << "! f[" << u << "] = " << f[u] << endl;
}

struct max2 {
    pair<int, int> first, second;
    max2() : first(0, 0), second(0, 0) {}
    void insert(int x, int y) {
        if (x > first.first) {
            second = first;
            first.first = x;
            first.second = y;
        } else if(x > second.first) {
            second.first = x;
            second.second = y;
        }
    }
    int other(int v) {
        return (v == first.second ? second.first : first.first);
    }

};

void dfs_combine(int u, int p, int cl, int above) {
    //cerr << " $ dfs combine " << u << " above " << above << endl;
    max2 m2;
    vis[u] = 1;
    if (cl != comp[u] && comp[u]) {
        int abv = above;
        for (auto& v : adj[u]) {
            if (v == p) continue;
            if (comp[v] == comp[u]) continue;
            abv = max(abv, f[v]+1);
            ////cerr << "  ~~~ " << v << " " << f[v]<< endl;
        }
        ll old_f = f[u];
        ////cerr << "  ~~~ " << u << " start " << abv << endl;
        f[u] = abv;
        cact_react(comp[u]);
        f[u] = old_f;
        m2.insert(above, p);
        ans[u] = above;
    }
    if (comp[u]) {
        ans[u] = max(ans[u], max(f[u], upd[u]));
        m2.insert(upd[u], -1);
        //m2.insert(above, p);
        //m2.insert(f[u], -1);
    } else {
        m2.insert(above, p);
        ans[u] = max(f[u], above);
    }

    for (auto& v : adj[u]) {
        if (vis[v]) continue;
        m2.insert(f[v]+1, v);
    }
    //cerr << "    FROM " << u << " HAVE " << m2.first.first << "," << m2.first.second << " : " << m2.second.first << "," << m2.second.second << endl;
    for (auto& v : adj[u]) {
        if (vis[v]) continue;
        dfs_combine(v, u, comp[u], m2.other(v)+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_build(1, -1);
    memset(vis, 0, sizeof vis);
    dfs_below(1, -1, 0);
    memset(vis, 0, sizeof vis);
    dfs_combine(1, -1, 0, 0);

    for (int i=1; i<=n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}