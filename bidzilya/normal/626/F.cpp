#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

void ModSum(int& x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
    if (x < 0) {
        x += MOD;
    }
}

const int MAX_N = 2e2;
const int MAX_K = 1e3;

int dp[2][MAX_N + 1][MAX_K + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    a.push_back(a.back());

    int curPtr = 0;
    dp[curPtr][0][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        int nxtPtr = 1 - curPtr;
        for (int j = 0; j <= n; ++j) {
            for (int s = 0; s <= k; ++s) {
                dp[nxtPtr][j][s] = 0;
            }
        }
        for (int j = 0; j <= n; ++j) {
            for (int ck = 0; ck <= k; ++ck) {
                int newK = ck + j * (a[i + 1] - a[i]);
                if (newK <= k) {
                    ModSum(dp[nxtPtr][j][newK], dp[curPtr][j][ck]);
                    if (j > 0) {
                        ModSum(dp[nxtPtr][j - 1][newK], (1LL * j * dp[curPtr][j][ck]) % MOD);
                    }
                    if (j + 1 <= n) {
                        ModSum(dp[nxtPtr][j + 1][newK], dp[curPtr][j][ck]);
                    }
                    ModSum(dp[nxtPtr][j][newK], (1LL * j * dp[curPtr][j][ck]) % MOD);
                }
            }
        }
        swap(curPtr, nxtPtr);
    }

    int result = 0;
    for (int i = 0; i <= k; ++i) {
        ModSum(result, dp[curPtr][0][i]);
    }
    cout << result << endl;

    return 0;
}