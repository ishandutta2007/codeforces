#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MOD = 1e6 + 3;

inline void ModSum(int& x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
    if (x < 0) {
        x += MOD;
    }
}

inline int GetModSum(int x, int y) {
    ModSum(x, y);
    return x;
}

inline void ModMul(int& x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int GetBinaryPow(int x, long long pw) {
    int r = 1;
    while (pw > 0) {
        if (pw & 1) {
            ModMul(r, x);
        }
        ModMul(x, x);
        pw >>= 1;
    }
    return r;
}

inline int GetInv(int x) {
    return GetBinaryPow(x, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    if (n < 60 && k > (1LL << n)) {
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    long long upPower = n;
    for (int pw = 1; (1LL << pw) <= k - 1; ++pw) {
        upPower += (k - 1) / (1LL << pw);
    }

    int ch;
    if (k >= MOD) {
        ch = 0;
    } else {
        int b = GetBinaryPow(2, n);
        ch = b;
        for (long long i = 1; i <= k - 1; ++i) {
            ModMul(ch, GetModSum(b, GetModSum(0, -i)));
        }
    }

    int zn = GetBinaryPow(GetBinaryPow(2, n), k);

    int d = GetBinaryPow(GetInv(2), upPower);

    ModMul(ch, d);
    ModMul(zn, d);

    ch = GetModSum(0, -ch);
    ModSum(ch, zn);

    cout << ch << " " << zn << endl;

    return 0;
}