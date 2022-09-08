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

const int max_n = 111, mod = 1000000007;

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

matrix power(matrix a, long long b) {
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

int n, b, k, x, a[max_n], used[max_n], f[max_n], num[2][max_n], res[max_n], dp[2][max_n];
matrix m, m1;
map<int, matrix> q;
vector<int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &b, &k, &x);
    for (int i = 0; i < n; ++i) {
        int q;
        scanf("%d", &q);
        ++a[q];
    }
    int pw = 1, cnt = 0;
    while (used[pw] == 0) {
        used[pw] = 1;
        num[0][pw] = cnt;
        pw = (pw * 10) % x;
        ++cnt;
    }
    int all = cnt;
    cnt = 0;
    while (f[pw] == 0) {
        f[pw] = 1;
        num[1][pw] = cnt;
        pw = (pw * 10) % x;
        ++cnt;
    }
    for (int i = 0; i < x; ++i) {
        if (used[i] == 1 && num[0][i] < b) {
            res[i] = 1;
        }
        if (f[i] == 1) {
            int kb = b - all - num[1][i] - 1;
            if (kb >= 0) {
                res[i] += kb / cnt + 1;
            }
        }
    }
    m = matrix(x, x);
    m1 = matrix(1, x);
    m1.v[0][0] = 1;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) {
            for (int d = 1; d <= 9; ++d) {
                if ((j + d) % x == i) {
                    m.v[j][i] += a[d];
                }
            }
        }
    }
    int q1 = 0, q2 = 1;
    dp[q1][0] = 1;
    for (int i = 0; i < x; ++i) {
        matrix M;
        if (q.count(res[i])) {
            M = q[res[i]];
        } else {
            M = m1 * power(m, res[i]);
            q[res[i]] = M;
        }
        for (int j = 0; j < x; ++j) {
            dp[q2][j] = 0;
        }
        for (int j = 0; j < x; ++j) {
            for (int k = 0; k < x; ++k) {
                dp[q2][(j + i * k) % x] += (1LL * dp[q1][j] * M.v[0][k]) % mod;
                dp[q2][(j + i * k) % x] %= mod;
            }
        }
        swap(q1, q2);
        /*cout << i << " " << res[i] << " : ";
        for (int j = 0; j < x; ++j) {
            cout << dp[q1][j] << " ";
        }
        cout << endl;*/
    }
    printf("%d\n", dp[q1][k]);
    return 0;
}