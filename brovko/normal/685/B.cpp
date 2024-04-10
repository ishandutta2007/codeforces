#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int n, q, p[300005], siz[300005], Max[300005], ans[300005];
vector <int> g[300005];

void dfs1(int v)
{
    siz[v] = 1;
    ans[v] = v;

    int x = 0;

    for(auto to:g[v])
    {
        dfs1(to);
        siz[v] += siz[to];

        if(siz[to] > x)
        {
            Max[v] = to;
            x = siz[to];
        }
    }

    if(g[v].size() > 0)
        ans[v] = ans[Max[v]];
}

void dfs2(int v)
{
    for(auto to:g[v])
        dfs2(to);

    if(g[v].size() > 0)
    {
        ans[v] = ans[Max[v]];
        
        while(siz[ans[v]] < (siz[v] + 1) / 2)
            ans[v] = p[ans[v]];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    for(int i = 1; i < n; i++)
    {
        cin >> p[i];
        p[i]--;

        g[p[i]].push_back(i);
    }

    dfs1(0);
    dfs2(0);

    while(q--)
    {
        int x;
        cin >> x;
        x--;

        cout << ans[x] + 1 << "\n";
    }
}