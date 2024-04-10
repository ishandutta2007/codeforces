#include <bits/stdc++.h>

using namespace std;

const int BASE = 100, MOD = 998244353;

long long modpow(long long b, long long e)
{
    long long res = 1;
    while(e)
    {
        if(e & 1)
            res = res * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return res;
}

int main()
{
    int n;
    scanf("%i", &n);
    long long pid = 1, sum = 0, inv = modpow(BASE, MOD - 2);
    for (int x = 1; x <= n; x++)
    {
        int p;
        scanf("%i", &p);
        sum = (sum + pid * (BASE - p) * x % MOD * inv) % MOD;
        pid = pid * p % MOD * inv % MOD;
    }
    long long ans = (sum * modpow(pid, MOD - 2) + n) % MOD;
    printf("%lli\n", ans);
}