#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, x, y, used[1000005], z[1000005], ans[1000005];
vector <int> g[1000005], u[1000005];

void dfs(int v)
{
    used[v] = 1;

    int x = 1e9, y = 1;

    for(auto to:g[v])
        if(used[to] == 0)
        {
            dfs(to);

            if(make_pair(u[to][z[to]], z[to]) > make_pair(y, x))
            {
                x = z[to];
                y = u[to][x];
            }

            if(u[v].size() < u[to].size())
                swap(u[v], u[to]);

            for(int i = (int)u[v].size() - (int)u[to].size(); i < u[v].size(); i++)
            {
                u[v][i] += u[to][i - (int)u[v].size() + u[to].size()];

                if(make_pair(u[v][i], i) > make_pair(y, x))
                {
                    y = u[v][i];
                    x = i;
                }
            }
        }

    u[v].pb(1);

    if(x == 1e9)
        x = u[v].size() - 1;

    z[v] = x;
    ans[v] = u[v].size() - 1 - x;

//    cout << v << endl;
//
//    for(auto to:u[v])
//        cout << to << ' ';
//
//    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;

        x--;
        y--;

        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(0);

    for(int i = 0; i < n; i++)
        cout << ans[i] << "\n";
}