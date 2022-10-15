#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vector<ll> d;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            d.push_back(i);
            if (i * i != n)
            {
                d.push_back(n / i);
            }
        }
    }
    if ((int) d.size() < k)
    {
        cout << "-1\n";
    }
    else
    {
        sort(d.begin(), d.end());
        cout << d[k - 1] << "\n";
    }
}