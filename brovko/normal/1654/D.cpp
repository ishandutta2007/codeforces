#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;
const int MOD = 998244353;

int n, used[200005], kdiv[200005], lp[200005], ans[200005], V[200005];
vector <vector <int> > g[200005];

int add(int x, int y)
{
    x += y;

    return (x >= MOD ? x - MOD : x);
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;
}

int binpow(int x, int y)
{
    if(y == 0)
        return 1;

    if(y % 2)
        return mul(x, binpow(x, y - 1));

    int p = binpow(x, y / 2);

    return mul(p, p);
}

int inv(int x)
{
    return binpow(x, MOD - 2);
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
        if(used[to[0]] == 0)
        {
            vector <int> factx, facty;
            int x = to[1], y = to[2];

            while(x > 1)
            {
                factx.pb(lp[x]);
                x /= lp[x];
            }

            while(y > 1)
            {
                facty.pb(lp[y]);
                y /= lp[y];
            }

            for(auto x:factx)
                kdiv[x]++;

            for(auto y:facty)
                kdiv[y]--;

            for(auto x:factx)
                ans[x] = max(ans[x], kdiv[x]);

            dfs(to[0]);

            for(auto x:factx)
                kdiv[x]--;

            for(auto y:facty)
                kdiv[y]++;
        }
}

void dfs2(int v)
{
    used[v] = 1;

    for(auto to:g[v])
        if(used[to[0]] == 0)
        {
            V[to[0]] = mul(V[v], divide(to[2], to[1]));
            dfs2(to[0]);
        }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 2; i * i < 200005; i++)
        if(lp[i] == 0)
            for(int j = i * i; j < 200005; j += i)
                if(lp[j] == 0)
                    lp[j] = i;

    for(int i = 2; i < 200005; i++)
        if(lp[i] == 0)
            lp[i] = i;

    int t;
    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i <= n; i++)
        {
            g[i].clear();
            used[i] = 0;
            kdiv[i] = 0;
            ans[i] = 0;
            V[i] = 0;
        }

        for(int e = 0; e < n - 1; e++)
        {
            int i, j, x, y;
            cin >> i >> j >> x >> y;

            i--;
            j--;

            g[i].pb({j, x, y});
            g[j].pb({i, y, x});
        }

        dfs(0);

        int M = 1;

        for(int i = 2; i <= n; i++)
            for(int j = 0; j < ans[i]; j++)
                M = mul(M, i);

        for(int i = 0; i < n; i++)
            used[i] = 0;

        V[0] = M;

        dfs2(0);

        int Ans = 0;

        for(int i = 0; i < n; i++)
            Ans = add(Ans, V[i]);

        cout << Ans << "\n";
    }
}