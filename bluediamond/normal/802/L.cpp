#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = (int) 1e9 + 7;

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
    return a * (ll) b % MOD;
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

const int N = (int) 1e5 + 7;
int n;
int sum[N];
int f[N];
int s[N];
int deg[N];
/// x(a) = x(p) * f(a) + s(a)
vector<pair<int, int>> g[N];

void dfs(int a, int p)
{
    bool leaf = 1;
    for (auto &it : g[a])
    {
        int b = it.first;
        if (b != p)
        {
            leaf = 0;
        }
    }
    if (leaf)
    {
        return;
    }
    int sum_f = 0;
    int sum_s = 0;
    for (auto &it : g[a])
    {
        int b = it.first;
        if (b == p)
        {
            continue;
        }
        dfs(b, a);
        sum_f = add(sum_f, f[b]);
        sum_s = add(sum_s, s[b]);
    }
    int c1 = add(1, -dv(sum_f, deg[a]));
    int c2 = dv(1, deg[a]);
    int c3 = add(sum[a], dv(sum_s, deg[a]));
    f[a] = dv(c2, c1);
    s[a] = dv(c3, c1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        sum[x] = add(sum[x], z);
        sum[y] = add(sum[y], z);
        deg[x]++;
        deg[y]++;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    for (int i = 0; i < n; i++)
    {
        sum[i] = dv(sum[i], deg[i]);
    }
    dfs(0, -1);
    cout << s[0] << "\n";
    return 0;
}