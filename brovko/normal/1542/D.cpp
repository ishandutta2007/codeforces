#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second

using namespace std;
const int MOD = 998244353;

int n, x[505], dp[505][505];
char c[505];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> c[i];

        if(c[i] == '+')
            cin >> x[i];
    }

//    int K = 0, p = 5;
//
//    for(int mask = 0; mask < (1 << n); mask++)
//        if(mask & (1 << p))
//        {
//            int y = 0, f = 1;
//
//            for(int i = 0; i < n; i++)
//                if(mask & (1 << i))
//                {
//                    if(c[i] == '-')
//                    {
//                        y--;
//
//                        if(y < 0)
//                        {
//                            if(i < p)
//                                y = 0;
//                            else f = 0;
//                        }
//                    }
//                    else
//                    {
//                        if(i < p && x[i] <= x[p] || i > p && x[i] < x[p])
//                            y++;
//                    }
//                }
//
//            K += f;
//        }
//
//    cout << K << endl << endl;

    int ans = 0;

    for(int i = 0; i < n; i++)
        if(c[i] == '+')
        {
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    dp[j][k] = 0;

            dp[0][0] = 1;

            if(i != 0 && c[0] == '+' && x[0] <= x[i])
            {
                dp[0][1] = 1;
            }
            else dp[0][0] = 2;

            if(i == 0)
                dp[0][0] = 1;

            for(int j = 1; j < n; j++)
            {

                for(int k = 0; k < n; k++)
                    dp[j][k] = dp[j - 1][k];

                if(c[j] == '-')
                {
                    for(int k = 1; k < n; k++)
                        dp[j][k - 1] = add(dp[j][k - 1], dp[j - 1][k]);

                    if(j < i)
                        dp[j][0] = add(dp[j][0], dp[j - 1][0]);
                }
                else if(j < i && x[j] <= x[i] || j > i && x[j] < x[i])
                {
                    for(int k = 1; k < n; k++)
                        dp[j][k] = add(dp[j][k], dp[j - 1][k - 1]);
                }
                else if(j != i)
                {
                    for(int k = 0; k < n; k++)
                        dp[j][k] = add(dp[j][k], dp[j - 1][k]);
                }
            }

//            if(i == 5)
//            {
//                for(int j = 0; j < n; j++)
//                {
//                    for(int k = 0; k < n; k++)
//                        cout << dp[j][k] << ' ';
//
//                    cout << endl;
//                }
//            }

            int z = 0;

            for(int k = 0; k < n; k++)
            {
                ans = add(ans, mul(dp[n - 1][k], x[i]));
                z = add(z, dp[n - 1][k]);
            }

            //cout << z << endl;
        }

    cout << ans;
}