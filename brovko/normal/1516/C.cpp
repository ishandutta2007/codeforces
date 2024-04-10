#include <bits/stdc++.h>
//#define int long long
#define x first
#define y second

using namespace std;

int n, a[105], dp[105][400005];

int gcd(int x, int y)
{
    if(x == 0)
        return y;

    return gcd(y % x, x);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int g = 0;

    for(int i = 0; i < n; i++)
        g = gcd(g, a[i]);

    for(int i = 0; i < n; i++)
        a[i] /= g;

    int N = 200002;

    dp[0][N + a[0]] = 1;
    dp[0][N - a[0]] = 1;

    for(int i = 1; i < n; i++)
        for(int j = 0; j <= 2 * N; j++)
        {
            if(j - a[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]]);

            if(j + a[i] <= 2 * N)
                dp[i][j] = max(dp[i][j], dp[i - 1][j + a[i]]);
        }

    if(dp[n - 1][N] == 0)
        cout << 0;
    else
    {
        cout << 1 << endl;

        for(int i = 0; i < n; i++)
            if(a[i] % 2)
            {
                cout << i + 1;
                return 0;
            }
    }
}