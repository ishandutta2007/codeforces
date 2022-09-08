#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

struct node {
    int cnt, l, r;

    node(): cnt(0), l(0), r(0) {
    }

    node(int cnt, int l, int r): cnt(cnt), l(l), r(r) {
    }
};

node merge(const node &a, const node &b) {
    return node(a.cnt + b.cnt - (a.r && b.l), a.l, b.r);
}

struct tree {
    node a[4 * max_n];

    void update(int v, int l, int r, int pos) {
        if (l == r) {
            a[v] = node(1, 1, 1);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * v, l, mid, pos);
        } else {
            update(2 * v + 1, mid + 1, r, pos);
        }
        a[v] = merge(a[2 * v], a[2 * v + 1]);
    }
};

int n, m, l, a[max_n], ok[max_n];
tree t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] > l) {
            ok[i] = 1;
            t.update(1, 0, n - 1, i);
        }
    }
    while (m--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 0) {
            printf("%d\n", t.a[1].cnt);
        } else {
            int pos, x;
            scanf("%d%d", &pos, &x);
            --pos;
            if (!ok[pos]) {
                a[pos] += x;
                if (a[pos] > l) {
                    ok[pos] = 1;
                    t.update(1, 0, n - 1, pos);
                }
            }
        }
    }
    return 0;
}