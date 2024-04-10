#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll mic(ll x)
{
    if (x <= 9)
    {
        return x;
    }
    else
    {
        return min(x % 10, mic(x / 10));
    }
}

ll mare(ll x)
{
    if (x <= 9)
    {
        return x;
    }
    else
    {
        return max(x % 10, mare(x / 10));
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        for (ll i = 1; i < k && mic(n); i++)
        {
            n += mic(n) * mare(n);
        }
        cout << n << "\n";
    }

}