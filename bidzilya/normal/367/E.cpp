#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

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

inline int GetModMul(int x, int y) {
    ModMul(x, y);
    return x;
}

using TDpBase = vector<vector<vector<int>>>;

void Clear(TDpBase& dp, int n) {
    dp.assign(2, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;
    --x;

    if (n > m) {
        cout << 0 << endl;
        return 0;
    }

    TDpBase dp[2];

    int curPtr = 0;
    Clear(dp[curPtr], n);

    dp[curPtr][0][0][0] = 1;

    for (int i = 0; i < m; ++i) {
        const int nxtPtr = 1 - curPtr;
        Clear(dp[nxtPtr], n);

        for (int hasX = 0; hasX < 2; ++hasX) {
            for (int closedCount = 0; closedCount <= n; ++closedCount) {
                for (int openedCount = 0; closedCount + openedCount <= n; ++openedCount) {
                    for (int isOpen = 0; isOpen < 2; ++isOpen) {
                        for (int isClose = 0; isClose < 2; ++isClose) {
                            if (openedCount + isOpen - isClose >= 0 && openedCount + isOpen - isClose <= n &&
                                closedCount + isClose <= n)
                            {
                                ModSum(dp[nxtPtr][hasX || (isOpen && i == x)][closedCount + isClose][openedCount + isOpen - isClose],
                                       dp[curPtr][hasX][closedCount][openedCount]);
                            }
                        }
                    }
                }
            }
        }

        curPtr = nxtPtr;
    }

    int result = dp[curPtr][1][n][0];

    for (int i = 1; i <= n; ++i) {
        ModMul(result, i);
    }

    cout << result << endl;

    return 0;
}