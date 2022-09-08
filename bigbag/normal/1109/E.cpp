#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011, inf = 1000111222;

struct tree {
    int add[4 * max_n];

    void update(int v, int tl, int tr, int l, int r, int value) {
        if (tl == l && tr == r) {
            add[v] += value;
            return;
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
    }

    int get(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            return add[v];
        }
        int mid = (tl + tr) / 2;
        if (pos <= mid) {
            return add[v] + get(2 * v, tl, mid, pos);
        }
        return add[v] + get(2 * v + 1, mid + 1, tr, pos);
    }
};

int mod;

int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

struct tree2 {
    int sum[4 * max_n], f[4 * max_n];

    void build(int v, int l, int r, int a[]) {
        f[v] = 1;
        if (l == r) {
            sum[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        sum[v] = (sum[2 * v] + sum[2 * v + 1]) % mod;
    }

    void push(int v) {
        if (f[v] != 1) {
            f[2 * v] = mul(f[2 * v], f[v]);
            f[2 * v + 1] = mul(f[2 * v + 1], f[v]);
            sum[2 * v] = mul(sum[2 * v], f[v]);
            sum[2 * v + 1] = mul(sum[2 * v + 1], f[v]);
            f[v] = 1;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int value) {
        if (tl == l && tr == r) {
            f[v] = mul(f[v], value);
            sum[v] = mul(sum[v], value);
            return;
        }
        push(v);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        sum[v] = (sum[2 * v] + sum[2 * v + 1]) % mod;
    }

    void upd_one(int v, int l, int r, int pos, int x) {
        if (l == r) {
            sum[v] = x;
            return;
        }
        push(v);
        int mid = (l + r) / 2;
        if (pos <= mid) {
            upd_one(2 * v, l, mid, pos, x);
        } else {
            upd_one(2 * v + 1, mid + 1, r, pos, x);
        }
        sum[v] = (sum[2 * v] + sum[2 * v + 1]) % mod;
    }

    int get_sum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return sum[v];
        }
        push(v);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return (get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r)) % mod;
    }
};

int get_phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

int n, q, a[max_n], b[max_n];
vector<int> p;
tree t[11];
tree2 t2, t3;

void factorize(int mod) {
    for (int i = 2; i * i <= mod; ++i) {
        if (mod % i == 0) {
            while (mod % i == 0) {
                mod /= i;
            }
            p.push_back(i);
        }
    }
    if (mod > 1) {
        p.push_back(mod);
    }
}

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2);
    }
    return (1LL * a * power(a, b - 1)) % mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &mod);
    factorize(mod);
    int phi = get_phi(mod) - 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
        for (int j = 0; j < p.size(); ++j) {
            int cnt = 0;
            while (a[i] % p[j] == 0) {
                a[i] /= p[j];
                ++cnt;
            }
            t[j].update(1, 0, n - 1, i, i, cnt);
        }
    }
    t2.build(1, 0, n - 1, a);
    t3.build(1, 0, n - 1, b); // real
    scanf("%d", &q);
    while (q--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            --l;
            --r;
            t3.update(1, 0, n - 1, l, r, x); // real
            for (int j = 0; j < p.size(); ++j) {
                int cnt = 0;
                while (x % p[j] == 0) {
                    x /= p[j];
                    ++cnt;
                }
                t[j].update(1, 0, n - 1, l, r, cnt);
            }
            t2.update(1, 0, n - 1, l, r, x);
        } else if (tp == 2) {
            int pos, x;
            scanf("%d%d", &pos, &x);
            --pos;
            for (int j = 0; j < p.size(); ++j) {
                int cnt = 0;
                while (x % p[j] == 0) {
                    x /= p[j];
                    --cnt;
                }
                t[j].update(1, 0, n - 1, pos, pos, cnt);
            }
            int rev = power(x, phi);
            t2.update(1, 0, n - 1, pos, pos, rev);
            x = t2.get_sum(1, 0, n - 1, pos, pos);
            for (int j = 0; j < p.size(); ++j) {
                int pw = t[j].get(1, 0, n - 1, pos);
                x = mul(x, power(p[j], pw));
            }
            t3.upd_one(1, 0, n - 1, pos, x);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            --l;
            --r;
            int ans = t3.get_sum(1, 0, n - 1, l, r) % mod;
            printf("%d\n", ans);
        }
    }
    return 0;
}