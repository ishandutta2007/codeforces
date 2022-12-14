#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = 1000000007;

long long qpow(long long v, long long st)
{
    long long r = 1;
    while (st)
    {
        if (st&1)
        {
            r *= v;
            if (r >= mod)
                r %= mod;
        }
        v = v * v;
        if (v >= mod)
            v %= mod;
        st /= 2;
    }
    return r;
}

int n;
vector<int> g[1 << 20];
int x[1<<20];

int par[1<<20];
long long dp[1 << 20][2];

long long dfs(int, int);

long long val(int v)
{
    if (x[v])
        return dfs(v, 1);
    else
        return dfs(v, 0) + dfs(v, 1);
}

long long dfs(int v, int p = 1)
{
    if (dp[v][p] != -1)
    {
        return dp[v][p];
    }
    if (x[v])
        p = 1;

    long long ans = 1;
    bool is_leaf = true;
    long long sm0 = 1;
    if (p == 0)
    {
        for (int i = 0; i < (int) g[v].size(); ++i)
        {
            int u = g[v][i];
            if (par[u] == -1 || par[u] == v)
            {
                is_leaf = false;
                par[u] = v;
                sm0 *= val(u);
                if (sm0 >= mod)
                    sm0 %= mod;
            }
        }
        if (sm0 >= mod)
            sm0 %= mod;
        ans = 0;
        for (int i = 0; i < (int) g[v].size(); ++i)
        {
            int u = g[v][i];
            if (par[u] == -1 || par[u] == v)
            {
                par[u] = v;
                if (dfs(u, 0) != 0)
                {
                    long long pr = qpow(val(u), mod - 2) * dfs(u, 0);
                    if (pr >= mod) pr %= mod;
                    pr *= sm0;
                    pr %= mod;
                    ans += pr;
                    if (ans >= mod)
                        ans %= mod;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < (int) g[v].size(); ++i)
        {
            int u = g[v][i];
            if (par[u] == -1 || par[u] == v)
            {
                is_leaf = false;
                par[u] = v;
                long long cmul = 0;
                if (p == 1 && x[u] == 1)
                {
                    cmul = dfs(u, 1);
                }
                else if (p == 0 && x[u] == 1)
                {
                    cmul = dfs(u, 1);
                }
                else if (p == 1 && x[u] == 0)
                {
                    cmul = dfs(u, 0) + dfs(u, 1);
                }
                else if (p == 0 && x[u] == 0)
                {
                    cmul = dfs(u, 0);
                }
                ans *= cmul;
                if (ans >= mod)
                    ans %= mod;
            }
        }
    }
    if (is_leaf && !p && !x[v])
    {
        ans = 0;
    }
    dp[v][p] = ans;
    return dp[v][p];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int p;
        scanf("%d", &p);
        g[p].push_back(i);
        g[i].push_back(p);
    }
    for (int i = 0; i < n; ++i)
        scanf("%d", &x[i]);
    memset(par, -1, sizeof(par));
    for (int i = 0; i < n; ++i)
    {
        if (x[i])
        {
            par[i] = -2;
            dfs(i);
            printf("%d\n", (int) dp[i][1]);
            break;
        }
    }
    return 0;
}