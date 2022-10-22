#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, s, t, ds, dt, c[200005], cl, useds[200005], usedt[200005];
vector <int> g[200005];
vector <pair <int, int> > ans;

void dfs(int v)
{
    c[v] = cl;

    for(auto to:g[v])
    {
        if(to != s && to != t && c[to] == 0)
            {
                dfs(to);
                ans.push_back({v + 1, to + 1});
            }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    cin >> s >> t >> ds >> dt;
    s--;
    t--;

    for(int i = 0; i < n; i++)
    {
        if(i != s && i != t && c[i] == 0)
        {
            cl++;
            dfs(i);
        }
    }

    c[s] = n + 1;
    c[t] = n + 2;

    for(auto to:g[s])
    {
        useds[c[to]] = to + 1;
    }

    for(auto to:g[t])
    {
        usedt[c[to]] = to + 1;
    }

    for(int i = 0; i <= n; i++)
        if(useds[i] > 0 && usedt[i] == 0)
        {
            ans.push_back({s + 1, useds[i]});
            ds--;
        }

    for(int i = 0; i <= n; i++)
    {
        if(usedt[i] > 0 && useds[i] == 0)
        {
            ans.push_back({t + 1, usedt[i]});
            dt--;
        }
    }

    int f = 0;

    for(int i = 0; i <= n; i++)
    {
        if(usedt[i] > 0 && useds[i] > 0)
        {
            if(ds > 0)
            {
                ans.push_back({s + 1, useds[i]});
                ds--;

                if(f == 0)
                {
                    f = 1;

                    ans.push_back({t + 1, usedt[i]});
                    dt--;
                }
            }
            else
            {
                ans.push_back({t + 1, usedt[i]});
                dt--;
            }
        }
    }

    if(f == 0 && useds[n + 2] > 0)
    {
        ans.push_back({s + 1, t + 1});
        ds--;
        dt--;
        f = 1;
    }

    if(ds < 0 || dt < 0 || f == 0)
    {
        cout << "No";
        return 0;
    }

    cout << "Yes\n";

    for(auto to:ans)
        cout << to.first << ' ' << to.second << "\n";
}