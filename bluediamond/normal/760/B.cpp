#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gauss(ll a)
{
    return a * (a + 1) / 2;
}

ll gauss(ll a, ll b)
{
    return gauss(b) - gauss(a - 1);
}

bool ok(ll n, ll m, ll k, ll a)
{
    ll l1 = k, x1 = a;
    ll l2 = n - k, x2 = a - 1;
    return (gauss(max(1LL, x1 - l1 + 1), x1) + gauss(max(1LL, x2 - l2 + 1), x2) <= m - n);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 0, r = (ll) 1e9, ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (ok(n, m, k, mid))
        {
            ans = mid + 1;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << "\n";
}