#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, mod = 1000000007;

long long n, m;

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

    matrix transpose() const {
        matrix res(columns(), rows());
        for (int i = 0; i < rows(); ++i) {
            for (int j = 0; j < columns(); ++j) {
                res[j][i] = v[i][j];
            }
        }
        return res;
    }

    matrix operator + (const matrix &m) const {
        matrix res(rows(), columns());
        for (int i = 0; i < rows(); ++i) {
            for (int j = 0; j < columns(); ++j) {
                res[i][j] = v[i][j] + m[i][j];
                if (res[i][j] >= mod) {
                    res[i][j] -= mod;
                }
            }
        }
        return res;
    }

    matrix operator * (const matrix &m) const {
        matrix res(rows(), m.columns());
        matrix t = m.transpose();
        for (int i = 0; i < res.rows(); ++i) {
            for (int j = 0; j < res.columns(); ++j) {
                const int *first = v[i];
                const int *second = t[j];
                unsigned long long sum = 0;
                int it = 0;
                for (int k = 0; k < columns(); ++k) {
                    sum += 1LLU * (*first) * (*second);
                    ++first;
                    ++second;
                    ++it;
                    if (it == 18) {
                        sum %= mod;
                        it = 0;
                    }
                }
                res.v[i][j] = sum % mod;
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

private:
    int v[max_n][max_n];
    int rows_, columns_;
};

matrix power(const matrix &a, long long b) {
    if (b == 0) {
        matrix res(a.rows(), a.columns());
        for (int i = 0; i < res.rows(); ++i) {
            res[i][i] = 1;
        }
        return res;
    }
    if (b % 2 == 0) {
        return power(a * a, b / 2);
    }
    return a * power(a, b - 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    matrix A(m, m);
    matrix V(1, m);
    for (int i = 0; i < m; ++i) {
        V[0][i] = 1;
    }
    V[0][m - 1] = 2;
    for (int i = 0; i + 1 < m; ++i) {
        A[i + 1][i] = 1;
    }
    A[m - 1][m - 1] = 1;
    A[0][m - 1] = 1;
    --n;
    matrix ans = V * power(A, n);
    cout << ans[0][0] << endl;
    return 0;
}