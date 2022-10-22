#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, dp[2005][2005], ans, dpu[2005][2005];
bool up[2005][2005], down[2005][2005], lf[2005][2005], rg[2005][2005];
char a[2005][2005], b[2005][2005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    if(n == 2)
    {
        for(int j = 1; j < m - 1; j++)
            if(a[0][j] == '.' && a[1][j] == '.')
                ans++;

        cout << ans;
        return 0;
    }

    if(m == 2)
    {
        for(int i = 1; i < n - 1; i++)
            if(a[i][0] == '.' && a[i][1] == '.')
                ans++;

        cout << ans;
        return 0;
    }

    for(int z = 0; z < 4; z++)
    {
//        for(int i = 0; i < n; i++)
//        {
//            for(int j = 0; j < m; j++)
//                cout << a[i][j];
//
//            cout << endl;
//        }
//
//        cout << endl;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(a[i][j] == '.' && (i == 0 || up[i - 1][j]))
                    up[i][j] = 1;
                else up[i][j] = 0;
            }

        for(int i = n - 1; i >= 0; i--)
            for(int j = 0; j < m; j++)
            {
                if(a[i][j] == '.' && (i == n - 1 || down[i + 1][j]))
                    down[i][j] = 1;
                else down[i][j] = 0;
            }

        if(z == 0)
        {
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    lf[i][j] = (a[i][j] == '.' && (j == 0 || lf[i][j - 1]));

            for(int i = 0; i < n; i++)
                for(int j = m - 1; j >= 0; j--)
                    rg[i][j] = (a[i][j] == '.' && (j == m - 1 || rg[i][j + 1]));

            for(int i = 1; i < n - 1; i++)
                for(int j = 1; j < m - 1; j++)
                    ans += (up[i][j] && rg[i][j]) + (rg[i][j] && down[i][j]) + (down[i][j] && lf[i][j]) + (lf[i][j] && up[i][j]);
        }

        for(int i = 1; i < n - 1; i++)
            for(int j = m - 2; j > 0; j--)
                if(a[i][j] == '.')
                {
                    if(j == m - 2)
                        dp[i][j] = 0;
                    else dp[i][j] = dp[i][j + 1] + (int)down[i][j + 1];

                    if(j < m - 3 && a[i][j] == '.' && a[i][j + 1] == '.')
                        dpu[i][j] = dpu[i][j + 1] + (int)up[i][j + 2];
                }

        for(int i = 1; i < n - 1; i++)
            for(int j = 1; j < m - 1; j++)
                if(up[i][j])
                    ans += dp[i][j] + dpu[i][j];

        if(z <= 1)
        {
            for(int j = 1; j < m - 1; j++)
                if(down[0][j])
                    ans++;
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                dp[i][j] = 0;
                dpu[i][j] = 0;
            }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                b[j][n - 1 - i] = a[i][j];

        swap(n, m);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                a[i][j] = b[i][j];

        if(z == 1 || z == 2)
        {
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m / 2; j++)
                    swap(a[i][j], a[i][m - 1 - j]);
        }

        if(z == 2)
        {
            for(int i = 0; i < n / 2; i++)
                for(int j = 0; j < m; j++)
                    swap(a[i][j], a[n - 1 - i][j]);
        }
    }

    cout << ans;
}