#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int get(ll x)
{
    if (x < 10)
    {
        return x;
    }
    else
    {
        return x % 10 + get(x / 10);
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
        ll n, p = 10, c;
        int s;
        cin >> n >> s;
        c = n;
        while (get(n) > s)
        {
            if (n % p)
            {
                n += p - n % p;
            }
            p *= 10;
        }
        cout << n - c << "\n";
    }
}