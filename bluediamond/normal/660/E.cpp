#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = (int) 1e9 + 7;

int add(int a, int b)
{
    a += b;
    if (a >= M)
    {
        return a - M;
    }
    if (a < 0)
    {
        return a + M;
    }
    return a;
}

int mul(int a, int b)
{
    return a * (ll) b % M;
}

int pw(int a, int b)
{
    int r = 1;
    while (b)
    {
        if (b & 1)
        {
            r = mul(r, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return r;
}

int dv(int a, int b)
{
    return mul(a, pw(b, M - 2));
}

const int N = (int) 1e6 + 7;
int fact[N];
int ifact[N];

int c(int n, int k)
{
    return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = mul(fact[i - 1], i);
    }
    ifact[N - 1] = dv(1, fact[N - 1]);
    for (int i = N - 2; i >= 0; i--)
    {
        ifact[i] = mul(ifact[i + 1], i + 1);
    }
    int n, m, sol = 0;
    cin >> n >> m;
    for (int d = 0; d <= n - 1; d++)
    {
        int cur = 0;
        cur = c(n, d + 1);
        cur = mul(cur, pw(m - 1, d));
        cur = mul(cur, pw(m, n - d));
        sol = add(sol, cur);
    }
    sol = add(sol, pw(m, n));
    cout << sol << "\n";
}