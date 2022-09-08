#include <bits/stdc++.h>

using namespace std;

const int max_x = 100111;
const int max_n = 200333, mod = 2;

class matrix {
public:
    matrix() {
        rows_ = columns_ = 0;
    }

    matrix(int n, int m): rows_(n), columns_(m) {
        memset(v, 0, sizeof(v));
    }

    int rows() const {
        return rows_;
    }

    int columns() const {
        return columns_;
    }

    matrix operator * (const matrix &m) const {
        matrix res(rows(), m.columns());
        for (int i = 0; i < res.rows(); ++i) {
            for (int j = 0; j < res.columns(); ++j) {
                for (int k = 0; k < columns(); ++k) {
                    res.v[i][j] += v[i][k] * m.v[k][j];
                }
                res.v[i][j] %= 2;
            }
        }
        return res;
    }

    int* operator [] (int row) {
        return v[row];
    }

    const int* operator [] (int row) const {
        return v[row];
    }

    bool operator == (const matrix &m) const {
        if (rows() == m.rows() && columns() == m.columns()) {
            for (int i = 0; i < rows(); ++i) {
                for (int j = 0; j < columns(); ++j) {
                    if (v[i][j] != m[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        }
        return false;
    }

    friend ostream &operator << (ostream &os, const matrix &m) {
        for (int i = 0; i < m.rows(); ++i) {
            for (int j = 0; j < m.columns(); ++j) {
                os << m[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }

    int v[2][2];
    int rows_, columns_;
};

struct tree {
    matrix f[4 * max_n];

    tree() {
        for (int i = 0; i < 4 * max_n; ++i) {
            f[i] = matrix(2, 2);
            f[i].v[0][0] = f[i].v[1][1] = 1;
        }
    }

    void push(int v) {
        f[2 * v] = f[2 * v] * f[v];
        f[2 * v + 1] = f[2 * v + 1] * f[v];
        f[v].v[0][0] = 1;
        f[v].v[1][1] = 1;
        f[v].v[0][1] = 0;
        f[v].v[1][0] = 0;
    }

    void update(int v, int tl, int tr, int l, int r, const matrix &x) {
        //cout << tl << " " << tr << " " << l << " " << r << endl;
        if (tl == l && tr == r) {
            f[v] = f[v] * x;
            return;
        }
        push(v);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, x);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, x);
        } else {
            update(2 * v, tl, mid, l, mid, x);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, x);
        }
    }

    matrix get(int v, int tl, int tr, int pos) {
        //cout << f[v] << endl;
        if (tl == tr) {
            return f[v];
        }
        push(v);
        int mid = (tl + tr) / 2;
        if (pos <= mid) {
            return get(2 * v, tl, mid, pos);
        }
        return get(2 * v + 1, mid + 1, tr, pos);
    }
};

int n, q, a[max_n];
tree t;
matrix eq0, eq1, m_xor;

void eq(int l, int r, const matrix &m) {
    //cout << "= " << l << " " << r << endl;
    l += max_x;
    r += max_x;
    t.update(1, 0, 2 * max_x, l, r, m);
}

void upd_xor(int l, int r) {
    //cout << "^ " << l << " " << r << endl;
    l += max_x;
    r += max_x;
    t.update(1, 0, 2 * max_x, l, r, m_xor);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    eq0 = matrix(2, 2);
    eq1 = matrix(2, 2);
    m_xor = matrix(2, 2);
    eq0.v[1][0] = 0;
    eq0.v[1][1] = 1;
    eq1.v[1][0] = 1;
    eq1.v[1][1] = 1;
    m_xor.v[0][0] = 1;
    m_xor.v[1][0] = 1;
    m_xor.v[1][1] = 1;
    while (q--) {
        char tp;
        int x;
        scanf("\n%c%d", &tp, &x);
        if (tp == '>') {
            if (x >= 0) {
                eq(x + 1, max_x, eq0);
                eq(-max_x, -x - 1, eq1);
            } else {
                eq(-x, max_x, eq0);
                eq(-max_x, x, eq1);
                upd_xor(x + 1, -x - 1);
            }
        } else {
            if (x <= 0) {
                eq(-max_x, x - 1, eq0);
                eq(-x + 1, max_x, eq1);
            } else {
                eq(-max_x, -x, eq0);
                eq(x, max_x, eq1);
                upd_xor(-x + 1, x - 1);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        const matrix &m = t.get(1, 0, 2 * max_x, a[i] + max_x);
        int res = (m.v[0][0] + m.v[1][0]) % 2;
        if (res == 0) {
            a[i] *= -1;
        }
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}