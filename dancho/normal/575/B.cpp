#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
using namespace std;

const int mod = 1000000007;

typedef pair<int, int> pii;

int n, k;

set<pii> dir;

vector<int> g[1 << 20];

vector<int> p;
vector<int> ps[1 << 20];
vector<int> lc[1 << 20];

int par[1 << 20];

long long ans = 0;
long long pen[1 << 20];

int dep[1 << 17];
int bp[1 << 17][18];

void dfslca(int v) {
    for (int i = 1; i < 18; ++i) {
        bp[v][i] = bp[ bp[v][i - 1] ][i - 1];
    }

    for (auto u : g[v]) {
        if (bp[u][0] == -1) {
            dep[u] = dep[v] + 1;
            bp[u][0] = v;
            dfslca(u);
        }
    }
}

int lca(int v, int u) {
    if (dep[v] < dep[u]) {
        swap(v, u);
    }
    int k = 17;
    while (k >= 0) {
        while (dep[ bp[v][k] ] >= dep[u]) {
            v = bp[v][k];
        }
        --k;
    }
    if (v == u) {
        return v;
    }
    k = 17;
    while (k >= 0) {
        while (bp[v][k] == bp[u][k]) {
            --k;
        }
        if (k >= 0) {
            v = bp[v][k];
            u = bp[u][k];
        }
    }
    if (v == u) {
        return v;
    }
    return bp[v][0];
}

int dfs(int v, unordered_set<int> &cont) {
    int up = 0;
    cont.insert(v);
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (par[u] == -1) {
            par[u] = v;
            unordered_set<int> sc;
            up += dfs(u, sc);
            if (sc.size() > cont.size()) {
                swap(sc, cont);
            }
            for (auto i : sc) {
                cont.insert(i);
            }
        }
    }
    for (auto pr : ps[v]) {
        if (pr == v) {
            continue;
        }
        if (cont.find(pr) == cont.end()) {
            ++up;
        }
    }
    for (auto l : lc[v]) {
        if (l == v) {
            continue;
        }
        if (cont.find(l) != cont.end()) {
            --up;
        }
    }

    int down = up;
    if (cont.find(p[k - 1]) != cont.end()) {
        --down;
    }
    // up guys coming in.
    if (dir.find(make_pair(v, par[v])) != dir.end()) {
        ans += pen[up];
        if (ans >= mod) {
            ans %= mod;
        }
    }
    if (dir.find(make_pair(par[v], v)) != dir.end()) {
        ans += pen[down];
        if (ans >= mod) {
            ans %= mod;
        }
    }
    return up;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i + 1 < n; ++i) {
        int a, b, x;
        scanf("%d %d %d", &a, &b, &x);
        g[a].push_back(b);
        g[b].push_back(a);
        if (x) {
            dir.insert(make_pair(a, b));
        }
    }

    memset(bp, -1, sizeof(bp));
    memset(bp[0], 0, sizeof(bp[0]));
    bp[1][0] = 0;
    dep[0] = -1;
    dep[1] = 0;
    dfslca(1);

    scanf("%d", &k);
    p.resize(k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &p[i]);
        if (i > 0) {
            ps[p[i]].push_back(lca(p[i], p[i - 1]));
            lc[lca(p[i], p[i - 1])].push_back(p[i]);
        } else {
            ps[p[i]].push_back(1);
        }
    }

    pen[0] = 1;
    for (int i = 1; i < (1 << 20); ++i) {
        pen[i] = pen[i - 1] * 2;
        if (pen[i] >= mod) {
            pen[i] %= mod;
        }
    }
    for (int i = 0; i < (1 << 20); ++i) {
        pen[i] = (pen[i] - 1 + mod) % mod;
    }

    memset(par, -1, sizeof(par));
    par[1] = 0;
    unordered_set<int> se;
    dfs(1, se);

    cout << ans << endl;
    return 0;
}