#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

int GetBinaryPow(int x, int pw) {
    int result = 1;
    while (pw) {
        if (pw & 1) {
            result = (1LL * result * x) % MOD;
        }
        pw >>= 1;
        x = (1LL * x * x) % MOD;
    }
    return result;
}

const int INV2 = GetBinaryPow(2, MOD - 2);

void Update(long long n, long long k, long long yMin, long long yMax, int& result) {
    result += (1LL * (n % MOD) * ((yMax - yMin + 1) % MOD)) % MOD;
    if (result >= MOD) {
        result -= MOD;
    }

    int buf = (1LL * ((1LL * ((yMin + yMax) % MOD) * ((yMax - yMin + 1) % MOD)) % MOD) * INV2) % MOD;

    result -= (1LL * (k % MOD) * buf) % MOD;
    if (result < 0) {
        result += MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    int result = 0;
    if (m > n) {
        result += ((n % MOD) * ((m - n) % MOD)) % MOD;
        if (result >= MOD) {
            result -= MOD;
        }
        m = n;
    }

    const long long C = 4e6;

    for (int k = 1; k <= C; ++k) {
        long long yMax = n / k;
        long long yMin = n / (k + 1) + 1;

        yMax = min(yMax, m);

        if (yMin > yMax) {
            continue;
        }

        Update(n, k, yMin, yMax, result);
    }

    for (int y = 1; y <= C && y <= m; ++y) {
        long long kMax = n / y;
        long long kMin = (n - y) / y + 1;

        kMin = max(kMin, C + 1);

        if (kMin > kMax) {
            continue;
        }

        Update(n, y, kMin, kMax, result);
    }

    cout << result << endl;

    return 0;
}