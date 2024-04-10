/**
 *  created: 06/03/2021, 13:00:55
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;
const int block_sz = 111;

struct Fenwick {
    long long a[max_n];

    void update(int i, long long x) {
        for (; i < max_n; i = (i | (i + 1))) {
            a[i] += x;
        }
    }

    void add(int l, int r, long long x) {
        update(l, x);
        update(r + 1, -x);
    }

    long long get(int r) const {
        long long res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res += a[r];
        }
        return res;
    }
};

int n, q, a[max_n], nxt[max_n];
int prev_other_block[max_n];
Fenwick f;

int get_nxt(int v) {
    if (nxt[v] == v) {
        return v;
    }
    return nxt[v] = get_nxt(nxt[v]);
}

int curt, last_t[max_n];

int get_parent(int v) {
    if (nxt[v] == v) {
        return a[v];
    }
    return max(0LL, a[v] - f.get(v));
}

int get_prev_other_block(int pos) {
    if (nxt[pos] == pos) {
        return prev_other_block[pos];
    }
    return max(0LL, a[pos] - f.get(pos));
}

int lca(int u, int v) {
    while (true) {
        while (u / block_sz != v / block_sz) {
            if (u > v) {
                swap(u, v);
            }
            v = get_prev_other_block(v);
        }
        int u1 = get_prev_other_block(u);
        int v1 = get_prev_other_block(v);
        if (u1 == v1) {
            break;
        }
        u = u1;
        v = v1;
    }
    //cout << u << " " << v << ": " << get_parent(u) << " " << get_parent(v) << "    " << get_prev_other_block(u) << " " << get_prev_other_block(v) << endl;
    int num = v / block_sz;
    ++curt;
    //cout << "us = ";
    while (u / block_sz == num && last_t[u] != curt) {
        last_t[u] = curt;
        //cout << u << " ";
        u = get_parent(u);
    }
    last_t[u] = curt;
    //cout << u << endl;
    //cout << "vs = ";
    while (true) {
        //cout << v << " ";
        if (last_t[v] == curt) {
            //cout << endl;
            return v;
        }
        if (v == 0) {
            exit(228);
        }
        v = get_parent(v);
    }
}

void update_prev_other(int pos) {
    if (a[pos] == 0 || a[pos] / block_sz != pos / block_sz) {
        prev_other_block[pos] = a[pos];
    } else {
        prev_other_block[pos] = get_prev_other_block(a[pos]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
    }
    for (int i = 1; i <= n; ++i) {
        nxt[i] = i;
    }
    nxt[0] = 1;
    for (int i = 0; i < n; ++i) {
        update_prev_other(i);
    }
    while (q--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            --l;
            --r;
            f.add(l, r, x);
            int pos = get_nxt(l);
            while (pos <= r) {
                a[pos] = max(0, a[pos] - x);
                if (a[pos] == 0 || pos - a[pos] >= block_sz) {
                    nxt[pos] = pos + 1;
                    long long val = f.get(pos);
                    f.add(pos, pos, -val);
                }
                update_prev_other(pos);
                pos = get_nxt(pos + 1);
            }
            for (int i = r + 1; i < n && i / block_sz == r / block_sz; ++i) {
                if (i == nxt[i]) {
                    update_prev_other(i);
                }
            }
        } else {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            int ans = lca(u, v);
            printf("%d\n", ans + 1);
        }
    }
    return 0;
}