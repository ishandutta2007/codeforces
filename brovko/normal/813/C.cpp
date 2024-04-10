#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, x, used1[200005], used2[200005], d1[200005], d2[200005];
vector <int> g[200005];

void dfs1(int v)
{
    used1[v] = 1;

    for(auto to:g[v])
    {
        if(used1[to] == 0)
        {
            d1[to] = d1[v] + 1;
            dfs1(to);
        }
    }
}

void dfs2(int v)
{
    used2[v] = 1;
    for(auto to:g[v])
    {
        if(used2[to] == 0 && d2[v] + 1 < d1[to])
        {
            d2[to] = d2[v] + 1;
            dfs2(to);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    x--;

    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs1(0);
    dfs2(x);

    int Max = 0;

    for(int i = 0; i < n; i++)
        if(used2[i])
            Max = max(Max, d1[i] * 2);

    cout << Max;
}