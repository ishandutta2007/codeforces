#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define vi ve<int>
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define ii pair<int, int>
#define sz(v) ((int) v.size())

int n;
vi a;

ve<vi> dp;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    dp.resize(3, vi(n));
    dp[0][0] = 0;
    dp[1][0] = a[0] & 1;
    dp[2][0] = (a[0] >> 1) & 1;

    for (int i = 1; i < n; ++i)
    for (int f = 0; f < 3; ++f)
    for (int g = 0; g < 3; ++g) {
        if (f == g and f != 0) continue;
        if (f != 0) if (~(a[i] >> (f - 1)) & 1) continue;
        if (g != 0) if (~(a[i - 1] >> (g - 1)) & 1) continue;
        dp[f][i] = max(dp[f][i], dp[g][i - 1] + (f != 0));
    }

    cout << n - max(dp[0].back(), max(dp[1].back(), dp[2].back()));

    return 0;
}