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

const int max_n = 101111, inf = 1011111111;

struct state {
    int sum[4];
    state() {
        memset(sum, 0, sizeof(sum));
    }
    state(int a, int b, int c, int d) {
        sum[0] = a;
        sum[1] = b;
        sum[2] = c;
        sum[3] = d;
    }
};

state merge(const state &a, const state &b) {
    return state(a.sum[0] + b.sum[0], a.sum[1] + b.sum[1], a.sum[2] + b.sum[2], a.sum[3] + b.sum[3]);
}

struct tree {
    int sz;
    vector<state> a;
    tree() {
        sz = 0;
        a.clear();
    }
    tree(int sz): sz(sz) {
        a.resize(4 * sz);
        for (int i = 0; i < 4 * sz; ++i) {
            a[i] = state();
        }
    }
    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            a[v] = state();
            a[v].sum[value] = 1;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        a[v] = merge(a[2 * v], a[2 * v + 1]);
    }
    int get_sum(int v, int tl, int tr, int l, int r, int c) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return a[v].sum[c];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r, c);
        }
        if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r, c);
        }
        return get_sum(2 * v, tl, mid, l, mid, c) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r, c);
    }
};

int q, n, mx;
char s[max_n], e[22];
tree t[11][11];

char get(char c) {
    if (c == 'A') {
        return 'a';
    } else if (c == 'T') {
        return 'b';
    } else if (c == 'G') {
        return 'c';
    } else {
        return 'd';
    }
}

int get_left(int len, int num, int pos) {
    return (pos - num + len - 1) / len;
}

int get_right(int len, int num, int pos) {
    return (pos - num) / len;
}

void update(int len, int i) {
    t[len][i % len].update(1, 0, t[len][i % len].sz, i / len, s[i] - 'a');
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%s%d", s, &q);
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        s[i] = get(s[i]);
    }
    for (int i = 1; i <= 10; ++i) {
        for (int j = 0; j < i; ++j) {
            t[i][j] = tree(n / i + 2);
        }
        for (int j = 0; j < n; ++j) {
            update(i, j);
        }
    }
    while (q--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int pos;
            char c;
            scanf("%d%c%c", &pos, &c, &c);
            --pos;
            c = get(c);
            s[pos] = c;
            for (int i = 1; i <= 10; ++i) {
                update(i, pos);
            }
        } else {
            int l, r;
            scanf("%d%d%s", &l, &r, e);
            --l;
            --r;
            int m = strlen(e), ans = 0;
            for (int i = 0; i < m && l + i <= r; ++i) {
                e[i] = get(e[i]);
                int num = (l + i) % m;
                //cout << num << " " << get_left(m, num, l) << " " << get_right(m, num, r) << "  " << e[i] << endl;
                ans += t[m][num].get_sum(1, 0, t[m][num].sz, get_left(m, num, l), get_right(m, num, r), e[i] - 'a');
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}