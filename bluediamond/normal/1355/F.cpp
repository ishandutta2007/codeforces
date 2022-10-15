#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = (ll) 1e18 + 123;
vector<int> primes;

ll add(ll a, ll b)
{
    return min(a + b, INF);
}

ll mul(ll a, ll b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }
    ll p = a * b;
    if (p % a == 0 && p / a == b)
    {
        return min(p, INF);
    }
    else
    {
        return INF;
    }
}

ll biggest(ll x)
{
    ll sol = 1;
    while (mul(x, sol) <= (ll) 1e9)
    {
        sol = mul(x, sol);
    }
    return sol;
}

pair<int, int> gap(int x)
{
    int l = x - 7;
    int r = x + 7;
    /// 0.5 <= sol / x <= 2
    /// x / 2 <= sol <= 2 * x
    l = min(l, (x + 1) / 2);
    r = max(r, 2 * x);
    return {l, r};
}

void print(pair<int, int> it)
{
    cout << "(" << it.first << ", " << it.second << ")\n";
}

bool is_prime(int x)
{
    if (x <= 1)
    {
        return 0;
    }
    else
    {
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

ll num(ll x, ll y)
{
    if (x % y)
    {
        return 1;
    }
    else
    {
        return y * num(x / y, y);
    }
}

int cnt(ll x, ll y)
{
    if (x % y)
    {
        return 0;
    }
    else
    {
        return 1 + cnt(x / y, y);
    }
}

int money;

ll ask(ll x)
{
    money--;
    cout << "? " << x << endl;
    ll ret;
    cin >> ret;
    return ret;
}

int cnt(int x)
{
    int sol = 1;
    for (int d = 2; d * d <= x; d++)
    {
        int e = 0;
        while (x % d == 0)
        {
            e++;
            x /= d;
        }
        sol *= (e + 1);
    }
    if (x > 1)
    {
        sol *= 2;
    }
    return sol;
}

int main()
{
    for (int i = 1; i <= 10000; i++)
    {
        if (is_prime(i))
        {
            primes.push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        vector<int> zoro;
        money = 22;
        ll sol = 1;
        int i = 0;
        while (money > 0)
        {
            if ((int) zoro.size() >= 2)
            {
                int x = zoro.back();
                zoro.pop_back();
                int y = zoro.back();
                zoro.pop_back();
                ll a = biggest(x) * biggest(y);
                ll b = ask(a);
                sol *= num(b, x);
                sol *= num(b, y);
                continue;
            }
            if (money == 1 && (int) zoro.size() == 1)
            {
                int x = zoro.back();
                zoro.pop_back();
                ll a = biggest(x);
                ll b = ask(a);
                sol *= num(b, x);
                continue;
            }
            int j = i;
            ll cur = primes[j];
            while (mul(cur, primes[j + 1]) <= (ll) 1e18)
            {
                j++;
                cur = mul(cur, primes[j]);
            }
            ll b = ask(cur);
            for (int k = i; k <= j; k++)
            {
                if (b % primes[k] == 0)
                {
                    zoro.push_back(primes[k]);
                }
            }
            i = j + 1;
        }
        for (auto &it : zoro)
        {
            sol *= it;
        }
        int x = cnt(sol);
        int pos = x;
        while (gap(pos + 1).first <= x)
        {
            pos++;
        }
        cout << "! " << pos << endl;
    }
}