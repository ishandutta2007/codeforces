#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, dp[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    dp[0] = 1;

    for(int i = 1; i < 200005; i++)
    {
        if(i >= 11)
            dp[i] |= dp[i - 11];

        if(i >= 111)
            dp[i] |= dp[i - 111];

        if(i >= 1111)
            dp[i] |= dp[i - 1111];

        if(i >= 11111)
            dp[i] |= dp[i - 11111];

        if(i >= 111111)
            dp[i] |= dp[i - 111111];
    }

    while(t--)
    {
        cin >> n;

        if(n >= 200000 || dp[n] == 1)
            cout << "YES\n";
        else cout << "NO\n";
    }
}