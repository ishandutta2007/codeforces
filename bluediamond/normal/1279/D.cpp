#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 998244353;

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
    {
        return a - MOD;
    }
    if (a < 0)
    {
        return a + MOD;
    }
    return a;
}

int mul(int a, int b)
{
    return a * (ll) b  % MOD;
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
    return mul(a, pw(b, MOD - 2));
}

const int N = (int) 1e6 + 7;
int n;
vector<int> want[N];
int tot;
int f[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++)
        {
            int x;
            cin >> x;
            want[i].push_back(x);
            f[x]++;
        }
        tot = add(tot, l);
    }
    int sol = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = (int) want[i].size();
        for (auto &x : want[i])
        {
            sol = add(sol, mul(dv(1, n), mul(dv(1, l), dv(f[x], n))));
        }
    }
    cout << sol << "\n";
}