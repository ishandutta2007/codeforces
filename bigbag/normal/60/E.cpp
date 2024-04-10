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

const int max_n = 1111111;

long long n, x, y, p, a[max_n];

struct matrix {
    vector<vector<long long> > v;
    matrix() {
        v.clear();
    }
    matrix(const int &n, const int &m) {
        v = vector<vector<long long> >(n, vector<long long>(m, 0));
    }
    matrix operator * (const matrix &b) const {
        matrix a = *this;
        int n = a.v.size();
        int m = a.v[0].size();
        int k = b.v[0].size();
        matrix res(n, k);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                res.v[i][j] = 0;
                for (int t = 0; t < m; ++t) {
                    res.v[i][j] = ((res.v[i][j] + a.v[i][t] * b.v[t][j]) % p + p) % p;
                }
            }
        }
        return res;
    }
};

matrix ones(int n) {
    matrix res(n, n);
    for (int i = 0; i < n; ++i) {
        res.v[i][i] = 1;
    }
    return res;
}

matrix pow_mod(matrix a, long long n) {
    if (n == 0) {
        return ones(a.v.size());
    }
    if (n % 2 == 0) {
        return pow_mod(a * a, n / 2);
    }
    return a * pow_mod(a, n - 1);
}

long long power(long long a, long long n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return power(a * a, n / 2);
    }
    return (a * power(a, n - 1)) % p;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> x >> y >> p;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum = (sum + a[i]) % p;
    }
    if (n == 1) {
        cout << a[0] % p << endl;
        return 0;
    }
    matrix m1(3, 3), m2(3, 1);
    m1.v[0][0] = 3;
    m1.v[0][1] = -1;
    m1.v[0][2] = -1;
    m1.v[1][1] = 1;
    m1.v[2][2] = 1;
    m2.v[0][0] = sum;
    m2.v[1][0] = a[0];
    m2.v[2][0] = a[n - 1];
    m1 = pow_mod(m1, x) * m2;
    //cout << m1.v[0][0] << endl;
    sum = m1.v[0][0];


    matrix q1(2, 2), q2(2, 1);
    q1.v[0][0] = 0;
    q1.v[0][1] = 1;
    q1.v[1][0] = 1;
    q1.v[1][1] = 1;
    q2.v[0][0] = a[n - 2];
    q2.v[1][0] = a[n - 1];
    q1 = pow_mod(q1, x) * q2;


    m1 = matrix(3, 3);
    m1.v[0][0] = 3;
    m1.v[0][1] = -1;
    m1.v[0][2] = -1;
    m1.v[1][1] = 1;
    m1.v[2][2] = 1;
    m2.v[0][0] = sum;
    m2.v[1][0] = a[0];
    m2.v[2][0] = q1.v[1][0];
    m1 = pow_mod(m1, y) * m2;
    cout << m1.v[0][0] % p << endl;
    return 0;
}