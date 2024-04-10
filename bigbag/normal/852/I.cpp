/**
 *  created: 26/09/2021, 18:03:39
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;
const int magic = 333;
const int max_lev = 18;

struct Query {
    int l, r, root, id;

    Query(int l, int r, int root, int id): l(l), r(r), root(root), id(id) {
    }

    bool operator < (const Query &q) const {
        return make_pair(l / magic, r) < make_pair(q.l / magic, q.r);
    }
};

int n, m, tp[max_n], a[max_n];
vector<int> order;
int cnt[2][max_n];
long long ans;

void add(int v) {
    ans += cnt[tp[v] ^ 1][a[v]];
    ++cnt[tp[v]][a[v]];
}

void del(int v) {
    ans -= cnt[tp[v] ^ 1][a[v]];
    --cnt[tp[v]][a[v]];
}

struct MO_state {
    int l, r;
    bool have_v[max_n];

    void proc(int v) {
        if (!have_v[v]) {
            add(v);
        } else {
            del(v
                );
        }
        have_v[v] ^= 1;
    }

    void udpate(int nl, int nr) {
        while (l < nl) {
            proc(order[l]);
            ++l;
        }
        while (l > nl) {
            --l;
            proc(order[l]);
        }
        while (r < nr) {
            proc(order[r]);
            ++r;
        }
        while (r > nr) {
            --r;
            proc(order[r]);
        }
    }
};

int tin[max_n], tout[max_n], p[max_lev][max_n];
long long answers[max_n];
vector<int> g[max_n];
vector<int> all;
vector<Query> queries;
MO_state MO;

int compress(int x) {
    return lower_bound(all.begin(), all.end(), x) - all.begin();
}

void dfs(int v) {
    tin[v] = order.size();
    order.push_back(v);
    for (int to : g[v]) {
        if (to == p[0][v]) {
            continue;
        }
        p[0][to] = v;
        dfs(to);
    }
    tout[v] = order.size();
    order.push_back(v);
}

void get_all_p() {
    for (int lev = 1; lev < max_lev; ++lev) {
        for (int i = 0; i < n; ++i) {
            p[lev][i] = p[lev - 1][p[lev - 1][i]];
        }
    }
}

bool is_ancestor(int v1, int v2) {
    return tin[v1] <= tin[v2] && tout[v1] >= tout[v2];
}

int lca(int v1, int v2) {
    if (is_ancestor(v1, v2)) {
        return v1;
    }
    for (int lev = max_lev - 1; lev >= 0; --lev) {
        if (!is_ancestor(p[lev][v1], v2)) {
            v1 = p[lev][v1];
        }
    }
    return p[0][v1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tp[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        all.push_back(a[i]);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (int i = 0; i < n; ++i) {
        a[i] = compress(a[i]);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    get_all_p();
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (tin[u] > tin[v]) {
            swap(u, v);
        }
        if (is_ancestor(u, v)) {
            queries.push_back({tin[u], tin[v] + 1, -1, i});
        } else {
            queries.push_back({tin[u] + 1, tin[v] + 1, lca(u, v), i});
        }
    }
    sort(queries.begin(), queries.end());
    for (const auto &q : queries) {
        MO.udpate(q.l, q.r);
        if (q.root != -1) {
            MO.proc(q.root);
        }
        answers[q.id] = ans;
        if (q.root != -1) {
            MO.proc(q.root);
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << answers[i] << "\n";
    }
    return 0;
}