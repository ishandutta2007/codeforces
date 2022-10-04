#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const int MOD = 1e9 + 7;
const int mx = 1200;
int dp[mx + 1], dp1[mx + 1][mx + 1], dp2[mx + 1][mx + 1], k;
string n;
int N;

int cnt(int x) {
    int res = 0;
    for (int i = 0; i < 20; ++i) {
        if (((x >> i) & 1) == 1) {
            res++;
        }
    }
    return res;
}

int main()
{
    for (int i = 0; i <= mx; ++i) {
        dp[i] = -1;
    }
    dp[1] = 0;
    for (int i = 2; i <= mx; ++i) {
        dp[i] = dp[cnt(i)] + 1;
    }
    cin >> n >> k;
    dp1[0][0] = 1;
    dp2[0][0] = 1;
    for (int i = 1; i <= n.size(); ++i) {
        dp1[i][0] = 1;
        dp2[i][0] = 1;
        if (n[n.size() - i] == '0') {
            for (int j = 1; j <= mx; ++j) {
                dp1[i][j] = dp1[i - 1][j];
                dp2[i][j] = (dp2[i - 1][j] + dp2[i - 1][j - 1]) % MOD;
            }
        }
        else {
            for (int j = 1; j <= mx; ++j) {
                dp1[i][j] = (dp2[i - 1][j] + dp1[i - 1][j - 1]) % MOD;
                dp2[i][j] = (dp2[i - 1][j] + dp2[i - 1][j - 1]) % MOD;
            }
        }
    }
    if (k == 0) {
        cout << 1 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= mx; ++i) {
        if (dp[i] == k - 1) {
            ans = (ans + dp1[n.size()][i]) % MOD;
        }
    }
    if (k > 1)
        cout << ans << endl;
    else
        cout << ans - 1 << endl;
    return 0;
}