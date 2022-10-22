#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, q, p[100005], up[100005][25], used[100005], tin[100005], tout[100005], T;
vector <int> g[100005];

void dfs(int v)
{
    T++;
    tin[v] = T;
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 0)
            {
                p[to] = v;
                dfs(to);
            }
    }

    T++;
    tout[v] = T;
}

int anc(int x, int y)
{
    return (tin[x] <= tin[y] && tout[x] >= tout[y]);
}

int d(int x, int y)
{
    int ans = 0;

    for(int i = 19; i >= 0; i--)
        if(anc(up[x][i], y) == 0)
            {
                x = up[x][i];
                ans += (1ll << i);
            }

    if(anc(x, y) == 0)
        {
            ans++;
            x = p[x];
        }

    if(x != y)
        ans += d(y, x);

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    for(int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        x--;

        g[i].push_back(x);
        g[x].push_back(i);
    }

    dfs(0);

    for(int i = 0; i < n; i++)
        up[i][0] = p[i];

    for(int i = 1; i < 20; i++)
        for(int j = 0; j < n; j++)
            up[j][i] = up[up[j][i - 1]][i - 1];

    while(q--)
    {
        int a, b, c;

        cin >> a >> b >> c;
        a--;
        b--;
        c--;

        int x = d(a, b);
        int y = d(b, c);
        int z = d(a, c);

        //cout << "!" << x << ' ' << y << ' ' << z << "\n";

        cout << (x + y + z) / 2 - min(x, min(y, z)) + 1 << "\n";
    }
}