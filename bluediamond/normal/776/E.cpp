#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = (ll) 1e9 + 7;

ll phi(ll n)
{
    ll r = n;
    for (ll d = 2; d * d <= n; d++)
    {
        bool e = 0;
        while (n % d == 0)
        {
            n /= d;
            e = 1;
        }
        if (e)
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

int main()
{
    ll n, k;
    cin >> n >> k;
    k = (k + 1) / 2;

    while (k-- && n != phi(n))
    {
        n = phi(n);
    }
    cout << n % MOD << "\n";

}