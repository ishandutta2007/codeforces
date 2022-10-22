#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, k, used[200005], d[200005], down[200005];
vector <int> g[200005];
set <pair <int, int> > q;

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            dfs(to);
            d[v] = max(d[v], d[to] + 1);

            if(d[v] == d[to] + 1)
                down[v] = to;
        }
    }

    q.insert({d[v], v});
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0);

//    for(int i = 0; i < n; i++)
//    {
//        cout << d[i] << ' ' << down[i] << endl;
//    }

    int x = 0;

    for(int i = 0; i < k; i++)
    {
        if(q.empty())
        {
            x = i + 1;
            break;
        }

        int v = (*q.rbegin()).y;

        q.erase({d[v], v});

        while(d[v] > 0)
        {
            v = down[v];
            q.erase({d[v], v});
        }
    }

//    cout << x << ' ' << q.size() << endl;

    if(x > 0)
    {
        int r = x - 1, w = n - x + 1;

        while(r < w && r < k)
        {
            r++;
            w--;
        }

        cout << r * w;
    }
    else
    {
        int r = k, b = 0, w = n - k;

        while(b - r < w && w > 0 && b < q.size())
        {
            b++;
            w--;
        }

        cout << (r - b) * w;
    }
}