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

const int max_n = 22, max_q = 11111, mod = 1000000007;

struct matrix {
    vector<vector<int> > v;
    matrix() {
    }
    matrix(int n, int m) {
        v.resize(n, vector<int>(m, 0));
    }
    matrix operator * (const matrix &m) const {
        matrix res(v.size(), m.v[0].size());
        for (int i = 0; i < res.v.size(); ++i) {
            for (int j = 0; j < res.v[i].size(); ++j) {
                for (int k = 0; k < v[i].size(); ++k) {
                    res.v[i][j] += (1LL * v[i][k] * m.v[k][j]) % mod;
                    res.v[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

matrix power(matrix a, int b) {
    if (b == 0) {
        matrix res(a.v.size(), a.v.size());
        for (int i = 0; i < res.v.size(); ++i) {
            res.v[i][i] = 1;
        }
        return res;
    }
    if (b % 2 == 0) {
        return power(a * a, b / 2);
    }
    return a * power(a, b - 1);
}

const int dx[] = {-1, 1, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0};

int n, m, q, tp[max_q], x[max_q], y[max_q], t[max_q], f[max_q], a[max_n][max_n];
matrix dp, p;

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

void get_p() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 5; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (is_in(x, y)) {
                    p.v[i * m + j][x * m + y] = 0;
                    if (a[x][y] == 0) {
                        p.v[i * m + j][x * m + y] = 1;
                    }
                }
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d%d", &tp[i], &x[i], &y[i], &t[i]);
        --x[i];
        --y[i];
        if (tp[i] == 3) {
            ++t[i];
        }
    }
    dp = matrix(1, n * m);
    p = matrix(n * m, n * m);
    get_p();
    dp.v[0][0] = 1;
    int nt = 1;
    for (int i = 0; i < q; ++i) {
        if (t[i] != nt) {
            dp = dp * power(p, t[i] - nt - 1);
        }
        while (i + 1 < q && t[i] == t[i + 1]) {
            if (tp[i] == 2) {
                a[x[i]][y[i]] = 1;
            }
            if (tp[i] == 3) {
                a[x[i]][y[i]] = 0;
            }
            ++i;
        }
        if (tp[i] == 2) {
            a[x[i]][y[i]] = 1;
        }
        if (tp[i] == 3) {
            a[x[i]][y[i]] = 0;
        }
        get_p();
        if (t[i] != nt) {
            dp = dp * p;
        }
        nt = t[i];
        if (tp[i] == 1) {
            printf("%d\n", dp.v[0][x[i] * m + y[i]]);
        }
    }
    return 0;
}