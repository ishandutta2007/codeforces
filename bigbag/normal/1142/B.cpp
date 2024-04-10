#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_lev = 20;

struct tree {
    int mins[4 * max_n];
    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            mins[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        mins[v] = min(mins[2 * v], mins[2 * v + 1]);
    }
    int get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mins[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return min(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int n, m, q, p[max_n], a[max_n], nxt[max_lev][max_n], pos[max_n];
int b[max_n], last[max_n];
tree t;

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        --p[i];
        pos[p[i]] = i;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &a[i]);
        --a[i];
    }
    for (int i = 0; i < n; ++i) {
        last[i] = m;
    }
    nxt[0][m] = m;
    for (int i = m - 1; i >= 0; --i) {
        if (n == 1) {
            continue;
        }
        int x = p[(pos[a[i]] + 1) % n];
        nxt[0][i] = last[x];
        last[a[i]] = i;
    }
    for (int lev = 1; lev < max_lev; ++lev) {
        for (int i = 0; i <= m; ++i) {
            nxt[lev][i] = nxt[lev - 1][nxt[lev - 1][i]];
        }
    }
    vector<int> v;
    for (int i = 0; i < max_lev; ++i) {
        if (get_bit(n - 1, i)) {
            v.push_back(i);
        }
    }
    for (int i = 0; i < m; ++i) {
        b[i] = i;
        for (int lev : v) {
            b[i] = nxt[lev][b[i]];
        }
        t.update(1, 0, m - 1, i, b[i]);
    }
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;
        int x = t.get_min(1, 0, m - 1, l, r);
        if (x <= r) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
    return 0;
}