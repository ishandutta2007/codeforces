#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, used[300005], p[300005], r[300005], ps[300005];
vector <int> g[300005];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            p[to] = v;
            dfs(to);
        }
        else if(p[v] != to && used[to] == 1)
        {
            int Min = v, Max = v;
            int x = v;

            while(x != to)
            {
                x = p[x];

//                cout << x << ' ' << to << endl;

                if(x == -1)
                    return;
                Min = min(Min, x);
                Max = max(Max, x);
            }

            r[Min] = min(r[Min], Max);
        }
    }

    used[v] = 2;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        r[i] = n;
        p[i] = -1;
    }

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i = 0; i < n; i++)
        if(used[i] == 0)
            dfs(i);

    for(int i = n - 2; i >= 0; i--)
        r[i] = min(r[i], r[i + 1]);

    for(int i = 0; i < n; i++)
        ps[i + 1] = ps[i] + r[i] - i;

    int q;
    cin >> q;

    while(q--)
    {
        int a, b;
        cin >> a >> b;

        a--;

        int L = a - 1, R = b;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(r[M] > b)
                R = M;
            else L = M;
        }

        cout << ps[R] - ps[a] + (b - R) * (b - R + 1) / 2 << "\n";
    }
}