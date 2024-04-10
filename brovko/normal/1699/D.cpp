#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define f first
#define s second

using li = long long;

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

        vector <int> a(n);

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]--;
        }

        int Max[n + 2][n + 2] = {};

        for(int i = 0; i < n; i++)
        {
            int mx = -1e9;
            vector <int> k(n);

            for(int j = i; j < n; j++)
            {
                k[a[j]]++;
                mx = max(mx, k[a[j]]);

                Max[i + 1][j + 1] = mx;
            }
        }

        vector <int> v[n];

        for(int i = 0; i < n; i++)
            v[i].pb(-1);

        for(int i = 0; i < n; i++)
            v[a[i]].pb(i);

        int ans = 0;

        for(int x = 0; x < n; x++)
        {
//                                    x = 1;

            v[x].pb(n);
            int m = v[x].size();

//            cout << m << endl;
//
//            for(auto to:v[x])
//                cout << to << ' ';
//
//            cout << endl;

            vector <int> dp(m, 1e9);
            dp[0] = 0;

            for(int i = 1; i < m; i++)
                for(int j = 0; j < i; j++)
                {
                    int add = max((v[x][i] - v[x][j] - 1) % 2 + (i - j - 1), 2 * Max[v[x][j] + 2][v[x][i]] - (v[x][i] - v[x][j] - 1) + (i - j - 1));

//                    cout << i << ' ' << j << ' ' << add << endl;

                    dp[i] = min(dp[i], dp[j] + add);
                }

//            for(int i = 0; i < m; i++)
//                cout << dp[i] << ' ';
//
//            cout << endl;

//            cout << x << ' ' << (int)v[x].size() - 2 - dp[m - 1] << endl;

            ans = max(ans, (int)v[x].size() - 2 - dp[m - 1]);

//                                                        return 0;
        }

        cout << ans << "\n";
    }
}

/*
1
7
1 1 1 1 2 2 2

1
6
1 2 3 2 1 2

*/