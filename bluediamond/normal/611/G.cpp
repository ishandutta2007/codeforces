#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = (int) 1e9 + 7;
const int N = (int) 5e5 + 7;

int n;
ll x[N];
ll y[N];
ll sum[N];
ll super[N];
ll tot;
ll sx[N];
ll sy[N];
ll blat[N];

ll f(int i, int j)
{
    return (x[i] + x[j]) * (y[i] - y[j]);
}

ll rep(ll x)
{
    x %= MOD;
    if (x < 0)
    {
        x += MOD;
    }
    return x;
}

ll call(int i, int l, int r)
{
    ll sol = 0;
    sol = rep(sol + x[i] * y[i] % MOD * (r - l + 1));
    sol = rep(sol - x[i] * (sy[r] - sy[l - 1]));
    sol = rep(sol + y[i] * (sx[r] - sx[l - 1]));
    sol = rep(sol - (blat[r] - blat[l - 1]));
    return sol;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        sx[i] = rep(sx[i - 1] + x[i]);
        sy[i] = rep(sy[i - 1] + y[i]);
        blat[i] = rep(blat[i - 1] + x[i] * y[i]);
    }
    x[n + 1] = x[1];
    y[n + 1] = y[1];
    for (int i = 1; i <= n; i++)
    {
        tot += f(i, i + 1);
        sum[i] = tot;
        super[i] = rep(super[i - 1] + sum[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = i + 2, r = n - (i == 1);
        int last = l - 1, lo = l, hi = r;
        while (lo <= hi)
        {
            int j = (lo + hi) / 2;
            ll p = sum[j - 1] - sum[i - 1] + f(j, i);
            if (p <= tot - p)
            {
                last = j;
                lo = j + 1;
            }
            else
            {
                hi = j - 1;
            }
        }
        if (l <= last)
        {
            ans = rep(ans - 2 * (super[last - 1] - super[l - 2]));
            ans = rep(ans + 2 * sum[i - 1] % MOD * (last - l + 1));
            ans = rep(ans + tot % MOD * (last - l + 1));
            ans = rep(ans + 2 * call(i, l, last));
        }

        if (last + 1 <= r)
        {
            ans = rep(ans + 2 * (super[r - 1] - super[last - 1]));
            ans = rep(ans - 2 * sum[i - 1] % MOD * (r - last));
            ans = rep(ans - tot % MOD * (r - last));
            ans = rep(ans - 2 * call(i, last + 1, r));
        }
    }
    cout << ans << "\n";
}