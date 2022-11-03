#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

inline void ModMul(int& x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int GetModMul(int x, int y) {
    ModMul(x, y);
    return x;
}

inline void ModSum(int& x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

inline int GetModSum(int x, int y) {
    ModSum(x, y);
    return x;
}

int GetBinaryPow(int x, long long pw) {
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

int GetInv(int x) {
    return GetBinaryPow(x, MOD - 2);
}

using TMatr = vector<vector<int>>;

TMatr operator * (const TMatr& lhs, const TMatr& rhs) {
    TMatr result(lhs.size(), vector<int>(rhs[0].size(), 0));
    for (int i = 0; i < (int) result.size(); ++i) {
        for (int j = 0; j < (int) result[i].size(); ++j) {
            for (int t = 0; t < (int) lhs[i].size(); ++t) {
                result[i][j] += lhs[i][t] * rhs[t][j];
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    vector<long long> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }

    int down = GetBinaryPow(2, a[0]);
    for (int i = 1; i < k; ++i) {
        down = GetBinaryPow(down, a[i]);
    }
    int up = down;
    ModMul(down, GetInv(2));

    bool even = false;
    for (int i = 0; i < k; ++i) {
        if ((a[i] & 1) == 0) {
            even = true;
            break;
        }
    }

    if (even) {
        ModMul(up, GetInv(4));
    } else {
        ModMul(up, GetInv(2));
    }

    --up;
    if (up < 0) {
        up += MOD;
    }
    ModMul(up, GetInv(3));

    if (even) {
        ModMul(up, 2);
        ModSum(up, 1);
    }

    cout << up << "/" << down << endl;

    /*

    TMatr base = {{1, 1}, {2, 0}};

    TMatr a = base;

    for (int i = 1; i <= 20; ++i) {
        int x = a[1][1];
        int pw = i;
        while (pw > 0 && (x & 1) == 0) {
            x >>= 1;
            --pw;
        }
        cout << i << ": " << x << " " << pw << endl;
        a = a * base;
    }
    */

    return 0;
}