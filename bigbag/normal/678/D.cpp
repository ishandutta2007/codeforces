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

const long long mod = 1000000007LL;

struct matrix {
    vector<vector<long long> > v;
    matrix() {
    }
    matrix(int n, int m) {
        v.resize(n, vector<long long>(m, 0));
    }
    matrix operator * (const matrix &m) const {
        matrix res(v.size(), m.v[0].size());
        for (int i = 0; i < res.v.size(); ++i) {
            for (int j = 0; j < res.v[i].size(); ++j) {
                for (int k = 0; k < v[i].size(); ++k) {
                    res.v[i][j] += v[i][k] * m.v[k][j];
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

long long a, b, n, x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> n >> x;
    matrix A(1, 2);
    A.v[0][0] = b;
    A.v[0][1] = x;
    matrix B(2, 2);
    B.v[0][0] = 1;
    B.v[0][1] = 1;
    B.v[1][0] = 0;
    B.v[1][1] = a;
    A = A * power(B, n);
    cout << A.v[0][1] << endl;
    return 0;
}