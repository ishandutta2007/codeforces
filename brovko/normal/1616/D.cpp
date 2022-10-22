#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[50005], ps[50005], x, l[50005], dp[50005][2], st[50005][20];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        cin >> x;

        for(int i = 0; i < n; i++)
            a[i] -= x;

        for(int i = 0; i <= n; i++)
            ps[i + 1] = ps[i] + a[i];

        for(int i = 0; i < n; i++)
            st[i][0] = ps[i];

        for(int j = 1; j < 20; j++)
            for(int i = (1 << j) - 1; i <= n; i++)
                st[i][j] = max(st[i][j - 1], st[i - (1 << j - 1)][j - 1]);

        l[0] = -1;
        l[1] = -1;

        for(int i = 2; i <= n; i++)
        {
            int x = i - 2;

            for(int j = 19; j >= 0; j--)
                if(x >= (1 << j) - 1 && st[x][j] <= ps[i])
                {
                    x -= (1 << j);

//                    if(i == 2)
//                        cout << "!" << j << "\n";
                }

            l[i] = x;
        }

        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
            dp[i][1] = 0;
        }

        for(int i = 1; i <= n; i++)
            l[i] = max(l[i], l[i - 1]);

//        for(int i = 0; i <= n; i++)
//            cout << l[i] << ' ';
//
//        cout << "\n";

        for(int i = 0; i < n; i++)
        {
            dp[i + 1][1] = i - l[i + 1] + dp[l[i + 1] + 1][0];
            dp[i + 1][0] = dp[i][1];
        }

        cout << dp[n][1] << "\n";
    }
}

/*
1
10
-1 1 -1 1 -1 1 -1 1 -1 1
0

*/