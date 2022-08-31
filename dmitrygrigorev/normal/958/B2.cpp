#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <random>
#include <time.h>

using namespace std;
#define int long long

const int MAXN = 1e5 + 7;
const int INF = 1e9 + 7;

vector <int> g[MAXN];
bool bad[MAXN];

int best = -1;
int besth = -1;

void jfs(int u, int parent, int h) {
    if (besth < h) {
        best = u;
        besth = h;
    }

    for (int v : g[u]) {
        if (v == parent) continue;
        if (bad[v]) continue;
        jfs(v, u, h + 1);
    }
}

pair <int, int> getd(int u, int parent, int h) {
    pair <int, int> res = {h, u};
    for (int v : g[u]) {
        if (v == parent) continue;
        if (bad[v]) continue;
        pair <int, int> nr = getd(v, u, h + 1);
        res = max(res, nr);
    }
    return res;
}

bool go(int u, int parent, int want) {
    if (u == want) {
        bad[u] = true;
        return true;
    }

    for (int v : g[u]) {
        if (v == parent) continue;
        if (go(v, u, want)) {
            bad[u] = true;
            return true;
        }
    }

    return false;
}

int dist[MAXN];

void calc(int u, int parent, int h) {
    dist[u] = h;
    for (int v : g[u]) {
        if (v == parent) continue;
        if (bad[v]) continue;
        calc(v, u, h + 1);
    }
}

int l[MAXN], r[MAXN], par[MAXN], pos[MAXN];
vector <int> e;
void build(int u, int parent) {
    par[u] = parent;
    
    pos[u] = e.size();
    e.push_back(u);
    l[u] = e.size();

    for (int v : g[u]) {
        if (v == parent) continue;
        build(v, u);
    }

    r[u] = e.size() - 1;
}

pair <int, int> tree[MAXN * 4];
int add[MAXN * 4];

void buildt(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = {dist[e[tl]], e[tl]};
        return;
    }

    int tm = (tl + tr) / 2;
    buildt(v * 2 + 1, tl, tm);
    buildt(v * 2 + 2, tm + 1, tr);
    tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void push(int v) {
    tree[v * 2 + 1].first += add[v];
    add[v * 2 + 1] += add[v];
    tree[v * 2 + 2].first += add[v];
    add[v * 2 + 2] += add[v];
    add[v] = 0;
}

void relax(int v) {
    tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void upd(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        tree[v].first += x;
        add[v] += x;
        return;
    }
    int tm = (tl + tr) / 2;
    push(v);
    upd(v * 2 + 1, tl, tm, l, r, x);
    upd(v * 2 + 2, tm + 1, tr, l, r, x);
    relax(v);
}

void del(int v, int tl, int tr, int p) {
    if (tl == tr) {
        tree[v].first = -INF;
        return;
    }

    int tm = (tl + tr) / 2;
    push(v);
    if (p <= tm) {
        del(v * 2 + 1, tl, tm, p);
    }
    else {
        del(v * 2 + 2, tm + 1, tr, p);
    }

    relax(v);
}

void make_bad(int u, int n) {
    bad[u] = true;
    del(0, 0, n - 1, pos[u]);
    upd(0, 0, n - 1, l[u], r[u], -1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 1) {
        cout << "1\n";
        return 0;
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    
    pair <int, int> t1 = getd(0, 0, 0);
    pair <int, int> t2 = getd(t1.second, t1.second, 0);
    
    go(t1.second, t1.second, t2.second);

    int curr = t2.first + 1;
    cout << "1 " << curr << ' ';
    
    for (int i = 0; i < n; ++i) dist[i] = -INF;
    for (int i = 0; i < n; ++i) {
        if (!bad[i]) continue;
        for (int j : g[i]) {
            if (bad[j]) continue;
            calc(j, j, 0);
        }
    }

    int root = t1.second;
    build(root, root);
    buildt(0, 0, n - 1);

    for (int it = 3; it <= n; ++it) {
        if (curr == n) {
            for (int i = 0; i < n - it + 1; ++i) cout << n << ' ';
            break;
        }
        
        pair <int, int> t = tree[0];
        curr += t.first + 1;
        cout << curr << ' ';
        int u = t.second;
        while (!bad[u]) {
            make_bad(u, n);
            u = par[u];
        }
    }
    cout << '\n';
    
    return 0;
}