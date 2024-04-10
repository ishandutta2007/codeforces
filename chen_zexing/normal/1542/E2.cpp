#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;
long long mod,dp[505][125005],up[125005],pre[125005],tot[125005],cnt[505];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin >> n >> mod;
        if (n == 1) {
            puts("0");
            continue;
        }
        dp[1][0] = 1, pre[1] = 1;
        for (int i = 2; i < n; i++) {
            for (int j = 0; j <= i * (i - 1) / 2; j++)
                dp[i][j] = pre[min(j + 1, (i - 1) * (i - 2) / 2 + 1)] - pre[max(0, j - (i - 1))];
            for (int j = 1; j <= i * (i - 1) / 2 + 1; j++) pre[j] = (pre[j - 1] + dp[i][j - 1]) % mod;
        }
        for (int i = 1; i < n; i++) {
            for (int j = i * i / 2 + 1; j >= 0; j--)
                up[j] = (up[j + 1] + dp[i][j]) % mod;
            for (int j = i * i / 2 + 1; j >= 0; j--)
                up[j] += up[j + 1], up[j] %= mod;
            for (int j = i * i / 2 + 1; j >= 0; j--)
                tot[j] = (up[j] + tot[j + 1]) % mod;
            for (int j = 0; j <= i * i / 2; j++)
                cnt[i] += dp[i][j] * ((up[j + 2] * i % mod - tot[j + 3] + tot[min(j + i + 3, i * i / 2 + 1)]) % mod) %
                          mod, cnt[i] %= mod;
        }
        long long ans = 0, pre = 1;
        for (int i = 1; i < n; i++) ans += pre * cnt[n - i] % mod, pre *= n - i + 1, pre %= mod, ans %= mod;
        cout << (ans + mod) % mod << endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//