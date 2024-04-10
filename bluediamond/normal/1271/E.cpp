#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
ll k;

ll get(ll x)
{
    if (x % 2 == 1)
    {
        ll ans = 0;
        for (ll m = 1; m * x <= n; m *= 2)
        {
            ll l = m * x;
            ll r = min(n, m * x + m - 1);
            ans += r - l + 1;
        }
        return ans;
    }
    else
    {
        ll ans = 0;
        for (ll m = 1; m * x <= n; m *= 2)
        {
            ll l = m * x;
            ll r = min(n, m * x + 2 * m - 1);
            ans += r - l + 1;
        }
        return ans;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    ll l = 0, r = (n - 1) / 2, ans = -1;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (get(2 * m + 1) >= k)
        {
            ans = max(ans, 2 * m + 1);
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    l = 1;
    r = n / 2;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (get(2 * m) >= k)
        {
            ans = max(ans, 2 * m);
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    cout << ans << "\n";
}