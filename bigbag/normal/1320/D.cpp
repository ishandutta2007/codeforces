#include <bits/stdc++.h>

using namespace std;

const int cmod = 1;

const int max_n = 200222;
int p[] = {37, 39, 43};
int mod[] = {1000000007, 1000000009, 1000000021};

struct state {
    int h[cmod];
    int len, cnt, first, last;
};

ostream& operator << (ostream &os, const state &s) {
    os << "h = (" << s.h[1] << "), len = " << s.len << ", cnt = " << s.cnt << ", first = " << s.first << ", last = " << s.last;
    return os;
}

int pw[cmod][max_n], rpw[cmod][max_n];

int mul(int tp, int x, int y) {
    return 1LL * x * y % mod[tp];
}

int power(int tp, int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        return power(tp, mul(tp, a, a), b / 2);
    }
    return mul(tp, a, power(tp, a, b - 1));
}

int inv(int tp, int x) {
    return power(tp, x, mod[tp] - 2);
}

void init() {
    for (int j = 0; j < cmod; ++j) {
        pw[j][0] = 1;
        rpw[j][0] = 1;
        int rp = inv(j, p[j]);
        for (int i = 1; i < max_n; ++i) {
            pw[j][i] = mul(j, pw[j][i - 1], p[j]);
            rpw[j][i] = mul(j, rpw[j][i - 1], rp);
        }
    }
}

int get_pw(int tp, int x) {
    if (x < 0) {
        return rpw[tp][-x];
    }
    return pw[tp][x];
}

state merge(state a, state b) {
    //cout << a << "   +++   " << b << " = " << endl;
    state res;
    res.len = a.len + b.len;

    res.first = a.first;
    if (a.first == a.len) {
        res.first += b.first;
    }
    res.last = b.last;
    if (b.last == b.len) {
        res.last += a.last;
    }

    res.cnt = a.cnt + b.cnt;
    for (int tp = 0; tp < cmod; ++tp) {
        if (!a.last || b.first % 2 == 0) {
            res.h[tp] = (a.h[tp] + 1LL * b.h[tp] * pw[tp][a.len - a.cnt]) % mod[tp];
        } else {
            if (a.last % 2) {
                if (tp == 0) {
                    res.cnt += 2;
                }
                a.h[tp] += mod[tp] - pw[tp][a.len - a.cnt - 1];
                b.h[tp] += mod[tp] - pw[tp][0];
                res.h[tp] = (a.h[tp] + 1LL * b.h[tp] * get_pw(tp, a.len - a.cnt - 2)) % mod[tp];
            } else {
                a.h[tp] += pw[tp][a.len - a.cnt];
                b.h[tp] += mod[tp] - pw[tp][0];
                res.h[tp] = (a.h[tp] + 1LL * b.h[tp] * pw[tp][a.len - a.cnt]) % mod[tp];
            }
        }
    }
    //cout << res << endl << endl;
    return res;
}

state a[4 * max_n];

void build(int v, int l, int r, char s[]) {
    if (l == r) {
        fill(a[v].h, a[v].h + cmod, s[l] - '0');
        a[v].first = s[l] - '0';
        a[v].last = s[l] - '0';
        a[v].cnt = 0;
        a[v].len = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid, s);
    build(2 * v + 1, mid + 1, r, s);
    a[v] = merge(a[2 * v], a[2 * v + 1]);
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
    return merge(get(2 * v, tl, mid, l, mid), get(2 * v + 1, mid + 1, tr, mid + 1, r));
}

int n, q;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%s", &n, s);
    scanf("%d", &q);
    init();
    build(1, 0, n - 1, s);
    while (q--) {
        int l1, l2, len;
        scanf("%d%d%d", &l1, &l2, &len);
        --l1;
        --l2;
        state a = get(1, 0, n - 1, l1, l1 + len - 1);
        state b = get(1, 0, n - 1, l2, l2 + len - 1);
        bool ok = true;
        for (int i = 0; i < cmod; ++i) {
            if (a.h[i] != b.h[i]) {
                ok = false;
                break;
            }
        }
        if (ok && a.cnt == b.cnt) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}