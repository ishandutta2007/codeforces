#include <bits/stdc++.h>

using namespace std;

const int max_n = (1 << 12) + 4, inf = 1000111222;
const int max_q = (1 << 16) + 4;
const int sz = 16;

struct query {
    int l, r, id;

    pair<int, int> func() const {
        return {l / sz, r};
    }

    bool operator < (const query &q) const {
        return func() < q.func();
    }
};

int n, q, a[max_n], num[max_n], ans[max_q];
query p[max_q];

int t[4 * max_n], last[4 * max_n], curt;
map<pair<int, int>, int> m;
vector<pair<int, int>> op;

int merge(int x, int y) {
    if (x == -1) {
        return y;
    }
    if (y == -1) {
        return x;
    }
    if (m.count({x, y})) {
        return m[{x, y}];
    }
    op.push_back({x, y});
    return m[{x, y}] = op.size() + n;
}

void update(int v, int l, int r, int pos, int x) {
    //if (v == 1) cout << pos << " " << x << endl;
    if (l == r) {
        t[v] = x;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(2 * v, l, mid, pos, x);
    } else {
        update(2 * v + 1, mid + 1, r, pos, x);
    }
    last[v] = curt;
}

void build(int v) {
    if (last[v] < curt) {
        return;
    }
    build(2 * v);
    build(2 * v + 1);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(t, -1, sizeof(t));
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
        num[a[i]] = i + 1;
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &p[i].l, &p[i].r);
        --p[i].l;
        --p[i].r;
        p[i].id = i;
    }
    sort(p, p + q);
    int lastl = 0, lastr = -1;
    for (int i = 0; i < q; ++i) {
        const int cl = max(lastl, p[i].l);
        const int cr = min(lastr, p[i].r);
        ++curt;
        for (int j = lastl; j < cl && j <= lastr; ++j) {
            //cout << "0) a[" << j << "] = " << a[j] << endl;
            update(1, 0, n - 1, a[j], -1);
        }
        for (int j = max(lastl, cr + 1); j <= lastr; ++j) {
            //cout << "1) a[" << j << "] = " << a[j] << endl;
            update(1, 0, n - 1, a[j], -1);
        }
        for (int j = p[i].l; j < cl && j <= p[i].r; ++j) {
            //cout << "2) a[" << j << "] = " << a[j] << endl;
            update(1, 0, n - 1, a[j], num[a[j]]);
        }
        for (int j = max(p[i].l, cr + 1); j <= p[i].r; ++j) {
            //cout << "3) a[" << j << "] = " << a[j] << endl;
            update(1, 0, n - 1, a[j], num[a[j]]);
        }
        lastl = p[i].l;
        lastr = p[i].r;
        build(1);
        ans[p[i].id] = t[1];
    };
    printf("%d\n", n + op.size());
    for (auto o : op) {
        printf("%d %d\n", o.first, o.second);
    }
    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}