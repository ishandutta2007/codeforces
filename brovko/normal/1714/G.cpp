#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;

using li = long long;
const int N = 2e5 + 5;

int used[N], a[N], b[N], sa[N], sb[N], p[N], up[N][20], d[N];
vector <int> g[N];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            d[to] = d[v] + 1;
            sa[to] = sa[v] + a[to];
            sb[to] = sb[v] + b[to];
            dfs(to);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            used[i] = 0;
            g[i].clear();
        }

        for(int i = 1; i < n; i++)
        {
            cin >> p[i] >> a[i] >> b[i];

            p[i]--;

            g[p[i]].pb(i);
            g[i].pb(p[i]);
        }

        dfs(0);

        for(int i = 0; i < n; i++)
        {
            up[i][0] = p[i];
        }

        for(int j = 1; j < 20; j++)
            for(int i = 0; i < n; i++)
            {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }

        for(int i = 1; i < n; i++)
        {
            int v = i;

            for(int j = 19; j >= 0; j--)
                if(sb[up[v][j]] > sa[i])
                    v = up[v][j];

            if(sb[v] > sa[i])
                v = p[v];

            cout << d[v] << ' ';
        }

        cout << "\n";
    }
}