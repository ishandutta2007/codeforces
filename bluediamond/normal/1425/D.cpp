/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 2002;

const int MOD = 1e9+7;

int pwr (int a, int b)
{
    if(b == 0)
        return 1;
    if(b & 1)
        return 1LL * a * pwr(a, (b ^ 1)) % MOD;
    int aux = pwr(a, (b >> 1));
    return 1LL * aux * aux % MOD;
}

int n, m, r;

struct Snake
{
    int a, b;
    int danger;
};

Snake v[N_MAX];

int sp[1002][1002];

int fact[N_MAX];
int ifact[N_MAX];

int comb (int a, int b)
{
    if(b > a)
        return 0;
    return 1LL * fact[a] * ifact[b] % MOD * ifact[a - b] % MOD;
}

int cnt (int a1, int b1, int a2, int b2)
{
    return sp[a2][b2] - sp[a2][b1 - 1] - sp[a1 - 1][b2] + sp[a1 - 1][b1 - 1];
}

int itcnt (int a1, int b1, int a2, int b2, int a3, int b3, int a4, int b4)
{
    int ia1, ib1, ia2, ib2;
    ia1 = max(a1, a3);
    ib1 = max(b1, b3);
    ia2 = min(a2, a4);
    ib2 = min(b2, b4);
    if(ia1 <= ia2 && ib1 <= ib2)
        return sp[ia2][ib2] - sp[ia2][ib1 - 1] - sp[ia1 - 1][ib2] + sp[ia1 - 1][ib1 - 1];
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++)
        cin >> v[i].a >> v[i].b >> v[i].danger;
    for(int i = 1; i <= n; i++)
        sp[v[i].a][v[i].b] = 1;
    for(int i = 1; i <= 1000; i++)
        for(int j = 1; j <= 1000; j++)
            sp[i][j] += sp[i - 1][j] + sp[i][j - 1] - sp[i - 1][j - 1];
    fact[0] = 1;
    ifact[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
        ifact[i] = pwr(fact[i], MOD - 2);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            int a1, b1, a2, b2;
            a1 = v[i].a - r;
            b1 = v[i].b - r;
            a2 = v[i].a + r;
            b2 = v[i].b + r;
            if(a1 < 1)
                a1 = 1;
            if(b1 < 1)
                b1 = 1;
            if(a2 > 1000)
                a2 = 1000;
            if(b2 > 1000)
                b2 = 1000;
            int a3, b3, a4, b4;
            a3 = v[j].a - r;
            b3 = v[j].b - r;
            a4 = v[j].a + r;
            b4 = v[j].b + r;
            if(a3 < 1)
                a3 = 1;
            if(b3 < 1)
                b3 = 1;
            if(a4 > 1000)
                a4 = 1000;
            if(b4 > 1000)
                b4 = 1000;
            int in = itcnt(a1, b1, a2, b2, a3, b3, a4, b4);
            int A = cnt(a1, b1, a2, b2) - in;
            int B = cnt(a3, b3, a4, b4) - in;
            int out = A + B;
            int all = 0;
            all += (1LL * comb(n, m) - comb(n - in, m) + MOD) % MOD;
            all += ((1LL * comb(n - in, m) - comb(n - in - A, m) - comb(n - in - B, m) + comb(n - in - out, m)) % MOD + MOD) % MOD;
            if(all >= MOD)
                all -= MOD;
            ans += 1LL * all * v[i].danger % MOD * v[j].danger % MOD;
            if(ans >= MOD)
                ans -= MOD;
        }
    cout << ans % MOD << "\n";
    return 0;
}