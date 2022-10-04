#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll mx = 5010;
const ll MOD = 1e9 + 7;
ll n, dp[mx][mx], a[mx], suf[mx];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == 's')
            a[i] = 0;
        else
            a[i] = 1;
    }
    dp[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        suf[n] = dp[i - 1][n];
        for (int j = n - 1; j >= 0; --j) {
            suf[j] = (suf[j + 1] + dp[i - 1][j]) % MOD;
        }
        if (a[i - 1] == 0) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = suf[j];
            }
        }
        else {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    if (a[n - 1] == 1)
        cout << 0 << endl;
    else {
        ll s = 0;
        for (int i = 0; i < n; ++i) {
            s = (s + dp[n - 1][i]) % MOD;
        }
        cout << s << endl;
    }
    return 0;
}