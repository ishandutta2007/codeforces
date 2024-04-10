#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, l, k, d[505], a[505], dp[505][505];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> k;

    for(int i = 0; i < n; i++)
        cin >> d[i];

    a[n] = 1;
    d[n] = l;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = n - 1; i >= 0; i--)
        for(int j = 0; j <= k; j++)
        {
            dp[i][j] = 1e9;

            if(j > 0)
                dp[i][j] = dp[i][j - 1];

            for(int z = i + 1; z <= min(n, i + j + 1); z++)
                dp[i][j] = min(dp[i][j], dp[z][j - z + i + 1] + a[i] * (d[z] - d[i]));
        }

    cout << dp[0][k];
}