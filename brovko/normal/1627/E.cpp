#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, m, k, x[100005];
vector <vector <int> > v[100005];
vector <int> dp[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> k;

        for(int i = 0; i < n; i++)
            cin >> x[i];

        for(int i = 0; i < n; i++)
            v[i].clear();

        for(int i = 0; i < k; i++)
        {
            int a, b, c, d, h;
            cin >> a >> b >> c >> d >> h;

            a--;
            b--;
            c--;
            d--;

            v[c].pb({d, a, b, h});
        }

        for(int i = 0; i < n; i++)
            sort(v[i].begin(), v[i].end());

        for(int i = 0; i < n; i++)
        {
//            cout << "+" << i << endl;

            dp[i].resize(v[i].size());

            for(int j = 0; j < dp[i].size(); j++)
                dp[i][j] = 1e18;

//            cout << "=" << i << ' ' << dp[i].size() << endl;



            for(int j = 0; j < dp[i].size(); j++)
            {
//                cout << "(" << j << endl;

                int a = v[i][j][1], b = v[i][j][2];

                if(a == 0)
                {
//                    cout << ")" << j << endl;

                    dp[i][j] = b * x[0] - v[i][j][3];
                    continue;
                }

                int L = 0, R = (int)v[a].size() - 1;

                while(R - L > 1)
                {
                    int M = (L + R) / 2;

                    if(v[a][M][0] >= b)
                        R = M;
                    else L = M;
                }

                if(L >= 0 && L < v[a].size())
                    dp[i][j] = min(dp[i][j], dp[a][L] + x[a] * abs(v[a][L][0] - b) - v[i][j][3]);

                L = R;

                if(L >= 0 && L < v[a].size())
                    dp[i][j] = min(dp[i][j], dp[a][L] + x[a] * abs(v[a][L][0] - b) - v[i][j][3]);

//                cout << ")" << j << endl;
            }

            vector <int> ldp = dp[i];
            vector <int> rdp = dp[i];

//            cout << "=" << i << endl;

            for(int j = 1; j < ldp.size(); j++)
                ldp[j] = min(ldp[j], ldp[j - 1] + x[i] * abs(v[i][j][0] - v[i][j - 1][0]));

            for(int j = (int)rdp.size() - 2; j >= 0; j--)
                rdp[j] = min(rdp[j], rdp[j + 1] + x[i] * abs(v[i][j][0] - v[i][j + 1][0]));

//            cout << "=" << i << endl;

//            cout << "! ";
//
//            for(auto x:dp[i])
//                cout << x << ' ';
//
//            cout << endl;

            for(int j = 0; j < dp[i].size(); j++)
                dp[i][j] = min(ldp[j], rdp[j]);

//            cout << "-" << i << endl;
        }

        if(dp[n - 1].size() == 0)
            cout << "NO ESCAPE\n";
        else
        {
            int ans = dp[n - 1].back() + x[n - 1] * (m - 1 - v[n - 1].back()[0]);

            if(ans > 5e17)
                cout << "NO ESCAPE\n";
            else cout << ans << "\n";
        }

//        cout << endl;
//
//        for(int i = 0; i < n; i++)
//        {
//            for(auto x:dp[i])
//                cout << x << ' ';
//
//            cout << endl;
//        }
//
//        cout << endl;
    }
}