#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;

const int modulo = 1e9 + 7;
const int max_n = 111;
const int max_k = max_n * max_n;

int bin_pow(int base, ll pw) {
    if (pw == 0)
        return 1;
    if (pw & 1) 
        return (1LL * base * bin_pow(base, pw - 1)) % modulo;
    return bin_pow((1LL * base * base) % modulo, pw >> 1);
}

int a[max_n][max_k], C[max_n][max_n], d[max_n][max_n];
int n, k;
ll m;

int main() {
    ios_base::sync_with_stdio(false);
    C[0][0] = 1;
    for (int i = 1; i < max_n; ++i) {
        C[0][i] = 0;
        C[i][0] = 1;
    }
    for (int i = 1; i < max_n; ++i)
        for (int j = 1; j < max_n; ++j)
            C[i][j] = (0LL + C[i][j] + C[i - 1][j] + C[i - 1][j - 1]) % modulo;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= n; ++j) {
            ll pw = 1 + (m - i) / n;
            d[i][j] = bin_pow(C[n][j], pw);
        }
    a[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= min(k, i * n); ++j)
            for (int t = 0; t <= min(j, n); ++t)
                if (a[i - 1][j - t] != 0)
                    a[i][j] = (a[i][j] + 1LL * a[i - 1][j - t] * d[i][t]) % modulo;
    cout << a[n][k] << endl;
    return 0;
}