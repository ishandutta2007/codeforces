#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
const int N = 1e5 + 5;

int used[N], u[N], d[N], ans[N];
vector <int> g[N];

void dfs1(int v)
{
    used[v] = 1;
    d[v] = -1e9;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            dfs1(to);
            d[v] = max(d[v], d[to] + 1);
        }
    }

    if(u[v])
        d[v] = max(d[v], 0);
}

void dfs2(int v)
{
    used[v] = 1;

    if(u[v])
        ans[v] = max(ans[v], 0);

    int mx = -1e9, mx2 = -1e9;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            if(d[to] > mx2)
                mx2 = d[to];

            if(mx2 > mx)
                swap(mx2, mx);
        }
    }

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            ans[to] = max(ans[v] + 1, (d[to] == mx ? mx2 : mx) + 2);
            dfs2(to);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, D;
    cin >> n >> m >> D;

    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        u[x - 1] = 1;
    }

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs1(0);

    for(int i = 0; i < n; i++)
        used[i] = 0;

    for(int i = 0; i < n; i++)
        ans[i] = -1e9;

    if(u[0])
        ans[0] = 0;

    dfs2(0);
//
//    for(int i = 0; i < n; i++)
//        cout << d[i] << ' ';
//
//    cout << "\n";
//
//    for(int i = 0; i < n; i++)
//        cout << ans[i] << ' ';
//
//    cout << "\n";

    for(int i = 0; i < n; i++)
        ans[i] = max(ans[i], d[i]);

    int A = 0;

    for(int i = 0; i < n; i++)
        if(ans[i] <= D)
            A++;

    cout << A;
}