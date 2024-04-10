// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1000000007;
const long double eps = 1e-10;
int n;
ull a[1000005], b[1000005];
ll v[64];
ull power(ull A, int B)
{
    ull res = 1;
    while (B)
    {
        if (B & 1)
            res *= A;
        B /= 2;
        A *= A;
    }
    return res;
}
ull powermod(ull A, ull B)
{
    ull res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B /= 2;
        A = A * A % MOD;
    }
    return res;
}
ll mul(ll A, ll B, ll C)
{
    A = (A % C + C) % C;
    B = (B % C + C) % C;
    ll res = 0;
    while (B)
    {
        if (B & 1)
            res = (res + A) % C;
        B /= 2;
        A = (A + A) % C;
    }
    return res;
}
ull g(ull A, int B)
{
    ull res = std::pow(A, 1.0l / B);
    return power(res, B) == A ? res : (power(res + 1, B) == A ? res + 1 : -1);
}
ull f(ull A, ull B)
{
    if (A == 1)
        return B == 1 ? 0 : -1;
    int res = std::log10(B) / std::log10(A);
    return power(A, res) == B ? res : (power(A, res + 1) == B ? res + 1 : -1);
}
bool check(ull x)
{
    for (int i = 1; i <= n; ++i)
        if (x % a[i] || !~f(b[i], x / a[i]))
            return false;
    return true;
}
bool check(ull x, ull y, ull z)
{
    for (int i = 1; i <= n; ++i)
        if (std::fmod((std::log10(x) - std::log10(a[i]) + std::log10(y) * z) / std::log10(b[i]) + eps, 1) > eps * 2)
            return false;
    return true;
}
ll exgcd(ll x, ll y, ll &a, ll &b)
{
    if (y == 0)
    {
        a = 1;
        b = 0;
        return x;
    }
    ll res = exgcd(y, x % y, a, b);
    std::swap(a, b);
    b -= a * (x / y);
    return res;
}
signed main()
{
    //freopen("d.in", "r", stdin);
    //freopen("d.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i] >> b[i];
    for (int i = 1; i <= n; ++i)
        if (b[i] == 1)
        {
            if (check(a[i]))
                std::cout << a[i] % MOD << std::endl;
            else
                std::cout << -1 << std::endl;
            return 0;
        }
    ull gcd = a[1], w = -1;
    for (int i = 2; i <= n; ++i)
        gcd = std::__gcd(gcd, a[i]);
    for (int i = 1; i <= n; ++i)
        a[i] /= gcd;
    std::vector<ull> A(n + 1), B(n + 1);
    for (int j = 1; j <= 64; ++j)
        w = ~(~g(b[1], j) ?: ~w);
    bool flag = false;
    for (int i = n; i >= 1; --i)
    {
        A[i] = f(w, a[i]);
        B[i] = f(w, b[i]);
        if (!~A[i] || !~B[i])
            flag = true;
        if (!~B[i])
        {
            long double val = std::log10(a[1]) - std::log10(a[i]), le = std::log10(b[1]), ri = std::log10(b[i]);
            int L = 0, R = 0;
            while (std::max(L, R) < 10000 && std::abs(val) > eps)
                if (val < 0)
                    val += le, ++L;
                else
                    val -= ri, ++R;
            if (i != 1 && std::abs(val) < eps && check(a[1], b[1], L))
                std::cout << a[1] * gcd % MOD * powermod(b[1] % MOD, L) % MOD << std::endl;
            else
                std::cout << -1 << std::endl;
            return 0;
        }
    }
    if (flag)
        return std::cout << -1 << std::endl, 0;
    std::fill(v + 1, v + 1 + 60, -1);
    ull least = 0;
    for (int i = 1; i <= n; ++i)
    {
        least = std::max(A[i], least);
        if (!~v[B[i]])
            v[B[i]] = A[i] % B[i];
        else if (v[B[i]] % B[i] != A[i] % B[i])
            return std::cout << -1 << std::endl, 0;
    }
    ll lcma = 1, vala = 0, lcmb = 1, valb = 0, aa = 0, bb = 0;
    // for (int i = 1; i <= 60; ++i)
    //     if (~v[i])
    //         std::cout << i << ' ' << v[i] << std::endl;
    for (ll i = 1; i <= 40; ++i)
        if (~v[i])
        {
            ll t = exgcd(lcma, i, aa, bb);
            if ((v[i] - vala) % t)
                return std::cout << -1 << std::endl, 0;
            ll nlcm = lcma / t * i;
            vala = (mul(mul(aa, (v[i] - vala) / t, nlcm), lcma, nlcm) + vala) % nlcm;
            lcma = nlcm;
        }
    for (ll i = 41; i <= 60; ++i)
        if (~v[i])
        {
            ll t = exgcd(lcmb, i, aa, bb);
            if ((v[i] - valb) % t)
                return std::cout << -1 << std::endl, 0;
            ll nlcm = lcmb / t * i;
            valb = (mul(mul(aa, (v[i] - valb) / t, nlcm), lcmb, nlcm) + valb) % nlcm;
            lcmb = nlcm;
        }
    if (!valb)
    {
        while (vala < ll(least))
            vala += lcma;
        std::cout << gcd % MOD * powermod(w % MOD, vala) % MOD << std::endl;
    }
    else
    {
        ll t = exgcd(lcma, lcmb, aa, bb);
        if ((valb - vala) % t)
            return std::cout << -1 << std::endl, 0;
        ll res = (valb - vala) / t;
        ll nlcm = lcma / t * lcmb;
        vala = (mul(mul(aa, res, nlcm), lcma, nlcm) + vala) % nlcm;
        lcma = nlcm;
        while (vala < ll(least))
            vala += lcma;
        // std::cout << vala % lcma << std::endl;
        std::cout << gcd % MOD * powermod(w % MOD, vala) % MOD << std::endl;
    }
    return 0;
}