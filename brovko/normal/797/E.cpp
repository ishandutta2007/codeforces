#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005], q, dp[100005][305];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = n; i > 0; i--)
        for(int j = 0; j < 300; j++)
    {
        if(i + a[i - 1] + j > n)
            dp[i][j] = 1;
        else dp[i][j] = 1 + dp[i + a[i - 1] + j][j];
    }

    cin >> q;
    while(q--)
    {
        int p, k;
        cin >> p >> k;

        if(k < 300)
            cout << dp[p][k] << "\n";
        else
        {
            int ans = 0;
            while(p <= n)
            {
                p += a[p - 1] + k;
                ans++;
            }

            cout << ans << "\n";
        }
    }
}