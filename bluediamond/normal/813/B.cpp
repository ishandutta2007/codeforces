#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = (ll) 1e18 + 1;

ll add(ll a, ll b)
{
    return min(INF, a + b);
}

ll mult(ll a, ll b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }
    if (a == INF || b == INF)
    {
        return INF;
    }
    ll p = a * b;
    if (p % a == 0 && p / a == b && p <= INF)
    {
        return p;
    }
    else
    {
        return INF;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll x, y, l, r, c1 = 1, c2 = 1;
    cin >> x >> y >> l >> r;
    vector<ll> a, b;
    while (c1 <= r)
    {
        a.push_back(c1);
        c1 = mult(c1, x);
    }
    while (c2 <= r)
    {
        b.push_back(c2);
        c2 = mult(c2, y);
    }
    set<ll> c;
    for (auto &c1 : a)
    {
        for (auto &c2 : b)
        {
            ll sum = add(c1, c2);
            if (l <= sum && sum <= r)
            {
                c.insert(sum);
            }
        }
    }
    c.insert(l - 1);
    c.insert(r + 1);
    ll age = 0, last = -111;
    for (auto &it : c)
    {
        if (last != -111)
        {
            age = max(age, it - last - 1);
        }
        last = it;
    }
    cout << age << "\n";


}