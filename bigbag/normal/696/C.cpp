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

const int mod = 1000000007;

int power(int a, long long b) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2);
    }
    return (1LL * a * power(a, b - 1)) % mod;
}

struct matrix2 {
    int n, m, v[2][2];
    matrix2() {
    }
    matrix2(int nn, int mm) {
        n = nn;
        m = mm;
        memset(v, 0, sizeof(v));
    }
    matrix2 operator * (const matrix2 &q) const {
        matrix2 res(n, q.m);
        for (int i = 0; i < res.n; ++i) {
            for (int j = 0; j < res.m; ++j) {
                for (int k = 0; k < m; ++k) {
                    res.v[i][j] += (1LL * v[i][k] * q.v[k][j]) % mod;
                    res.v[i][j] %= mod;
                    if (res.v[i][j] < 0) {
                        res.v[i][j] += mod;
                    }
                }
            }
        }
        return res;
    }
};

matrix2 power(matrix2 a, long long b) {
    if (b == 0) {
        matrix2 res(a.n, a.n);
        for (int i = 0; i < res.n; ++i) {
            res.v[i][i] = 1;
        }
        return res;
    }
    if (b % 2 == 0) {
        return power(a * a, b / 2);
    }
    return a * power(a, b - 1);
}


int n;
long long x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    matrix2 A = matrix2(1, 2);
    matrix2 B = matrix2(2, 2);
    A.v[0][0] = 0;
    A.v[0][1] = 1;
    B.v[0][0] = 0;
    B.v[0][1] = 2;
    B.v[1][0] = 1;
    B.v[1][1] = 1;
    matrix2 C = matrix2(2, 2);
    C = B;
    int q = 2;
    while (n--) {
        scanf("%I64d", &x);
        C = power(C, x);
        q = power(q, x);
    }
    B.v[0][0] = -power(2, mod - 2);
    B.v[0][1] = 1;
    B.v[1][0] = power(2, mod - 2);
    B.v[1][1] = 0;
    C = C * B;
    A = A * C;
    printf("%d/%d\n", A.v[0][0], (1LL * q * power(2, mod - 2)) % mod);
    return 0;
}