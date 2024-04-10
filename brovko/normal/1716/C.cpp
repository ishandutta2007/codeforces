#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int a[2][n];

        for(int i = 0; i < 2; i++)
            for(int j = 0; j < n; j++)
                cin >> a[i][j];

        a[0][0] = -1;

        vector <int> md(n), mu(n);

        int Md = -1, Mu = -1;

        for(int i = n - 1; i >= 0; i--)
        {
            Md = max({Md + 1, a[1][i] + 1, a[0][i] + 2 * n - 2 * i});
            Mu = max({Mu + 1, a[0][i] + 1, a[1][i] + 2 * n - 2 * i});

            md[i] = Md;
            mu[i] = Mu;
        }

        vector <int> dp(n);

        dp[n - 1] = (n % 2 ? md[n - 1] : mu[n - 1]);

        for(int i = n - 2; i >= 0; i--)
        {
            dp[i] = min((i % 2 == 0 ? md[i] : mu[i]), max({a[i % 2][i] + 2 * n - 2 * i, a[i % 2 ^ 1][i] + 2 * n - 2 * i - 1, dp[i + 1]}));
        }

//        for(int i = 0; i < n; i++)
//            cout << md[i] << ' ';
//
//        cout << "\n";
//
//        for(int i = 0; i < n; i++)
//            cout << mu[i] << ' ';
//
//        cout << "\n";
//
//        for(int i = 0; i < n; i++)
//            cout << dp[i] << ' ';
//
//        cout << "\n";

        cout << dp[0] << "\n";
    }
}