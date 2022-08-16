#include <iostream>

using namespace std;

const int mod = (int)1e6 + 3, C = (int)2e5 + 5, N = (int)5e5 + 5;
long long fact[N+C], invFact[N+C];

long long fastModExp(long long x, long long e, long long mod)
{
 //Calculates x raised to the power e modulo m
 //Time Complexity is O(log2(e))
 //Works as long as mod^2 fits in long long

    long long ans = 1;
    x %= mod;

    while (e != 0)
    {
        if (e % 2 == 1)
            ans = (ans * x) % mod;

        x = (x * x) % mod;
        e /= 2;
    }

    return ans;
}

void pre()
{
    fact[0] = 1;
    invFact[0] = 1;

    for (int i = 1; i < N+C; ++i)
    {
        fact[i] = (i * fact[i-1]) % mod;
        invFact[i] = fastModExp(fact[i], mod-2, mod);
    }
}

int getAns(int n, int c)
{
    long long ans = (fact[n+c] * invFact[c]) % mod;
    ans = (ans * invFact[n]) % mod;

    return (ans - 1) % mod;
}



int main()
{
    ios_base::sync_with_stdio(false);
    pre();

    int n, c;

    cin >> n >> c;
    cout << getAns(n, c);

    return 0;
}