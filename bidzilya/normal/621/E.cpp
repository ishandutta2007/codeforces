#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

using TMatr = vector<vector<int>>;

TMatr GetOne(int n) {
    TMatr result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1;
    }
    return result;
}

TMatr GetMult(const TMatr& lhs, const TMatr& rhs) {
    int n = lhs.size();
    TMatr result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][k] += (1LL * lhs[i][j] * rhs[j][k]) % MOD;
                if (result[i][k] >= MOD) {
                    result[i][k] -= MOD;
                }
            }
        }
    }
    return result;
}

TMatr GetBinaryPow(const TMatr& a, int pw) {
    if (pw == 0) {
        return GetOne(a.size());
    }
    if (pw & 1) {
        return GetMult(a, GetBinaryPow(a, pw - 1));
    }
    return GetBinaryPow(GetMult(a, a), pw >> 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b, k, x;

    cin >> n >> b >> k >> x;
    vector<int> count(10, 0);
    for (int i = 0; i < n; ++i) {
        int cur;
        cin >> cur;
        ++count[cur];
    }

    TMatr base(x, vector<int>(x, 0));
    for (int prev = 0; prev < x; ++prev) {
        for (int digit = 1; digit < 10; ++digit) {
            int next = (prev * 10 + digit) % x;
            base[prev][next] += count[digit];
            if (base[prev][next] >= MOD) {
                base[prev][next] -= MOD;
            }
        }
    }

    base = GetBinaryPow(base, b);

    int result = base[0][k];

    cout << result << endl;

    return 0;
}