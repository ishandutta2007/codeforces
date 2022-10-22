#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair

using namespace std;
const int N = 2e5 + 13;

int n[4], a[N][4], dp[N][4];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 4; i++)
        cin >> n[i];

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < n[i]; j++)
            cin >> a[j][i];

    vector <pair <int, int> > dp2[4];

    for(int i = 0; i < n[0]; i++)
    {
        dp[i][0] = a[i][0];
        dp2[0].push_back({dp[i][0], i});
    }
//
//    for(int i = 0; i < n[0]; i++)
//        cout << dp[i][0] << ' ';
//
//    cout << "\n";

    sort(dp2[0].begin(), dp2[0].end());

    for(int j = 1; j < 4; j++)
    {
        int x;
        cin >> x;

        map <pair <int, int>, int> m;

        for(int i = 0; i < x; i++)
        {
            int p, q;
            cin >> p >> q;

            p--;
            q--;

            m[{p, q}] = 1;
        }

        for(int i = 0; i < n[j]; i++)
        {
            int y = 0;

            while(y < dp2[j - 1].size() && m[mp(dp2[j - 1][y].y, i)] == 1)
                y++;

//            cout << "y " << y << "\n";

            if(y >= dp2[j - 1].size())
                dp[i][j] = 1e18;
            else dp[i][j] = dp2[j - 1][y].x + a[i][j];

            dp2[j].push_back({dp[i][j], i});
        }

        sort(dp2[j].begin(), dp2[j].end());

//        for(int i = 0; i < n[j]; i++)
//            cout << dp[i][j] << ' ';
//
//        cout << "\n";
    }

    int ans = 1e18;

    for(int i = 0; i < n[3]; i++)
        ans = min(ans, dp[i][3]);

    if(ans >= 1e15)
        cout << -1;
    else cout << ans;
}

/*

2 2 2 2
1 2
3 4
5 6
7 8
2
1 2
2 1
2
1 1
2 2
2
1 2
2 1

*/