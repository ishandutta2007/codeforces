#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 goerohgerigegoihr
#define y0 peowjfefwepojfewe

using namespace std;

int t, n, used[100005], siz[100005], k[100005];
vector <int> g[100005];

void dfs(int v)
{
    used[v] = 1;
    siz[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            dfs(to);
            siz[v] += siz[to];
            k[v] = max(k[v], siz[to]);
        }
    }

    k[v] = max(k[v], n - siz[v]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            g[i].clear();
            used[i] = 0;
            k[i] = 0;
            siz[i] = 0;
        }

        for(int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;

            u--;
            v--;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0);

        int Min = n;

        for(int i = 0; i < n; i++)
        {
            Min = min(Min, k[i]);
        }

        vector <int> ans;

        for(int i = 0; i < n; i++)
        {
            if(k[i] == Min)
                ans.push_back(i);
        }

        if(ans.size() == 1)
        {
            cout << 1 << ' ' << g[0][0] + 1 << "\n" << 1 << ' ' << g[0][0] + 1 << "\n";
        }
        else
        {
            int x = g[ans[0]][0];

            if(x == ans[1])
                x = g[ans[0]][1];

            cout << x + 1 << ' ' << ans[0] + 1 << "\n" << x + 1 << ' ' << ans[1] + 1 << "\n";
        }
    }
}