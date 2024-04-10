#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 101111, max_lev = 20, inf = 1111111111;

vector<int> all[max_n];

struct tree {
    vector<int> a, ll, rr;
    vector<vector<int> > q;
    tree() {
        a.clear();
        q.clear();
    }
    void build(int v, int l, int r) {
        if (l == r) {
            q[v].push_back(a[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        q[v].clear();
        merge(q[2 * v].begin(), q[2 * v].end(), q[2 * v + 1].begin(), q[2 * v + 1].end(), back_inserter(q[v]));
        while (q[v].size() > 10) {
            q[v].pop_back();
        }
    }
    tree(vector<int> b) {
        if (b.size() == 0) {
            return;
        }
        for (int i = 0; i < b.size(); ++i) {
            //cout << b[i] << " ";
            ll.push_back(a.size());
            for (int j = 0; j < all[b[i]].size(); ++j) {
                a.push_back(all[b[i]][j]);
                //cout << all[b[i]][j] << " ";
            }
            rr.push_back((int) a.size() - 1);
            //cout << ll[i] << " " << rr[i] << endl;
        }
        //cout << endl;
        if (a.size() == 0) {
            return;
        }
        q.resize(4 * (a.size() + 1));
        build(1, 0, a.size() - 1);
    }
    vector<int> get_max(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            vector<int> q;
            return q;
        }
        //cout << "$" << v << " ::: " << tl << " " << tr << endl;
        if (tl == l && tr == r) {
            //cout << v<< "@" << q[v].size() << endl;
            return q[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        vector<int> res, r1, r2;
        res.clear();
        r1 = get_max(2 * v, tl, mid, l, mid);
        r2 = get_max(2 * v + 1, mid + 1, tr, mid + 1, r);
        merge(r1.begin(), r1.end(), r2.begin(), r2.end(), back_inserter(res));
        while (res.size() > 10) {
            res.pop_back();
        }
        return res;
    }
};

int n, m, q, cnt, p[max_lev][max_n], tin[max_n], tout[max_n], sz[max_n], h[max_n];
int num[max_n], poz[max_n];
vector<int> g[max_n];
vector<int> paths[max_n];
tree t[max_n];

void dfs(int v, int par) {
    p[0][v] = par;
    sz[v] = 1;
    ++cnt;
    tin[v] = cnt;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != par) {
            dfs(g[v][i], v);
            sz[v] += sz[g[v][i]];
        }
    }
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != par && (sz[v] + 1) / 2 <= sz[g[v][i]]) {
            h[v] = 1;
            break;
        }
    }
    ++cnt;
    tout[v] = cnt;
}

void get_all_ancestors() {
    for (int lev = 1; lev < max_lev; ++lev) {
        for (int i = 1; i <= n; ++i) {
            p[lev][i] = p[lev - 1][p[lev - 1][i]];
        }
    }
}

bool is_ancestor(int v1, int v2) {
    return v1 == 0 || (tin[v1] <= tin[v2] && tout[v1] >= tout[v2]);
}

void add(int v) {
    ++cnt;
    paths[cnt].push_back(v);
    while (true) {
        int v2 = p[0][v];
        if (v2 == 0) {
            break;
        }
        //cout << v << " -> " << v2 << endl;
        if ((sz[v2] + 1) / 2 <= sz[v]) {
            v = v2;
            paths[cnt].push_back(v);
        } else {
            break;
        }
    }
    //printf("%d : ", cnt);
    for (int i = 0; i < paths[cnt].size(); ++i) {
        //cout << paths[cnt][i] << " ";
        num[paths[cnt][i]] = cnt;
        poz[paths[cnt][i]] = i;
    }
    //cout << endl;
    t[cnt] = tree(paths[cnt]);
}

void do_heavy_light() {
    for (int i = 1; i <= n; ++i) {
        if (h[i] == 0) {
            //cout << i << endl;
            add(i);
            //cout << i << endl;
        }
    }
}

vector<int> get_max(int v, int v2) {
    vector<int> mx, k, res;
    while (true) {
        int last = paths[num[v]].back();
        if (is_ancestor(last, v2)) {
            if (t[num[v]].ll[poz[v]] <= t[num[v]].rr[poz[v2]]) {
                //cout << "!";
                //cout << t[num[v]].ll[poz[v]] <<  "  " << t[num[v]].rr[poz[v2]] << endl;
                res = t[num[v]].get_max(1, 0, t[num[v]].a.size() - 1, t[num[v]].ll[poz[v]], t[num[v]].rr[poz[v2]]);
                k.clear();
                merge(mx.begin(), mx.end(), res.begin(), res.end(), back_inserter(k));
                mx = k;
                while (mx.size() > 10) {
                    mx.pop_back();
                }
            }
            break;
        }
        if (t[num[v]].ll[poz[v]] <= t[num[v]].rr[poz[last]]) {
            res = t[num[v]].get_max(1, 0, t[num[v]].a.size() - 1, t[num[v]].ll[poz[v]], t[num[v]].rr[poz[last]]);
            k.clear();
            merge(mx.begin(), mx.end(), res.begin(), res.end(), back_inserter(k));
            mx = k;
        }
        while (mx.size() > 10) {
            mx.pop_back();
        }
        v = p[0][last];
    }
    return mx;
}

int lca(int v1, int v2) {
    if (is_ancestor(v1, v2)) {
        return v1;
    }
    if (is_ancestor(v2, v1)) {
        return v2;
    }
    for (int i = max_lev - 1; i >= 0; --i) {
        //cout << v1 << endl;
        if (!is_ancestor(p[i][v1], v2)) {
            v1 = p[i][v1];
        }
    }
    return p[0][v1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= m; ++i) {
        int num;
        scanf("%d", &num);
        all[num].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        while (all[i].size() > 10) {
            all[i].pop_back();
        }
    }
    dfs(1, 0);
    cnt = 0;
    get_all_ancestors();
    do_heavy_light();
    /*for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << i << " " << j << " " << lca(i, j) << endl;
        }
    }*/
    //printf("%d\n", p[0][3]);
    //return 0;
    vector<int> ans, r1, r2;
    while (q--) {
        int u, v, a;
        scanf("%d%d%d", &u, &v, &a);
        int lc = lca(u, v);
        int lc2 = v;
        for (int i = max_lev - 1; i >= 0; --i) {
            if (!is_ancestor(p[i][lc2], lc)) {
                lc2 = p[i][lc2];
            }
        }
        r1 = get_max(u, lc);
        r2.clear();
        if (v != lc) {
            r2 = get_max(v, lc2);
        }
        ans.clear();
        merge(r1.begin(), r1.end(), r2.begin(), r2.end(), back_inserter(ans));
        printf("%d ", min(a, (int) ans.size()));
        for (int i = 0; i < min(a, (int) ans.size()); ++i) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}