#include <bits/stdc++.h>
//#define int long long
#define ld long double

using namespace std;
const int MOD = 1e9 + 7;

int n, k, q, a[5005], dp[5005][5005], b[5005];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int sub(int x, int y)
{
    return add(x, MOD - y);
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> q;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        dp[0][i] = 1;

    for(int i = 1; i <= k; i++)
        for(int j = 0; j < n; j++)
    {
        if(j > 0)
            dp[i][j] = dp[i - 1][j - 1];

        if(j < n - 1)
            dp[i][j] = add(dp[i][j], dp[i - 1][j + 1]);
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= k; j++)
            b[i] = add(b[i], mul(dp[j][i], dp[k - j][i]));

    int ans = 0;

    for(int i = 0; i < n; i++)
        ans = add(ans, mul(b[i], a[i]));

    while(q--)
    {
        int x, y;
        cin >> x >> y;
        x--;

        ans = add(ans, sub(mul(b[x], y), mul(b[x], a[x])));
        a[x] = y;

        cout << ans << "\n";
    }
}