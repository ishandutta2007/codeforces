#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll modulo(ll a, ll mod)
{
        if (a < mod)
        {
                return a;
        }
        else
        {
                return (a % mod) + mod;
        }
}

ll mul(ll a, ll b, ll mod)
{
        return modulo(a * b, mod);
}

ll expow(ll a, ll b, ll mod)
{
        ll r = 1;
        while (b)
        {
                if (b & 1)
                {
                        r = mul(r, a, mod);
                }
                a = mul(a, a, mod);
                b >>= 1;
        }
        return r;
}

bool prie(ll x)
{
        if (x <= 1)
        {
                return 0;
        }
        else
        {
                for (ll d = 2; d * d <= x; d++)
                {
                        if (x % d == 0)
                        {
                                return 0;
                        }
                }
                return 1;
        }
}

vector <ll> primes;

ll phi(ll x)
{
        ll sol = x;
        for (auto &d : primes)
        {
                if (d * d > x) break;
                bool is = 0;
                while (x % d == 0)
                {
                        x /= d;
                        is = 1;
                }
                if (is)
                {
                        sol /= d;
                        sol *= (d - 1);
                }
        }
        if (x > 1)
        {
                ll d = x;
                sol /= d;
                sol *= (d - 1);
        }
        return sol;
}

const ll N = (ll) 1e5 + 7;
ll n, a[N];
vector <ll> mod;

ll solve(ll l, ll r, ll k)
{
        if (k >= (ll) mod.size() || l > r)
        {
                return 1;
        }
        return expow(a[l], solve(l + 1, r, k + 1), mod[k]);
}

signed main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

    //    freopen ("input", "r", stdin);
    //    freopen ("output", "w", stdout);

        cin >> n;
        ll ugar;
        cin >> ugar;
        mod.push_back(ugar);

        for (ll d = 2; d * d <= mod[0]; d++)
        {
                if (prie(d))
                {
                        primes.push_back(d);
                }
        }

        for (ll i = 1; i <= n; i++)
        {
                cin >> a[i];
        }

        while (mod.back() != 1)
        {
                mod.push_back(phi(mod.back()));
        }

        ll q;
        cin >> q;
        while (q--)
        {
                ll l, r;
                cin >> l >> r;
                cout << solve(l, r, 0) % ugar << "\n";
        }
}