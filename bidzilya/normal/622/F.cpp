#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

void Normalize(int& x) {
    while (x >= MOD) {
        x -= MOD;
    }
    while (x < 0) {
        x += MOD;
    }
}

inline void ModSum(int& x, int y) {
    x += y;
    Normalize(x);
}

inline int GetModSum(int x, int y) {
    ModSum(x, y);
    return x;
}

inline void ModMul(int& x, int y) {
    x = (1LL * x * y) % MOD;
    Normalize(x);
}

inline int GetModMul(int x, int y) {
    ModMul(x, y);
    return x;
}

inline int GetBinaryPow(int x, int pow) {
    if (pow == 0) {
        return 1;
    }
    if (pow & 1) {
        return GetModMul(x, GetBinaryPow(x, pow - 1));
    }
    return GetBinaryPow(GetModMul(x, x), pow >> 1);
}

inline int GetInv(int x) {
    return GetBinaryPow(x, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    if (n <= k + 2) {
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            ModSum(result, GetBinaryPow(i, k));
        }
        cout << result << endl;
        return 0;
    }

    vector<int> values(k + 3);
    values[1] = 1;
    for (int i = 2; i <= k + 2; ++i) {
        values[i] = GetModSum(values[i - 1], GetBinaryPow(i, k));
    }

    vector<int> fact(k + 2);
    fact[0] = 1;
    for (int i = 1; i <= k + 1; ++i) {
        fact[i] = GetModMul(fact[i - 1], i);
    }

    int top = 1;
    for (int i = 1; i <= k + 2; ++i) {
        ModMul(top, n - i);
    }

    int result = 0;
    for (int i = 1; i <= k + 2; ++i) {
        int curTop = GetModMul(top, values[i]);
        int curBot = n - i;
        if (i != 1) {
            ModMul(curBot, fact[i - 1]);
        }
        if (i != k + 2) {
            ModMul(curBot, fact[(k + 2) - i]);
        }
        int curResult = GetModMul(curTop, GetInv(curBot));
        if (i != k + 2 && (k + 2 - i) & 1) {
            ModMul(curResult, -1);
        }
        ModSum(result, curResult);
    }

    cout << result << endl;

    return 0;
}