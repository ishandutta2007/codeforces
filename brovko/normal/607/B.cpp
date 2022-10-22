#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, a[505], dp[505][505];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = 1;

    for(int i = n - 1; i >= 0; i--)
        for(int j = i + 1; j < n; j++)
        {
            dp[i][j] = dp[i + 1][j] + 1;

            for(int k = i + 1; k <= j; k++)
                if(a[i] == a[k])
                    dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + (k == j ? 0 : dp[k + 1][j]));
        }

//    cout << dp[1][2] << ' ' << dp[3][5] << endl;
    cout << dp[0][n - 1];
}