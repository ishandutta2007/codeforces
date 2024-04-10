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

const int max_n = 100111, max_m = 303333, inf = 1011111111;

struct tree {
    int pos[4 * max_n];
    vector<int> a[4 * max_n];
    void build(int v, int l, int r, int x[]) {
        pos[v] = 0;
        if (l == r) {
            a[v].push_back(x[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, x);
        build(2 * v + 1, mid + 1, r, x);
        merge(a[2 * v].begin(), a[2 * v].end(), a[2 * v + 1].begin(), a[2 * v + 1].end(), back_inserter(a[v]));
    }
    int get(int v, int tl, int tr, int l, int x, int y) {
        while (pos[v] < a[v].size() && a[v][pos[v]] < x) {
            ++pos[v];
        }
        if (pos[v] == a[v].size() || a[v][pos[v]] > y) {
            return -1;
        }
        if (tl == tr) {
            return tl;
        }
        int mid = (tl + tr) / 2, res = -1;
        if (l <= mid) {
            res = get(2 * v, tl, mid, l, x, y);
        }
        if (res == -1) {
            res = get(2 * v + 1, mid + 1, tr, max(l, mid + 1), x, y);
        }
        return res;
    }
};

struct fenwick_tree {
    int n, t[max_n];
    fenwick_tree() {
    }
    fenwick_tree(int n) : n(n) {
        for (int i = 0; i < n; ++i) {
            t[i] = inf;
        }
    }
    void update(int i, int x) {
        i = n - i - 1;
        for (; i < n; i = (i | (i + 1))) {
            t[i] = min(t[i], x);
        }
    }
    int get(int r) {
        r = n - r - 1;
        int res = inf;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res = min(res, t[r]);
        }
        return res;
    }
};

int n, m, a[max_n], ans[max_m];
vector<int> q[max_n], num[max_n];

void solve() {
    tree t;
    t.build(1, 0, n - 1, a);
    pair<int, int> b[max_n];
    for (int i = 0; i < n; ++i) {
        b[i] = make_pair(a[i], i);
    }
    sort(b, b + n);
    vector<int> upd[max_n];
    for (int i = 0; i < n; ++i) {
        int Q = 0;
        int pos = b[i].second + 1, x = b[i].first, y = inf;
        while (pos < n) {
            ++Q;
            pos = t.get(1, 0, n - 1, pos, x, y);
            if (pos == -1) {
                break;
            }
            upd[pos].push_back(b[i].second);
            if (x == y) {
                break;
            }
            y = (x + a[pos]) / 2;
            ++pos;
        }
    }
    fenwick_tree f = fenwick_tree(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < upd[i].size(); ++j) {
            f.update(upd[i][j], a[i] - a[upd[i][j]]);
        }
        for (int j = 0; j < q[i].size(); ++j) {
            int res = f.get(q[i][j]);
            ans[num[i][j]] = min(ans[num[i][j]], res);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;
        ans[i] = inf;
        q[r].push_back(l);
        num[r].push_back(i);
    }
    solve();
    for (int i = 0; i < n; ++i) {
        a[i] *= -1;
    }
    solve();
    for (int i = 0; i < m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}