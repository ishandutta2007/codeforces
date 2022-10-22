#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, m, p[300005], used[300005], siz[300005], pr[300005];
vector <pair <int, int> > g[300005];
map <pair <int, int>, int> q;

int get(int x)
{
    if(x == p[x])
        return x;

    p[x] = get(p[x]);
    return p[x];
}

void unite(int x, int y)
{
    x = get(x);
    y = get(y);

    if(x == y)
        return;

    if(siz[x] > siz[y])
        swap(x, y);

    p[x] = y;

    siz[y] += siz[x];
}

void dfs(int v)
{
    used[v] = 1;

    for(auto to2:g[v])
    {
        int to = to2.first;

        if(used[to] == 0)
        {
            pr[to] = v;
            dfs(to);
        }
        else if(to != pr[v])
        {
            int x = v;

            while(get(x) != get(to))
            {
                unite(x, to);
                x = pr[x];
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int x, y, z;

        cin >> x >> y >> z;

        x--;
        y--;

        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }

    for(int i = 0; i < n; i++)
    {
        p[i] = i;
        siz[i] = 1;
        pr[i] = -1;
    }

    int a, b;
    cin >> a >> b;

    a--;
    b--;

    dfs(a);

    for(int i = 0; i < n; i++)
        for(auto to:g[i])
    {
        q[{get(i), get(to.first)}] += to.second;
    }

    if(q[{get(b), get(b)}])
        {
            cout << "YES";
            return 0;
        }

    while(b != a)
    {
        if(q[{get(b), get(pr[b])}] + q[{get(pr[b]), get(pr[b])}])
            {
                cout << "YES";
                return 0;
            }

        b = pr[b];
    }

    cout << "NO";
}