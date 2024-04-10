#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 1e9 + 7;

int mul(int x, int y)
{
    return x * y % MOD;
}

int dp[65];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    dp[1] = 1;

    for(int i = 2; i <= k; i++)
        dp[i] = mul(dp[i - 1], mul(dp[i - 1], 16));

    cout << mul(dp[k], 6);
}