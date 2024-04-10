#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (ll) 1e9 + 7;

ll add(ll a, ll b)
{
        a += b;
        if (a >= MOD)
                return a - MOD;
        if (a < 0)
                return a + MOD;
        return a;
}

ll mul(ll a, ll b)
{
        return a * (ll) b % MOD;
}

ll expow(ll a, ll b)
{
        ll r = 1;
        while (b)
        {
                if (b & 1)
                        r = mul(r, a);
                a = mul(a, a);
                b >>= 1;
        }
        return r;
}

const ll N = (ll) 2e5 + 7;
ll fact[N], inv[N];
ll n;
ll a[N], t;

ll comb(ll n, ll k) /// O(1)
{
        ll x = fact[n];
        ll y = inv[k];
        ll z = inv[n - k];
        return mul(x, mul(y, z));
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> t;
        for (ll i = 1; i <= n; i++)
                cin >> a[i];
        for (ll i = 1; i <= n; i++)
                a[i] += a[i - 1];
        fact[0] = 1;
        for (ll i = 1; i < N; i++)
                fact[i] = mul(fact[i - 1], i);
        inv[N - 1] = expow(fact[N - 1], MOD - 2);
        for (ll i = N - 2; i >= 0; i--)
                inv[i] = mul(inv[i + 1], i + 1);
        ll sol = 0;
        a[n + 1] = (ll) 1e18;
        for (ll i = 1; i <= n; i++)
        {
                /// val <= i
                /// val + a[i + 1] >= t + 1
                /// i >= val >= t + 1 - a[i + 1]
                /// val + a[i] <= t
                /// val <= t - a[i]
                /// val <= t - a[i]
                /// First
                ll st = t + 1 - a[i + 1];
                ll dr = i;
                if (dr > t - a[i])
                        dr = t - a[i];
                ll cur = 0;
                if (st < 0)
                        st = 0;
                if (st < 0) st = 0;
                if (dr > (ll) i) dr = (ll) i;
                for (ll j = st; j <= dr; j++)
                        cur = add(cur, comb(i, j));
                if (i < n)
                {
                        /// Second
                        st = t + 1 - (a[i + 1] + 1);
                        dr = i;
                        if (dr > t - a[i])
                                dr = t - a[i];
                        if (st < 0)
                                st = 0;
                        if (st < 0) st = 0;
                        if (dr > (ll) i) dr = (ll) i;
                        for (ll j = st; j <= dr; j++)
                                cur = add(cur, comb(i, j));
                }
                if (i < n)
                        cur = mul(cur, expow(2, n - i - 1));
               /// cout << i << " : " << cur << "\n";
                sol = add(sol, mul(cur, i));
        }
        ll good = sol, tot = expow(2, n);
        cout << mul(good, expow(tot, MOD - 2)) << "\n";
        return 0;
}