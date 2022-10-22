#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int n, m, dp[5005][5005];
string a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> a >> b;

    int ans = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            dp[i + 1][j + 1] = max({0ll, dp[i + 1][j] - 1, dp[i][j + 1] - 1});

            if(a[i] == b[j])
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);

            ans = max(ans, dp[i + 1][j + 1]);
        }

    cout << ans;
}