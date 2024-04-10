#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, u, v, used[100005], c[100005];
vector <int> g[100005];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
        if(used[to] == 0)
    {
        c[to] = 1 - c[v];
        dfs(to);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);

    int k0 = 0;
    int k1 = 0;

    for(int i = 0; i < n; i++)
    {
        if(c[i] == 0)
            k0++;
        else k1++;
    }

    cout << k0 * k1 - n + 1;
}