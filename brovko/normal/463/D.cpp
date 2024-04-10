#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, k, p[1005][5], dp[1005], pos[1005][5];

int f(int x)
{
    if(dp[x] > 0)
        return dp[x];

    dp[x] = 1;

    for(int i = 1; i <= n; i++)
        if(i != x)
        {
            int F = 1;

            for(int z = 0; z < k; z++)
                if(pos[i][z] >= pos[x][z])
                    F = 0;

            if(F)
                dp[x] = max(dp[x], 1 + f(i));
        }

    return dp[x];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < k; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> p[j][i];
            pos[p[j][i]][i] = j;
        }

    int ans = 0;

    for(int i = 1; i <= n; i++)
        ans = max(ans, f(i));

    cout << ans;
}