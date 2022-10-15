#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int pw(int a, int b, int mod)
{
    int r = 1;
    while (b)
    {
        if (b & 1)
        {
            r = (ll) r * a % mod;
        }
        a = (ll) a * a % mod;
        b /= 2;
    }
    return r;
}

int dv(int a, int b, int mod)
{
    return (ll) a * pw(b, mod - 2, mod) % mod;
}

int get_phi(int x)
{
    int r = x;
    for (int i = 2; i * i <= x; i++)
    {
        bool e = 0;
        while (x % i == 0)
        {
            x /= i;
            e = 1;
        }
        if (e)
        {
            r /= i;
            r *= (i - 1);
        }
    }
    if (x > 1)
    {
        r /= x;
        r *= (x - 1);
    }
    return r;
}

vector<int> get_divisors(int x)
{
    vector<int> sol;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            sol.push_back(i);
            if (i * i != x)
            {
                sol.push_back(x / i);
            }
        }
    }
    sort(sol.begin(), sol.end());
    return sol;
}

const int N = (int) 2e6;
int n; /// length
int m; /// number of operations
int a; /// starting number
int mod; /// output modulo mod
int rep;
int fact[N];
int ifact[N];
int sol[N];

int comb(int n, int k)
{
    if (k > n)
    {
        return 0;
    }
    return (ll) fact[n] * ifact[k] % rep * ifact[n - k] % rep;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> a >> mod;
    vector<int> d_phi = get_divisors(get_phi(mod));
    for (auto &d : d_phi)
    {
        if (pw(a, d, mod) == 1)
        {
            rep = d;
            break;
        }
    }
    int lim = max(n, m);
    fact[0] = 1;
    for (int i = 1; i <= lim; i++)
    {
        fact[i] = (ll) fact[i - 1] * i % rep;
    }
    ifact[lim] = dv(1, fact[lim], rep);
    for (int i = lim - 1; i >= 0; i--)
    {
        ifact[i] = (ll) ifact[i + 1] * (i + 1) % rep;
    }
    int coef = 0;
    for (int i = 1; i <= n; i++)
    {
        coef = (coef + comb(m, i - 1)) % rep;
        sol[i] = pw(a, coef, mod);
    }
    for (int i = n; i >= 1; i--)
    {
        cout << sol[i] << " ";
    }
    cout << "\n";
}