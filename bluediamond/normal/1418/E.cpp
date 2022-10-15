#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 998244353;

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

const int N = (int) 2e5 + 7;
int n;
int q;
int v[N];
int sum[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = (sum[i - 1] + v[i]) % M;
    }
    while (q--)
    {
        int a, b, last = 0, l = 1, r = n;
        cin >> a >> b;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (v[m] < b)
            {
                last = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        int big = n - last;
        int sol = 0;
        if (big < a)
        {
            cout << "0\n";
            continue;
        }
        sol = mul(sum[last], dv(big - a + 1, big + 1));
        sol = add(sol, mul(add(sum[n], -sum[last]), dv(big - a, big)));
        cout << sol << "\n";
    }
}