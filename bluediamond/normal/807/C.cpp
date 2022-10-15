#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll calc_phi(ll a)
{
    ll r = a;
    for (ll d = 2; d * d <= a; d++)
    {
        bool is = 0;
        while (a % d == 0)
        {
            a /= d;
            is = 1;
        }
        if (is)
        {
            r /= d;
            r *= (d - 1);
        }
    }
    if (a > 1)
    {
        r /= a;
        r *= (a - 1);
    }
    return r;
}

ll pw(ll a, ll b, ll mod)
{
    ll r = 1 % mod;
    while (b)
    {
        if (b & 1)
        {
            r = r * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return r;
}

ll dv(ll a, ll b, ll mod)
{
    ll pt = calc_phi(mod) - 1;
    ll inv_b = pw(b, pt, mod);
    return a * inv_b % mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

  ///  freopen ("hacker.in", "r", stdin);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        ll x, y, p, q;
        cin >> x >> y >> p >> q;

        if (p == 0)
        {
            if (x == 0)
            {
                cout << "0\n";
            }
            else
            {
                cout << "-1\n";
            }
            continue;
        }

        if (p == q)
        {
            if (x == y)
            {
                cout << "0\n";
            }
            else
            {
                cout << "-1\n";
            }
            continue;
        }

        ll val = p * y - q * x;
        ll p1, p2;

        if (val % (q - p) == 0)
        {
            p1 = val / (q - p);
        }
        else
        {
            p1 = val / (q - p) + 1;
        }

        val *= -1;

        if (val % p == 0)
        {
            p2 = val / p;
        }
        else
        {
            p2 = val / p + 1;
        }


        val *= -1;

        ll b = max(p1, p2);
        ll wanted = (q - val % q) % q;
        ll cur = b % q * p % q;
        ll jump = p % q;
        wanted = (q + wanted - cur) % q;

        ll xo = b + dv(wanted, jump, q);
        cout << xo << "\n";
    }

}