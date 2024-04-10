#include <bits/stdc++.h>

using namespace std;

const int max_n = 200022, max_lev = 18, inf = 1000111222;

struct fenwick_tree {
    int t[max_n];

    void update(int i, int x) {
        for (; i < max_n; i = (i | (i + 1))) {
            t[i] += x;
        }
    }

    int get_sum(int r) const {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res += t[r];
        }
        return res;
    }

    int get_sum(int l, int r) const {
        if (l == 0) {
            return get_sum(r);
        }
        return get_sum(r) - get_sum(l - 1);
    }

};

int n, p[max_lev][max_n], sz[max_n];
int tin[max_n], tout[max_n], pos[max_n];
int pos2[max_n];
vector<int> g[max_n];
bool ok[max_n];
pair<int, int> cost[max_n];

void get_all_p() {
    for (int lev = 1; lev < max_lev; ++lev) {
        for (int i = 1; i <= n; ++i) {
            p[lev][i] = p[lev - 1][p[lev - 1][i]];
        }
    }
}

bool is_ancestor(int u, int v) {
    if (u == 0) {
        return true;
    }
    if (v == 0) {
        return false;
    }
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) {
        return u;
    }
    for (int i = max_lev - 1; i >= 0; --i) {
        if (!is_ancestor(p[i][u], v)) {
            u = p[i][u];
        }
    }
    return p[0][u];
}

int cur_t;
fenwick_tree t, t2;

void dfs(int v) {
    tin[v] = ++cur_t;
    pos[v] = cur_t;
    for (int to : g[v]) {
        if (to == p[0][v]) {
            continue;
        }
        p[0][to] = v;
        dfs(to);
        sz[v] += sz[to];
    }
    tout[v] = cur_t;
    sz[v] = max(sz[v], 1);
}

void dfs2(int v) {
    for (int to : g[v]) {
        if (to == p[0][v]) {
            continue;
        }
        dfs2(to);
    }
    pos2[v] = ++cur_t;
}

struct prefix {
    fenwick_tree t1, t2;

    void update(int v) {
        t1.update(pos[v], 1);
        t2.update(pos2[v], 1);
    }

    int get_sum(int v) const {
        if (v == 0) {
            return 0;
        }
        //cout << v << ", sum = " << t1.get_sum(tout[v]) - t2.get_sum(pos2[v] - 1) << endl;
        return t1.get_sum(tout[v]) - t2.get_sum(pos2[v] - 1);
    }
};

prefix pr, pr2;
bool bad[max_n];

int find_up(int v) {
    int sum = pr.get_sum(v);
    for (int lev = max_lev - 1; lev >= 0; --lev) {
        if (p[lev][v] && pr.get_sum(p[0][p[lev][v]]) == sum) {
            v = p[lev][v];
        }
    }
    return p[0][v];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &cost[i].first);
        cost[i].second = i + 1;
    }
    sort(cost, cost + n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cur_t = 0;
    dfs2(1);
    get_all_p();

    for (int i = 2; i <= n; ++i) {
        if (g[i].size() == 1) {
            t.update(tin[i], 1);
            t2.update(tin[i], 1);
        }
    }

    /*t1.update(pos[2], 1);
    t2.update(pos2[2], 1);
    cout << get_sum(2) << endl;
    return 0;*/
    long long ans = 0;
    for (int i = 0; i < n; ) {
        int st = i;
        while (i < n && cost[i].first == cost[st].first) {
            ++i;
        }

        for (int j = st; j < i; ++j) {
            const int v = cost[j].second;
            //cout << v << ": " << t.get_sum(tin[v], tout[v]) << endl;
            int can = t.get_sum(tin[v], tout[v]);
            int up = find_up(v);
            int can_up = t.get_sum(tin[up], tout[up]);
            //cout << v << ": " << can << ", up = " << up << " " << c
            if (can > 0 && (up == 0 || can_up > can)) {
                ok[v] = 1;
            }
        }

        for (int j = st; j < i; ++j) {
            const int v = cost[j].second;
            int can = t.get_sum(tin[v], tout[v]);
            int up = find_up(v);
            int can_up = t.get_sum(tin[up], tout[up]);
            if (can > 0 && (up == 0 || can_up > can)) {
                t.update(tin[p[0][v]], -can);
                if (up > 1) {
                    t.update(tin[p[0][up]], can);
                }
                pr.update(v);

                ans += cost[j].first;
            } else {
                //cout << "- " << v << endl;
            }
        }
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        if (ok[i]) {
            v.push_back(i);
        }
    }
    printf("%I64d %d\n", ans, v.size());
    for (int x : v) {
        printf("%d ", x);
    }
    puts("");
    return 0;
}