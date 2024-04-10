#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = (ll) 1e6 + 7;
const ll INF = (ll) 1e18;
ll n;
ll c1;
ll c2;
ll c3;
ll d;
ll a[N];
ll dp[N][2];

ll full(ll i)
{
    return 1LL * a[i] * c1 + c3;
}

ll part(ll i)
{
    return min(1LL * (a[i] + 1) * c1, 1LL * c2);
}

void upd(ll i, ll state, ll val)
{
    dp[i][state] = min(dp[i][state], val);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c1 >> c2 >> c3 >> d;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i][0] = dp[i][1] = INF;
    }
    dp[1][0] = full(1);
    dp[1][1] = part(1);
    for (ll i = 1; i < n; i++)
    {
        upd(i + 1, 0, dp[i][0] + d + full(i + 1));
        upd(i + 1, 1, dp[i][0] + d + part(i + 1));
        upd(i + 1, 0, dp[i][1] + 3 * d + c1 + full(i + 1));
        upd(i + 1, 0, dp[i][1] + 3 * d + 2 * c1 + part(i + 1));
        upd(i + 1, 1, dp[i][1] + 3 * d + c1 + part(i + 1));
        if (i == n - 1)
        {
            upd(n, 0, dp[i][1] + 2 * d + full(i + 1) + c1);
        }
    }
    cout << dp[n][0] << "\n";
}