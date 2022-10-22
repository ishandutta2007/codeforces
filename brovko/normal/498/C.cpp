#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int N = 1000;

int n, m, a[1005], e[1005], ans, f[1005], p[1005], pr[1005], used[1005], F;
vector <int> g[1005];

void bfs()
{
    queue <int> q;

    for(int i = 0; i < n + 2; i++)
        used[i] = 0;

    q.push(n);
    used[n] = 1;

    while(!q.empty() && used[n + 1] == 0)
    {
        int v = q.front();
        q.pop();

        for(auto to:g[v])
        {
            if(used[e[to]] == 0 && p[to] > f[to])
            {
                q.push(e[to]);
                used[e[to]] = 1;
                pr[e[to]] = to;
            }
        }
    }

    if(used[n + 1] == 0)
    {
        F = 0;
        return;
    }

    int Min = 1e9;
    int ver = n + 1;

    while(ver != n)
    {
        Min = min(Min, p[pr[ver]] - f[pr[ver]]);
        ver = e[N - pr[ver]];
    }

    ver = n + 1;

    while(ver != n)
    {
        f[pr[ver]] += Min;
        f[N - pr[ver]] -= Min;
        ver = e[N - pr[ver]];
    }

    ans += Min;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        if(u % 2)
            swap(u, v);

        e[i] = v;
        g[u].pb(i);

        e[N - i] = u;
        g[v].pb(N - i);
    }

    for(int i = m; i < m + n; i++)
    {
        if((i - m) % 2 == 0)
        {
            e[i] = i - m;
            g[n].pb(i);

            e[N - i] = n;
            g[i - m].pb(N - i);
        }
        else
        {
            e[i] = n + 1;
            g[i - m].pb(i);

            e[N - i] = i - m;
            g[n + 1].pb(N - i);
        }
    }

    set <int> q;

    for(int i = 0; i < n; i++)
    {
        int x = a[i];

        for(int j = 2; j * j <= x; j++)
        {
            while(x % j == 0)
            {
                x /= j;
                q.insert(j);
            }
        }

        if(x > 1)
            q.insert(x);
    }

    for(auto d:q)
    {
        for(int i = 0; i < n + m; i++)
        {
            f[i] = 0;
            f[N - i] = 0;
            p[N - i] = 0;

            if(i < m)
                p[i] = 1e9;
            else
            {
                int x = a[i - m], k = 0;

                while(x % d == 0)
                {
                    x /= d;
                    k++;
                }

                p[i] = k;
            }
        }

        F = 1;

        while(F)
            bfs();
    }

    cout << ans;
}