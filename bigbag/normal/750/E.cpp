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

const int max_n = 222222, inf = 1011111111;
const int arr[] = {2, 0, 1, 6};

int n, q, cnt[max_n][11], pr[max_n][11];
char s[max_n];

int get_cnt(int x, int l, int r) {
    if (l == 0) {
        return cnt[r][x];
    }
    return cnt[r][x] - cnt[l - 1][x];
}

struct state {
    int x[4][4], l, r;
    state() {
        memset(x, 0, sizeof(x));
        l = r = 0;
    }
    state(int pos) {
        memset(x, 0, sizeof(x));
        l = pos;
        r = pos;
        for (int i = 0; i < 4; ++i) {
            if (arr[i] == s[pos]) {
                x[i][i] = 1;
            }
        }
    }

    void write(string s = "") {
        //printf("[%d %d] : %d %d %d %d%s", l, r, x[0], x[1], x[2], x[3], s.c_str());
        printf("[%d %d] : ", l, r);
        for (int l = 0; l < 4; ++l) {
            for (int r = l; r < 4; ++r) {
                cout << "(" << l << " " << r << " = " << x[l][r] << ") ";
            }
        }
        cout << s;
        //printf("[%d %d] : %d%s", l, r, x[0][0], s.c_str());
    }
};

state merge(const state &x, const state &y, int v) {
    state z;
    z.l = x.l;
    z.r = y.r;
    for (int l = 0; l < 4; ++l) {
        z.x[l][l] = x.x[l][l] + y.x[l][l];
        for (int r = l + 1; r < 4; ++r) {
            /*int a = x.x[l][r] + y.x[r][r];
            int b = x.x[l][r - 1] + y.x[l][r];
            z.x[l][r] = min(a, b);*/
            z.x[l][r] = inf;
            for (int k = r; k >= l; --k) {
                int a = x.x[l][k] + y.x[k][r];
                z.x[l][r] = min(z.x[l][r], a);
            }
        }
    }
    /*for (int i = 1; i < 4; ++i) {
        int a = x.x[i] + get_cnt(arr[i], y.l, y.r);
        int b = x.x[i - 1] + y.x[i];
        z.x[i] = min(a, b);
    }*/
    return z;
}

struct tree {
    state a[4 * max_n];
    tree() {
    }
    void build(int v, int l, int r) {
        if (l == r) {
            a[v] = state(l);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        a[v] = merge(a[2 * v], a[2 * v + 1], mid + 1);
        //cout << v << " [" << l << " " << r << "] : ";
        /*if (v == 4 || v == 5 || v == 2) {
            cout << v << " ";
            a[v].write("\n\n");
        }*/
    }
    void update(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return;
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r);
        } else {
            update(2 * v, tl, mid, l, mid);
            update(2 * v + 1, mid + 1, tr, mid + 1, r);
        }
        a[v] = merge(a[2 * v], a[2 * v + 1], mid + 1);
    }
    state get(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get(2 * v + 1, mid + 1, tr, l, r);
        }
        return merge(get(2 * v, tl, mid, l, mid), get(2 * v + 1, mid + 1, tr, mid + 1, r), mid + 1);
    }
};

tree t;

int solve(int l, int r) {
    int a, b, c, d;
    d = pr[r][7];
    if (d < l) {
        return -1;
    }
    c = pr[d][1];
    if (c < l) {
        return -1;
    }
    b = pr[c][0];
    if (b < l) {
        return -1;
    }
    a = pr[b][2];
    if (a < l) {
        return -1;
    }
    int res = get_cnt(6, c + 1, r);
    state q = t.get(1, 0, n - 1, l, a);
    state w = t.get(1, 0, n - 1, a, c);
    state Q = t.get(1, 0, n - 1, a, b - 1);
    state W = t.get(1, 0, n - 1, b + 1, c);
    int mn = inf;
    for (int i = 3; i >= 0; --i) {
        int res = q.x[0][i] + w.x[i][3];
        if (i <= 1) {
            res -= w.x[i][3];
            int A = Q.x[1][3] + W.x[3][3];
            int B = Q.x[1][2] + W.x[2][3];
            int C = Q.x[1][1] + W.x[2][3];
            res += min({A, B, C});
        }
        mn = min(mn, res);
    }
    return res + mn;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    scanf("%s", s);
    memset(pr, -1, sizeof(pr));
    for (int i = 0; i < n; ++i) {
        s[i] -= '0';
        if (i) {
            for (int j = 0; j < 10; ++j) {
                cnt[i][j] = cnt[i - 1][j];
                pr[i][j] = pr[i - 1][j];
            }

        }
        ++cnt[i][s[i]];
        pr[i][s[i]] = i;
    }
    t.build(1, 0, n - 1);
    //return 0;
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;
        printf("%d\n", solve(l, r));
    }
    return 0;
}