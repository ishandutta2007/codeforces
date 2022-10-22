#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int n, a[5005], b[5005], dp[5005][5005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    for(int i = n - 1; i >= 0; i--)
        for(int j = i + 1; j < n; j++)
        {
            dp[i][j] = dp[i + 1][j - 1] + a[i] * b[j] + a[j] * b[i] - a[i] * b[i] - a[j] * b[j];
        }

    int x = 0;

    for(int i = 0; i < n; i++)
        x += a[i] * b[i];

    int ans = x;

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            ans = max(ans, x + dp[i][j]);

    cout << ans;
}