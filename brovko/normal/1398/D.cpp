#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int R, G, B, r[205], g[205], b[205], dp[205][205][205];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> G >> B;

    for(int i = 0; i < R; i++)
        cin >> r[i];

    for(int i = 0; i < G; i++)
        cin >> g[i];

    for(int i = 0; i < B; i++)
        cin >> b[i];

    sort(r, r + R);
    sort(g, g + G);
    sort(b, b + B);

    int ans = 0;

    for(int i = R; i >= 0; i--)
        for(int j = G; j >= 0; j--)
            for(int k = B; k >= 0; k--)
            {
                dp[i][j][k] = max({dp[i + 1][j + 1][k] + r[i] * g[j], dp[i + 1][j][k + 1] + r[i] * b[k], dp[i][j + 1][k + 1] + g[j] * b[k]});
                ans = max(ans, dp[i][j][k]);
            }

    cout << ans;
}