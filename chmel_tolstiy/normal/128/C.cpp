#include <iostream>

using namespace std;

const int MOD = 1000000007;

const int nn = 1 << 10;
long long f[1<<10][1<<10];

long long solve() {

    for (int j = 1; j < nn; j++)
        f[1][j] = (j - 1) * (j - 2) / 2;

    for (int i = 2; i < nn; i++) {
        long long s = 0;
        f[i][1] = 0;
        for (int j = 2; j < nn; j++) {
            s += f[i-1][j-2];
            f[i][j] = (s + f[i][j-1]) % MOD;
        }
    }

    int n, m, k;
    cin >> n >> m >> k;
    long long H = f[k][n], V = f[k][m];

    return H * V % MOD;
}

int main() {
    cout << solve() << endl;
    return 0;
}