#include <iostream>
#include <vector>
#include <string>

#include <cassert>
using namespace std;

const int MOD = 1e9 + 7;

inline void ModSum(int& x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

inline int GetScore(char c) {
    if (c == '(') {
        return 1;
    } else if (c == ')') {
        return -1;
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int minSum = 0;
    int curSum = 0;
    for (int i = 0; i < (int) s.length(); ++i) {
        curSum += GetScore(s[i]);
        if (curSum < 0) {
            minSum = max(minSum, abs(curSum));
        }
    }

    int k = n - m;

    vector<vector<int>> dp1(k + 1, vector<int>(k + 1, 0));
    dp1[0][0] = 1;
    for (int l = 0; l + 1 <= k; ++l) {
        for (int c = 0; c <= l; ++c) {
            ModSum(dp1[l + 1][c + 1], dp1[l][c]);
            if (c > 0) {
                ModSum(dp1[l + 1][c - 1], dp1[l][c]);
            }
        }
    }

    int result = 0;
    for (int l = 0; l <= k; ++l) {
        for (int t = minSum; t <= k; ++t) {
            if (t + curSum <= k) {
                ModSum(result, (1LL * dp1[l][t] * dp1[k - l][t + curSum]) % MOD);
            }
        }
    }

    cout << result << endl;

    return 0;
}