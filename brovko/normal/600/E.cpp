#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, a[100005], used[100005], kmax[100005], ans[100005];
vector <int> g[100005];
map <int, int> m[100005];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
        if(used[to] == 0)
        {
            dfs(to);

            if(m[to].size() > m[v].size())
            {
                swap(kmax[v], kmax[to]);
                ans[v] = ans[to];
                swap(m[to], m[v]);
            }

            for(auto x:m[to])
            {
                m[v][x.x] += x.y;

                if(m[v][x.x] > kmax[v])
                {
                    kmax[v] = m[v][x.x];
                    ans[v] = x.x;
                }
                else
                if(m[v][x.x] == kmax[v])
                    ans[v] += x.x;
            }
        }

    if(++m[v][a[v]] > kmax[v])
    {
        kmax[v]++;
        ans[v] = a[v];
    }
    else
    if(m[v][a[v]] == kmax[v])
        ans[v] += a[v];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

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

    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}