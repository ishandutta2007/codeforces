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

const int max_n = 1001111, inf = 1111111111;

struct tree {
    int a[4 * max_n];
    tree() {
        memset(a, 0, sizeof(a));
    }
    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            a[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        a[v] = a[2 * v] ^ a[2 * v + 1];
    }
    int get_sum(int v, int tl, int tr, int l, int r) {
        if (l == tl && r == tr) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) ^ get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
};

int n, m, a[max_n], ans[max_n], x[max_n], nxt[max_n];
map<int, int> poz;
vector<pair<int, int> > q[max_n];
tree t;

int get_x(int l, int r) {
    if (l == 0) {
        return x[r];
    }
    return x[r] ^ x[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    x[0] = a[0];
    for (int i = 1; i < n; ++i) {
        x[i] = x[i - 1] ^ a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        if (!poz.count(a[i])) {
            nxt[i] = inf;
        } else {
            nxt[i] = poz[a[i]];
        }
        poz[a[i]] = i;
    }
    for (map<int, int>::iterator it = poz.begin(); it != poz.end(); ++it) {
        pair<int, int> p = *it;
        t.update(1, 0, n - 1, p.second, p.first);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;
        q[l].push_back(make_pair(r, i));
        ans[i] = get_x(l, r);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < q[i].size(); ++j) {
            ans[q[i][j].second] ^= t.get_sum(1, 0, n - 1, i, q[i][j].first);
        }
        t.update(1, 0, n - 1, i, 0);
        if (nxt[i] != inf) {
            t.update(1, 0, n - 1, nxt[i], a[i]);
        }
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}