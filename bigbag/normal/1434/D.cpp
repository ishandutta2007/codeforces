#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111222, inf = 100111222;
const int max_v = 2 * max_n;

struct state {
    int max_suf, max_pref, max_h, res;

    state(): max_suf(0), max_pref(0), max_h(0), res(0) {
    }

    state(int max_suf, int max_pref, int max_h, int res): max_suf(max_suf), max_pref(max_pref), max_h(max_h), res(res) {
    }
};

struct node {
    state a[2];
    int min_h;

    node() {
    }

    node(int h, int col) {
        min_h = h;
        a[col] = {-h, -h, h, 0};
        //a[col ^ 1] = {0, 0, 0, 0};
        a[col ^ 1] = {-inf, -inf, -inf, -inf};
    }

    void flip() {
        swap(a[0], a[1]);
    }

    int get_res() const {
        return max(a[0].res, a[1].res);
    }
};

state merge(const state &a, const state &b, int amnh, int bmnh) {
    return {max(b.max_suf, max(a.max_suf, a.max_h - 2 * bmnh)),
            max(a.max_pref, max(b.max_pref, b.max_h - 2 * amnh)),
            max(a.max_h, b.max_h),
            max(a.res, max(b.res, max(a.max_suf + b.max_h, a.max_h + b.max_pref)))};
}

node merge(const node &a, const node &b) {
    node res;
    res.min_h = min(a.min_h, b.min_h);
    res.a[0] = merge(a.a[0], b.a[0], a.min_h, b.min_h);
    res.a[1] = merge(a.a[1], b.a[1], a.min_h, b.min_h);
    return res;
}

ostream& operator << (ostream &os, const state &s) {
    os << s.max_suf << " " << s.max_pref << " " << s.max_h << " " << s.res;
    return os;
}

ostream& operator << (ostream &os, const node &nd) {
    os << nd.min_h << "col0 = " << nd.a[0] << " " << "col1 = " << nd.a[1];
    return os;
}

struct tree {
    node a[max_v];
    bool f[max_v];

    void build(int v, int l, int r, const vector<int> &h, const vector<int> &col) {
        if (l == r) {
            assert(v < max_v);
            a[v] = node(h[l], col[l]);
            f[v] = 0;
            //cout << l << " " << r << ": " << a[v] << endl;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, h, col);
        build(2 * v + 1, mid + 1, r, h, col);
        a[v] = merge(a[2 * v], a[2 * v + 1]);
        //cout << l << " " << r << ": " << a[v] << endl;
    }

    void push(int v) {
        if (f[v]) {
            f[2 * v] ^= 1;
            f[2 * v + 1] ^= 1;
            a[2 * v].flip();
            a[2 * v + 1].flip();
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            f[v] ^= 1;
            a[v].flip();
            return;
        }
        push(v);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r);
        } else {
            update(2 * v, tl, mid, l, mid);
            update(2 * v + 1, mid + 1, tr, mid + 1, r);
        }
        a[v] = merge(a[2 * v], a[2 * v + 1]);
    }
};

int n, m, col[max_n], h[max_n], l[max_n], r[max_n];
int U[max_n], V[max_n], x[max_n];
vector<int> g[max_n], order_h, order_col;
tree t;

void dfs(int v, int p) {
    l[v] = order_h.size();
    order_h.push_back(h[v]);
    order_col.push_back(col[v]);
    for (int id : g[v]) {
        const int to = U[id] ^ V[id] ^ v;
        if (to == p) {
            continue;
        }
        if (to != V[id]) {
            swap(U[id], V[id]);
        }
        //cout << v << " -> " << to << endl;
        col[to] = col[v] ^ x[id];
        h[to] = h[v] + 1;
        dfs(to, v);
        order_h.push_back(h[v]);
        order_col.push_back(col[v]);
    }
    r[v] = order_h.size() - 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d%d", &U[i], &V[i], &x[i]);
        --U[i];
        --V[i];
        g[U[i]].push_back(i);
        g[V[i]].push_back(i);
    }
    dfs(0, -1);
    t.build(1, 0, order_h.size() - 1, order_h, order_col);
    /*for (int i = 0; i < order_h.size(); ++i) {
        cout << order_h[i] << " " << order_col[i] << endl;
    }
    cout << t.a[1].get_res() << endl;
    return 0;*/
    scanf("%d", &m);
    while (m--) {
        int id;
        scanf("%d", &id);
        //cout << "$" << V[id] << endl;
        t.update(1, 0, order_h.size() - 1, l[V[id]], r[V[id]]);
        int ans = t.a[1].get_res();
        ans = max(ans, 0);
        printf("%d\n", ans);
    }
    return 0;
}