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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    cin >> n >> h;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(h + 1, 0));
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int closedCount = 0; closedCount <= h; ++closedCount) {
            for (int isClosed = 0; isClosed < 2; ++isClosed) {
                for (int isOpened = 0; isOpened < 2; ++isOpened) {
                    if (a[i] + closedCount + isClosed == h && closedCount + isClosed - isOpened <= h && closedCount + isClosed - isOpened >= 0) {
                        ModSum(dp[i][closedCount + isClosed - isOpened],
                            GetModMul(dp[i + 1][closedCount],
                                (isOpened ? closedCount + isClosed : 1)));
                    }
                }
            }
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}