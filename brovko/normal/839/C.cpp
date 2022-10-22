#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, u, v, used[100005];
vector <int> g[100005];

ld dfs(int v)
{
    used[v] = 1;
    int f = 0;
    ld ans = 0;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            f++;
            ans += dfs(to);
        }
    }

    if(f == 0)
        return 0;

    return ans / f + 1;
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

    cout << setprecision(20) << dfs(0);
}