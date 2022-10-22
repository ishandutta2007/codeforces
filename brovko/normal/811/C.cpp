#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[5005], used[5005], dp[5005], u[5005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            used[a[i]]++;
        }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 5005; j++)
            u[j] = 0;

        dp[i] = dp[i - 1];

        int x = 0;
        int k = 0;

        for(int j = i - 1; j >= 0; j--)
        {
            if(u[a[j]] == 0)
            {
                u[a[j]] = used[a[j]] - 1;
                if(u[a[j]])
                    k++;
                x ^= a[j];
            }
            else
            {
                u[a[j]]--;
                if(u[a[j]] == 0)
                    k--;
            }

            if(k == 0)
                dp[i] = max(dp[i], dp[j] + x);
        }
    }

    cout << dp[n];
}