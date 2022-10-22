#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        string a, b;
        cin >> a >> b;

        x = min(x, 2 * y);

        vector <int> v;

        for(int i = 0; i < n; i++)
            if(a[i] != b[i])
                v.pb(i);

        if(v.size() % 2)
        {
            cout << "-1\n";
            continue;
        }

        if(x >= y)
        {
            if(v.size() == 2 && v[0] + 1 == v[1])
                cout << x << "\n";
            else cout << y * 1ll * v.size() / 2 << "\n";
        }
        else
        {
            li dp[n + 1];

            dp[0] = dp[1] = 0;

            for(int i = 1; i < v.size(); i++)
            {
                if(i % 2 == 0)
                {
                    dp[i + 1] = min(dp[i], dp[i - 1] + min(y * 1ll, x * 1ll * (v[i] - v[i - 1])));
                    continue;
                }

                dp[i + 1] = dp[i - 1] + min(1ll * y, x * 1ll * (v[i] - v[i - 1]));

                if(i > 1)
                    dp[i + 1] = min(dp[i + 1], dp[i] + y);
            }

//            for(int i = 0; i <= v.size(); i++)
//                cout << dp[i] << ' ';
//
//            cout << "\n";

            cout << dp[v.size()] << "\n";
        }
    }
}