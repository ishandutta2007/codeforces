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

const int max_n = 333333, inf = 1111111111;
const double pi = 2 * acos(0.0);

struct matrix {
    int n, m;
    double v[3][3];
    matrix() {
    }
    matrix(int n, int m) : n(n), m(m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                v[i][j] = 0;
            }
        }
    }
    matrix operator * (const matrix &M) const {
        matrix res(n, M.m);
        for (int i = 0; i < res.n; ++i) {
            for (int j = 0; j < res.m; ++j) {
                for (int k = 0; k < m; ++k) {
                    res.v[i][j] += v[i][k] * M.v[k][j];
                }
            }
        }
        return res;
    }
};

struct tree {
    matrix a[4 * max_n], f[4 * max_n];
    tree() {
        for (int i = 0; i < 4 * max_n; ++i) {
            a[i] = matrix(1, 3);
            a[i].v[0][0] = 0;
            a[i].v[0][1] = 0;
            a[i].v[0][2] = 1;
            f[i] = matrix(3, 3);
            f[i].v[0][0] = f[i].v[1][1] = f[i].v[2][2] = 1;
        }
    }
    void push(int v, int l, int r) {
        if (l != r) {
            f[2 * v] = f[2 * v] * f[v];
            a[2 * v] = a[2 * v] * f[v];
            a[2 * v + 1] = a[2 * v + 1] * f[v];
            f[2 * v + 1] = f[2 * v + 1] * f[v];
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == j) {
                    f[v].v[i][j] = 1;
                } else {
                    f[v].v[i][j] = 0;
                }
            }
        }
    }
    void update(int v, int l, int r, int tl, int tr, matrix m) {
        push(v, l, r);
        if (tl == l && tr == r) {
            a[v] = a[v] * m;
            f[v] = f[v] * m;
            return;
        }
        int mid = (l + r) / 2;
        if (tr <= mid) {
            update(2 * v, l, mid, tl, tr, m);
        } else if (tl > mid) {
            update(2 * v + 1, mid + 1, r, tl, tr, m);
        } else {
            update(2 * v, l, mid, tl, mid, m);
            update(2 * v + 1, mid + 1, r, mid + 1, tr, m);
        }
    }
    matrix get(int v, int l, int r, int x) {
        push(v, l, r);
        if (l == r) {
            return a[v];
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            return get(2 * v, l, mid, x);
        }
        return get(2 * v + 1, mid + 1, r, x);
    }
};

int n, m;
tree t;

void add(int l, int r, double x, double y) {
    matrix m(3, 3);
    m.v[0][0] = 1;
    m.v[0][1] = 0;
    m.v[0][2] = 0;
    m.v[1][0] = 0;
    m.v[1][1] = 1;
    m.v[1][2] = 0;
    m.v[2][0] = x;
    m.v[2][1] = y;
    m.v[2][2] = 1;
    t.update(1, 0, n, l, r, m);
}

void upd(int l, int r, double a) {
    matrix m(3, 3);
    m.v[0][0] = cos(a);
    m.v[0][1] = -sin(a);
    m.v[0][2] = 0;
    m.v[1][0] = sin(a);
    m.v[1][1] = cos(a);
    m.v[1][2] = 0;
    m.v[2][0] = 0;
    m.v[2][1] = 0;
    m.v[2][2] = 1;
    t.update(1, 0, n, l, r, m);
}

void write(int poz) {
    matrix q = t.get(1, 0, n, poz);
    printf("%.10f %.10f\n", q.v[0][0], q.v[0][1]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i) {
        add(i, i, i, 0);
    }
    while (m--) {
        int tp, a, b;
        scanf("%d%d%d", &tp, &a, &b);
        if (tp == 1) {
            matrix q = t.get(1, 0, n, a - 1);
            matrix q2 = t.get(1, 0, n, a);
            double x = q2.v[0][0] - q.v[0][0];
            double y = q2.v[0][1] - q.v[0][1];
            double d = sqrt(x * x + y * y);
            x *= b / d;
            y *= b / d;
            add(a, n, x, y);
        } else {
            matrix q = t.get(1, 0, n, a - 1);
            //write(a - 1);
            add(a, n, -q.v[0][0], -q.v[0][1]);
            //write(n);
            double ang = b * pi / 180.0;
            upd(a, n, ang);
            add(a, n, q.v[0][0], q.v[0][1]);
        }
        write(n);
    }
    return 0;
}