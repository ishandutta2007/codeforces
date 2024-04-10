#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;
const int MOD = 998244353;

int add(int x, int y)
{
    x += y;

    return (x >= MOD ? x - MOD : x);
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

    int n;
    cin >> n;

    string s;
    cin >> s;

    string Min[1 << n];
    int dp[1 << n];

    for(int i = (1 << n) - 1; i >= 0; i--)
    {
        if(2 * i + 1 >= (1 << n) - 1)
        {
            dp[i] = 1;
            Min[i] = s.substr(i, 1);
        }
        else
        {
            dp[i] = mul(dp[2 * i + 1], dp[2 * i + 2]);

            if(Min[2 * i + 1] != Min[2 * i + 2])
                dp[i] = mul(dp[i], 2);

            Min[i] = s.substr(i, 1) + min(Min[2 * i + 1], Min[2 * i + 2]) + max(Min[2 * i + 1], Min[2 * i + 2]);
        }
    }

    cout << dp[0];
}