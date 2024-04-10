#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_lev = 18;

class tree {
public:
    int curt, tin[max_n], tout[max_n];
    int h[max_n], p[max_lev][max_n];

    void init(int n, vector<int> g[]) {
        curt = 0;
        dfs(0, g);
        get_all_p(n);
    }

    bool is_ancestor(int u, int v) const {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v) const {
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

    int get_dist(int u, int v) const {
        const int lc = lca(u, v);
        return h[u] + h[v] - 2 * h[lc];
    }

    int get_up(int v, int dist) const {
        for (int i = max_lev - 1; i >= 0; --i) {
            if (get_bit(dist, i)) {
                v = p[i][v];
            }
        }
        return v;
    }

private:
    void dfs(int v, vector<int> g[]) {
        tin[v] = ++curt;
        for (int to : g[v]) {
            if (to == p[0][v]) {
                continue;
            }
            p[0][to] = v;
            h[to] = h[v] + 1;
            dfs(to, g);
        }
        tout[v] = curt;
    }

    void get_all_p(int n) {
        for (int lev = 1; lev < max_lev; ++lev) {
            for (int i = 0; i < n; ++i) {
                p[lev][i] = p[lev - 1][p[lev - 1][i]];
            }
        }
    }

    static bool get_bit(int mask, int pos) {
        return (mask >> pos) & 1;
    }
};

struct Dist {
    int step, num, t;

    Dist() {
    }

    Dist(int step, int num, int t): step(step), num(num), t(t) {
    }

    bool operator < (const Dist &s) const {
        return step > s.step || step == s.step && num > s.num || step == s.step && num == s.num && t > s.t;
    }

    bool operator != (const Dist &s) const {
        return step != s.step || num != s.num || t != s.t;
    }
};

int n, a[max_n], b[max_n], speed[max_n];
vector<int> g[max_n], g2[max_n];
Dist dist[max_n];
tree t;

vector<int> build_virtual_tree(const tree &t, vector<int> vs, vector<int> g[]) {
    auto cmp_by_tin = [&t](int a, int b) {
         return t.tin[a] < t.tin[b];
    };
    sort(vs.begin(), vs.end(), cmp_by_tin);
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
    for (int i = 0, sz = vs.size(); i + 1 < sz; ++i) {
        vs.push_back(t.lca(vs[i], vs[i + 1]));
    }
    sort(vs.begin(), vs.end(), cmp_by_tin);
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
    const int n = vs.size();
    for (int i = 0; i < n; ++i) {
        g[vs[i]].clear();
    }
    vector<int> st;
    for (int v : vs) {
        while (!st.empty() && !t.is_ancestor(st.back(), v)) {
            st.pop_back();
        }
        if (!st.empty()) {
            g[st.back()].push_back(v);
            g[v].push_back(st.back());
        }
        st.push_back(v);
    }
    return vs;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    t.init(n, g);
    int q;
    scanf("%d", &q);
    while (q--) {
        int k, m;
        scanf("%d%d", &k, &m);
        vector<int> v;
        for (int i = 0; i < k; ++i) {
            scanf("%d%d", &a[i], &speed[i]);
            --a[i];
            v.push_back(a[i]);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d", &b[i]);
            --b[i];
            v.push_back(b[i]);
        }
        vector<int> vs = build_virtual_tree(t, v, g2);
        for (int v : vs) {
            dist[v] = {inf, inf, inf};
        }
        priority_queue<pair<Dist, int>> q;
        for (int i = 0; i < k; ++i) {
            dist[a[i]] = {0, i, speed[i]};
            q.push({dist[a[i]], a[i]});
        }
        while (!q.empty()) {
            const pair<Dist, int> p = q.top();
            q.pop();
            const int v = p.second;
            if (p.first != dist[v]) {
                continue;
            }
            for (int to : g2[v]) {
                int d = t.get_dist(v, to);
                Dist nd;
                if (d <= speed[dist[v].num] - dist[v].t) {
                    nd = {dist[v].step, dist[v].num, dist[v].t + d};
                } else {
                    d -= speed[dist[v].num] - dist[v].t;
                    int cnt = (d + speed[dist[v].num] - 1) / speed[dist[v].num];
                    d %= speed[dist[v].num];
                    if (!d) {
                        d = speed[dist[v].num];
                    }
                    nd = {dist[v].step + cnt, dist[v].num, d};
                }
                if (dist[to] < nd) {
                    dist[to] = nd;
                    q.push({dist[to], to});
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            printf("%d ", dist[b[i]].num + 1);
        }
        puts("");
    }
    return 0;
}