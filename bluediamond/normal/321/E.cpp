#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = (ll) 1e18;
const ll N = 4000 + 7;
const ll K = 800 + 7;
ll n;
ll k;
ll s[N][N];
ll dp[K][N];

ll get(ll i, ll j)
{
    return s[j][j] - s[i - 1][j] - s[j][i - 1] + s[i - 1][i - 1];
}

ll opt(ll c, ll i, ll lo, ll hi)
{
    dp[c][i] = INF;
    ll ans = -1;
    for (ll j = lo; j <= hi && j + 1 <= i; j++)
    {
        ll cur = dp[c - 1][j] + get(j + 1, i);
        if (cur < dp[c][i])
        {
            dp[c][i] = cur;
            ans = j;
        }
    }
    return ans;
}

void solve(ll c, ll l, ll r, ll lo, ll hi)
{
    if (l > r)
    {
        return;
    }
    ll m = (l + r) / 2;
    ll x = opt(c, m, lo, hi);
    solve(c, l, m - 1, lo, x);
    solve(c, m + 1, r, x, hi);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
    {
        ll cur = 0;
        for (ll j = 1; j <= n; j++)
        {
            char x;
            cin >> x;
            cur += x - '0';
            s[i][j] = s[i - 1][j] + cur;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        dp[1][i] = get(1, i);
    }
    for (ll c = 2; c <= k; c++)
    {
        solve(c, 1, n, 1, n);
    }
    cout << dp[k][n] / 2 << "\n";
}