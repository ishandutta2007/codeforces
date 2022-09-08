/**
 *  created: 24/08/2021, 18:51:46
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, mod = 998244353;

inline void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

inline void dec(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
}

inline int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int power(int a, int b) {
    int res = 1 % mod;
    while (b) {
        if (b % 2) {
            res = mul(res, a);
        }
        b /= 2;
        a = mul(a, a);
    }
    return res;
}

int inv(int x) {
    return power(x, mod - 2);
}

string str_fraq(int x, int n = 20) {
    stringstream res;
    pair<int, int> best(x, 1);
    for (int j = 1; j < n; ++j) {
        best = min(best, {mul(x, j), j});
    }
    res << best.first << "/" << best.second;
    return res.str();
}

const int max_f = 2 * max_n;

int f[max_f], rf[max_f];

void get_all_f() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < max_f; ++i) {
        f[i] = mul(i, f[i - 1]);
    }
    rf[max_f - 1] = inv(f[max_f - 1]);
    for (int i = max_f - 2; i > 0; --i) {
        rf[i] = mul(i + 1, rf[i + 1]);
    }
}

int get_c(int n, int k) {
    if (n < k) {
        return 0;
    }
    return mul(f[n], mul(rf[k], rf[n - k]));
}

int a[max_n];

int rec(int n, int pos, const vector<int> &v) {
    if (pos == n) {
        return 1;
    }
    int res = 0;
    for (int x = 0; x < n; ++x) {
        a[pos] = x;
        if (pos && a[pos - 1] > a[pos]) {
            int mn;
            for (int i = 0; i < pos; ++i) {
                if (x < a[i]) {
                    mn = i;
                    break;
                }
            }
            if (mn == v[pos]) {
                rotate(a + mn, a + pos, a + pos + 1);
                res += rec(n, pos + 1, v);
                rotate(a + mn, a + mn + 1, a + pos + 1);
            }
        } else {
            if (v[pos] == -1) {
                res += rec(n, pos + 1, v);
            }
        }
    }
    return res;
}

int t, n, m, x[max_n], y[max_n];

int triv() {
    vector<int> a(n, -1);
    for (int i = 0; i < m; ++i) {
        a[x[i]] = y[i];
    }
    int res = rec(n, 0, a);
    return res;
}

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(seed);

struct treap {
    int sz, value, add, prior;
    treap *left, *right;
    treap(int v) {
        value = v;
        sz = 1;
        add = 0;
        prior = generator();
        left = NULL;
        right = NULL;
    }
};

int get_size(treap *t) {
    if (t == NULL) {
        return 0;
    }
    return t->sz;
}

void update(treap *&t) {
    if (t == NULL) {
        return;
    }
    t->sz = 1 + get_size(t->left) + get_size(t->right);
}

void push(treap *&t) {
    if (t) {
        t->value += t->add;
        if (t->left) {
            t->left->add += t->add;
        }
        if (t->right) {
            t->right->add += t->add;
        }
        t->add = 0;
    }
}

treap *merge(treap *t1, treap *t2) {
    push(t1);
    push(t2);
    if (t1 == NULL) {
        return t2;
    }
    if (t2 == NULL) {
        return t1;
    }
    if (t1->prior <= t2->prior) {
        t2->left = merge(t1, t2->left);
        update(t2);
        return t2;
    } else {
        t1->right = merge(t1->right, t2);
        update(t1);
        return t1;
    }
}

void split(treap *our, int key, treap *&l, treap *&r) {
    push(our);
    if (our == NULL) {
        l = NULL;
        r = NULL;
        return;
    }
    if (our->value >= key) {
        r = our;
        split(r->left, key, l, r->left);
    } else {
        l = our;
        split(l->right, key, l->right, r);
    }
    update(l);
    update(r);
}

void add(treap *&t, int x) {
    treap *nt = new treap(x);
    treap *buf1, *buf2;
    split(t, x, buf1, buf2);
    t = merge(buf1, merge(nt, buf2));
}

void erase(treap *&t, int x) {
    treap *buf1, *buf2, *buf3, *buf4;
    split(t, x, buf1, buf2);
    split(buf2, x + 1, buf3, buf4);
    t = merge(buf1, buf4);
}

int solve() {
    /*vector<int> a(n, -1);
    for (int i = 0; i < m; ++i) {
        a[x[i]] = y[i];
    }
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) {
            v[i] = 1;
            rotate(v.begin() + a[i], v.begin() + i, v.begin() + i + 1);
            if (a[i] > 0) {
                v[a[i] - 1] = 0;
            }
        }
    }
    int k = accumulate(v.begin(), v.end(), 0);*/
    treap *t = nullptr;
    for (int i = 0; i < m; ++i) {
        treap *buf1, *buf2, *buf3, *buf4;
        split(t, y[i] - 1, buf1, buf2);
        split(buf2, y[i], buf3, buf4);
        if (buf4) {
            buf4->add += 1;
        }
        treap *nt = new treap(y[i]);
        t = merge(buf1, merge(nt, buf4));
    }
    int k = get_size(t);
    return get_c(n + n - k - 1, n);
}

int rnd() {
    return generator() >> 1;
}

int rnd(int r) {
    return rnd() % r;
}

int rnd(int l, int r) {
    return l + rnd(r - l + 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_f();
    if (0) {
        while (1) {
            n = rnd(2, 9);
            m = 0;
            for (int i = 1; i < n; ++i) {
                int p = rnd(0, 2 * i);
                if (p < i) {
                    x[m] = i;
                    y[m] = p;
                    ++m;
                }
            }
            if (solve() != triv()) {
                cout << "WA" << endl;
                exit(2);
            }
            cout << "+";
        }
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &x[i], &y[i]);
            --x[i];
            --y[i];
        }
        printf("%d\n", solve());
    }
    return 0;
}