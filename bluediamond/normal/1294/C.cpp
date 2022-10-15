#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve(ll n)
{
    vector<ll> d;
    for (ll x = 1; x * x <= n; x++)
    {
        if (n % x == 0)
        {
            if (x != 1)
            {
                d.push_back(x);
            }
            if (x * x == n)
            {
                break;
            }
            d.push_back(n / x);
        }
    }
    sort(d.begin(), d.end());
    for (auto &a : d)
    {
        for (auto &b : d)
        {
            if (b >= a)
            {
                break;
            }
            if (n % (a * b) == 0)
            {
                ll c = n / (a * b);
                if (c != 1 && c != a && c != b)
                {
                    cout << "YES\n";
                    cout << a << " " << b << " " << c << "\n";
                    return;
                }
            }

        }
    }
    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        solve(n);
    }

}