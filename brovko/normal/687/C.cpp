#include <bits/stdc++.h>
//#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int n, k, a[505], dp[505][505];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    dp[0][0] = 1;

    for(int i = 0; i < n; i++)
        for(int x = k; x >= 0; x--)
            for(int y = k; y >= 0; y--)
            {
                if(x >= a[i])
                    dp[x][y] = max(dp[x][y], dp[x - a[i]][y]);

                if(y >= a[i])
                    dp[x][y] = max(dp[x][y], dp[x][y - a[i]]);
            }

    vector <int> v;

    for(int i = 0; i <= k; i++)
        if(dp[i][k - i])
            v.push_back(i);

    cout << v.size() << "\n";

    for(auto to:v)
        cout << to << ' ';
}