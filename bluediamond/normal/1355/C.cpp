#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll sum(ll x)
{
    return x * (x + 1) / 2;
}

ll sum(ll l, ll r)
{
    return sum(r) - sum(l - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;
    ll sol = 0;
    cin >> a >> b >> c >> d;
    for (int i = a; i <= b; i++)
    {
        int l = i + b - 1;
        int r = i + c - 1;
        if (d < l)
        {
            sol += (ll) max(d - c + 1, 0) * (r - l + 1);
            continue;
        }
        if (l <= d && d <= r)
        {
            int l2 = max(c - 1, l);
            int r2 = d;
            if (l2 <= r2)
            {
                sol += sum(l2, r2);
                sol += (ll) (1 - c) * (r2 - l2 + 1);
            }
            sol += (ll) (r - d) * max(d - c + 1, 0);
            continue;
        }
        int l2 = max(c - 1, l);
        int r2 = r;
        if (l2 <= r2)
        {
            sol += sum(l2, r2);
            sol += (ll) (1 - c) * (r2 - l2 + 1);
        }
    }
    cout << sol << "\n";
}