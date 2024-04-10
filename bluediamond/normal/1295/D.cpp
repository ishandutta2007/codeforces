#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
        if (b == 0)
                return a;
        else
                return gcd(b, a % b);
}

ll phi(ll n)
{
        ll r = n;
        for (ll d = 2; d * d <= n; d++)
        {
                bool is = 0;
                while (n % d == 0)
                {
                        n /= d;
                        is = 1;
                }
                if (is)
                {
                        r /= d;
                        r *= (d - 1);
                }
        }
        if (n > 1)
        {
                r /= n;
                r *= (n - 1);
        }
        return r;
}

ll solve(ll a, ll m)
{
        return phi(m / gcd(a, m));
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int t;
        cin >> t;
        while (t--)
        {
                ll a, m;
                cin >> a >> m;
                cout << solve(a, m) << "\n";
        }
}