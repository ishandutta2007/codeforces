#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, x, l[200005], r[200005], cost[200005], dp[200005];
vector <pair <int, int> > v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for(int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i] >> cost[i];
        v.push_back({l[i], -i});
        v.push_back({r[i], i});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < 200005; i++)
        dp[i] = 1e18;

    int Min = 1e18;

    for(auto to:v)
    {
        int i = to.second;

        if(i < 0)
        {
            i = -i;
            if(r[i] - l[i] + 1 < x)
            {
                Min = min(Min, cost[i] + dp[x - r[i] + l[i] - 1]);
            }
        }
        else
        {
            dp[r[i] - l[i] + 1] = min(dp[r[i] - l[i] + 1], cost[i]);
        }
    }

    if(Min == 1e18)
        cout << -1;
    else cout << Min;
}