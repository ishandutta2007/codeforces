#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111, max_e = 1000011, inf = 1000111222;

int pr[max_n];
int sz[max_n];

int n, m;
vector<pair<pair<int, int>, pair<int, int>>> f;
vector<pair<pair<int, int>, pair<int, int>>> e;
vector<pair<pair<int, int>, pair<int, int>>> alle;
const int max_lev = 17;
int par[max_lev][max_n], mn[max_lev][max_n];
vector<int> g[max_n];

int get_set(int cur) {
    return pr[cur] == cur ? cur : cur = get_set(pr[cur]);
}

void unite(int a, int b) {
    int pa = get_set(a);
    int pb = get_set(b);
    if (sz[pa] > sz[pb]) {
        pr[pb] = pa;
        sz[pa] += sz[pb];
    } else {
        pr[pa] = pb;
        sz[pb] += sz[pa];
    }
}

void clr() {
    for (int i = 0; i < n; ++i) {
        pr[i] = i;
        sz[i] = 1;
    }
}

int l[max_e], r[max_e], mid[max_e];
int ans[max_e];
bool res[max_e];

void split() {
    clr();
    for (auto c : alle) {
        int a = c.S.F, b = c.S.S;
        bool added;
        if (get_set(a) != get_set(b)) {
            added = true;
            unite(a, b);
        } else {
            added = false;
        }
        if (added) {
            e.push_back(c);
        } else {
            f.push_back(c);
        }
    }
}

int tin[max_n], tout[max_n], curt;

void dfs(int v, int p) {
    par[0][v] = p;
    tin[v] = ++curt;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
    }
    tout[v] = curt;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void get_all_p() {
    for (int lev = 0; lev < max_lev; ++lev) {
        for (int i = 0; i < n; ++i) {
            mn[lev][i] = inf;
        }
    }
    for (int lev = 1; lev < max_lev; ++lev) {
        for (int i = 0; i < n; ++i) {
            par[lev][i] = par[lev - 1][par[lev - 1][i]];
        }
    }
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) {
        return u;
    }
    for (int lev = max_lev - 1; lev >= 0; --lev) {
        if (!is_ancestor(par[lev][u], v)) {
            u = par[lev][u];
        }
    }
    return par[0][u];
}

void upd(int v, int lc, int x) {
    if (v == lc) {
        return;
    }
    for (int lev = max_lev - 1; lev >= 0; --lev) {
        if (!is_ancestor(par[lev][v], lc)) {
            mn[lev][v] = min(mn[lev][v], x);
            v = par[lev][v];
        }
    }
    mn[0][v] = min(mn[0][v], x);
}

void push_all() {
    for (int lev = max_lev - 1; lev; --lev) {
        for (int i = 0; i < n; ++i) {
            mn[lev - 1][i] = min(mn[lev - 1][i], mn[lev][i]);
            mn[lev - 1][par[lev - 1][i]] = min(mn[lev - 1][par[lev - 1][i]], mn[lev][i]);
        }
    }
}

void matvey() {
    for (const auto &p : e) {
        int u = p.second.first;
        int v = p.second.second;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0);
    get_all_p();
    for (const auto &p : f) {
        int u = p.second.first;
        int v = p.second.second;
        int len = p.first.first;
        int lc = lca(u, v);
        upd(u, lc, len);
        upd(v, lc, len);
    }
    push_all();
    for (const auto &p : e) {
        int u = p.second.first;
        int v = p.second.second;
        if (is_ancestor(v, u)) {
            swap(u, v);
        }
        ans[p.first.second] = -mn[0][v] - 1;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        pair<pair<int, int>, pair<int, int>> c;
        scanf("%d%d%d", &c.S.F, &c.S.S, &c.F.F);
        --c.S.S;
        --c.S.F;
        c.F.S = i;
        alle.push_back(c);
    }
    sort(alle.begin(), alle.end());
    split();
    for (int i = 0; i < m; ++i) {
        l[i] = 0;
        r[i] = 1000000001;
        ans[i] = -1;
    }
    int fnd = 0;
    while (fnd < f.size()) {
        vector<pair<pair<int, int>, pair<int, int>>> q;
        for (pair<pair<int, int>, pair<int, int>> ed : f) {
            int i = ed.F.S;
            if (ans[i] != -1) continue;
            mid[i] = (1LL * l[i] + r[i]) / 2;
            ed.F.F = mid[i];
            q.push_back(ed);
        }

        sort(q.begin(), q.end());
        reverse(q.begin(), q.end());
        clr();
        for (auto c : e) {
            while (q.size() && q.back().F.F <= c.F.F) {
                int a = q.back().S.F, b = q.back().S.S, i = q.back().F.S;
                q.pop_back();
                if (get_set(a) == get_set(b)) {
                    res[i] = 0;
                } else {
                    res[i] = 1;
                }
            }
            int a = c.S.F, b = c.S.S;
            if (get_set(a) != get_set(b)) {
                unite(a, b);
            }
        }
        while (q.size()) {
            int i = q.back().F.S;
            q.pop_back();
            res[i] = 0;
        }
        for (pair<pair<int, int>, pair<int, int>> ed : f) {
            int i = ed.F.S;
            if (ans[i] != -1) continue;
            if (res[i] == 1) {
                l[i] = mid[i];
            } else {
                r[i] = mid[i];
            }
            if (l[i] + 1 == r[i]) {
                ans[i] = l[i];
                ++fnd;
            }
        }
    }
    matvey();
    for (int i = 0; i < m; ++i) {
        if (ans[i] >= 0) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}