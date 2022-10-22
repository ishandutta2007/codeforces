#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int N = 200005;

int n, k, a[105], b[105], c[105], dp[105][400010];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    for(int i = 0; i < n; i++)
        c[i] = a[i] - k * b[i];

    for(int i = 0; i <= n; i++)
        for(int j = 0; j < 400005; j++)
            dp[i][j] = -1e9;

    dp[0][N] = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < 400005; j++)
            if(dp[i][j] >= 0)
            {
                dp[i + 1][j + c[i]] = max(dp[i + 1][j + c[i]], dp[i][j] + a[i]);
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            }

    cout << (dp[n][N] == 0 ? -1 : dp[n][N]);
}