#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, u, v, a[100005], x, y, used[100005], f;
vector <int> g[100005];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 0)
            {
                dfs(to);
                if(v != x && a[v] != a[to])
                    f = 0;
            }
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

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        for(auto to:g[i])
    {
        if(a[i] != a[to])
        {
            x = i;
            y = to;
        }
    }

    if(x == 0 && y == 0)
    {
        cout << "YES\n1";
        return 0;
    }

    f = 1;
    dfs(x);

    if(f)
    {
        cout << "YES\n" << x + 1;
        return 0;
    }

    swap(x, y);
    for(int i = 0; i < n; i++)
        used[i] = 0;

    f = 1;
    dfs(x);

    if(f)
    {
        cout << "YES\n" << x + 1;
        return 0;
    }

    cout << "NO";
}