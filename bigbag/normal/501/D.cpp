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

const int max_n = 211111, inf = 1111111111;

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
        a[v] = a[2 * v] + a[2 * v + 1];
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
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
};

struct factorial_system {
    int n, a[max_n];
    factorial_system() {
        memset(a, 0, sizeof(a));
    }
    factorial_system(int n, int b[]) : n(n) {
        for (int i = 0; i <= n; ++i) {
            a[i] = b[i];
        }
    }
    factorial_system operator + (const factorial_system &f) const {
        factorial_system res;
        res.n = n;
        for (int i = 0; i <= n; ++i) {
            res.a[i] += a[i] + f.a[i];
            if (res.a[i] > i) {
                res.a[i] -= (i + 1);
                ++res.a[i + 1];
                if (i == n) {
                    ++res.n;
                }
            }
        }
        return res;
    }
    void write(const string &s = "") const {
        for (int i = 0; i <= n; ++i) {
            printf("%d!  -  %d\n", i, a[i]);
        }
        printf("%s", s.c_str());
    }
};

struct permutation {
    int n, a[max_n];
    permutation() {
        memset(a, 0, sizeof(a));
    }
    permutation(int n, int b[]) : n(n) {
        for (int i = 0; i <= n; ++i) {
            a[i] = b[i];
        }
    }
    void read(int nn = -1) {
        if (nn == -1) {
            scanf("%d", &n);
        } else {
            n = nn;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
    }
    void write(const string &s = "") const {
        for (int i = 0; i < n; ++i) {
            printf("%d ", a[i]);
        }
        printf("%s", s.c_str());
    }
};

factorial_system factorial_system_from_permutation(const permutation &p) {
    factorial_system res;
    tree t;
    for (int i = 0; i < p.n; ++i) {
        t.update(1, 0, p.n - 1, i, 1);
    }
    res.n = p.n - 1;
    for (int i = 0; i < p.n; ++i) {
        if (p.a[i] == 0) {
            res.a[p.n - i - 1] = 0;
        } else {
            res.a[p.n - i - 1] = t.get_sum(1, 0, p.n - 1, 0, p.a[i] - 1);
        }
        t.update(1, 0, p.n - 1, p.a[i], 0);
    }
    return res;
}

permutation permutation_from_factorial_system(const factorial_system &f) {
    permutation res;
    tree t;
    res.n = f.n + 1;
    for (int i = 0; i < res.n; ++i) {
        t.update(1, 0, res.n - 1, i, 1);
    }
    for (int i = 0; i < res.n; ++i) {
        int x = f.a[res.n - i - 1] + 1;
        int l = -1, r = res.n - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (t.get_sum(1, 0, res.n - 1, 0, mid) < x) {
                l = mid;
            } else {
                r = mid;
            }
        }
        res.a[i] = r;
        t.update(1, 0, res.n - 1, r, 0);
    }
    return res;
}

int n;
permutation p1, p2, ans;
factorial_system a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    p1.read(n);
    p2.read(n);
    a = factorial_system_from_permutation(p1);
    b = factorial_system_from_permutation(p2);
    a = a + b;
    if (a.n == n) {
        a.a[a.n] = 0;
        --a.n;
    }
    ans = permutation_from_factorial_system(a);
    ans.write();
    return 0;
}