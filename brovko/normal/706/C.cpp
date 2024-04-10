#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int n, a[100005], dp[100005][2];
string s[100005];

string inv(string x)
{
    for(int i = 0; i < x.size() / 2; i++)
        swap(x[i], x[x.size() - 1 - i]);

    return x;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> s[i];

    dp[0][0] = 0;
    dp[0][1] = a[0];

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = 1e18;
        dp[i][1] = 1e18;

        if(s[i] >= s[i - 1])
        {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        }

        if(s[i] >= inv(s[i - 1]))
        {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }

        if(inv(s[i]) >= s[i - 1])
        {
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i]);
        }

        if(inv(s[i]) >= inv(s[i - 1]))
        {
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + a[i]);
        }
    }

    int ans = min(dp[n - 1][0], dp[n - 1][1]);

    if(ans == 1e18)
        cout << -1;
    else cout << ans;
}