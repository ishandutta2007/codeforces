#pragma GCC optimize("Ofast")
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000003;
const int maxw = 107;

long long pw[maxw];

using Mat = vector<vector<long long>>;

Mat operator*(const Mat& a, const Mat& b) {
    int n = a.size();
    Mat c(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}

vector<long long> operator*(const Mat& a, const vector<long long>& v) {
    int n = v.size();
    vector<long long> u(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            u[i] += a[i][j] * v[j];
            u[i] %= mod;
        }
    }
    return u;
}

Mat operator^(const Mat& a, long long p) {
    if (p == 0) {
        int n = a.size();
        Mat c(n, vector<long long>(n));
        for (int i = 0; i < n; i++) c[i][i] = 1;
        return c;
    }
    if (p % 2 == 0) {
        auto c = a ^ (p / 2);
        return c * c;
    } else {
        return a * (a ^ (p - 1));
    }
}

int main() {
    long long n;
    int w, h;
    cin >> n >> w >> h;
    pw[0] = 1;
    for (int i = 1; i < maxw; i++) {
        pw[i] = pw[i - 1] * h % mod;
    }
    vector<long long> a(w + 1), b(w + 1);
    a[0] = 1, b[0] = 0;
    for (int i = 1; i <= w; i++) {
        a[i] = (a[i - 1] + b[i - 1]) % mod;
        for (int j = i - 1; j >= max(0, i - w); j--) {
            b[i] += a[j] * pw[i - j];
            b[i] %= mod;
        }
    }
    if (n <= w) {
        cout << (a[n] + b[n]) % mod << endl;
        return 0;
    }
    vector<vector<long long>> mat(2 * w, vector<long long>(2 * w));
    for (int i = 0; i < w - 1; i++) mat[i][i + 1] = 1;
    mat[w - 1][w - 1] = mat[w - 1][2 * w - 1] = 1;
    for (int i = w; i < 2 * w - 1; i++) mat[i][i + 1] = 1;
    for (int k = 0; k < w; k++) {
        mat[2 * w - 1][k] = pw[w - k];
    }
    auto res_mat = mat ^ (n - w);
    vector<long long> v(2 * w);
    for (int i = 0; i < w; i++) {
        v[i] = a[i + 1];
        v[i + w] = b[i + 1];
    }
    auto res = res_mat * v;
    cout << (res[w - 1] + res[2 * w - 1]) % mod << endl;
}