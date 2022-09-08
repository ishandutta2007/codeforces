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

const int max_n = 111, max_y = 17, mod = 1000000007;

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
                long long x = 0;
                for (int k = 0; k < v[i].size(); ++k) {
                    x += (1LL * v[i][k] * m.v[k][j]) % mod;
                }
                res.v[i][j] = x % mod;
            }
        }
        return res;
    }
    void write(const string &s = "") const {
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v[i].size(); ++j) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        cout << s;
    }
};

matrix power(const matrix &a, long long b) {
    if (b <= 0) {
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

int n, c[max_n], dp[max_y];
long long k, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        if (a[i] == b[i]) {
            exit(228);
        }
        ++c[i];
    }
    b[n - 1] = k;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        matrix A(c[i], c[i]);
        matrix V(1, c[i]);
        for (int j = 0; j < c[i]; ++j) {
            V.v[0][j] = dp[j];
            for (int k = max(j - 1, 0); k < c[i] && k <= j + 1; ++k) {
                A.v[j][k] = 1;
            }
        }
        V = V * power(A, b[i] - a[i] - 1);
        int sz = c[i];
        if (i + 1 < n) {
            sz = min(sz, c[i + 1]);
        }
        if (a[i] != b[i]) {
            memset(dp, 0, sizeof(dp));
            for (int j = 0; j < sz; ++j) {
                for (int k = max(j - 1, 0); k <= j + 1 && k < V.v[0].size(); ++k) {
                    dp[j] += V.v[0][k];
                    dp[j] %= mod;
                }
            }
        }
    }
    cout << dp[0] << endl;
    return 0;
}