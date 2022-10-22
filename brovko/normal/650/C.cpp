#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, m, p[1000005], siz[1000005], used[1000005], dp[1000005];
map <int, int> mx[1000005], my[1000005];
vector <int> g[1000005];

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

    if(siz[x] > siz[y])
        swap(x, y);

    p[x] = y;
    siz[y] += siz[x];
}

void dfs(int v)
{
    v = get(v);

    if(used[v])
        return;

    used[v] = 1;
    dp[v] = 1;

    for(auto to:g[v])
    {
        if(used[get(to)] == 0)
            dfs(get(to));

        dp[v] = max(dp[v], 1 + dp[get(to)]);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int a[n + 5][m + 5];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    int posx[n + 5][m + 5], posy[m + 5][n + 5];

    for(int i = 0; i < n; i++)
    {
        int y = 1;
        vector <int> v;

        for(int j = 0; j < m; j++)
            v.push_back(a[i][j]);

        sort(v.begin(), v.end());

        for(auto to:v)
        {
            if(mx[i][to] == 0)
            {
                mx[i][to] = y;
                y++;
            }
        }

        for(int j = 0; j < m; j++)
        {
            posx[i][mx[i][a[i][j]]] = j;
        }
    }

    for(int j = 0; j < m; j++)
    {
        int y = 1;
        vector <int> v;

        for(int i = 0; i < n; i++)
            v.push_back(a[i][j]);

        sort(v.begin(), v.end());

        for(auto to:v)
        {
            if(my[j][to] == 0)
            {
                my[j][to] = y;
                y++;
            }
        }

        for(int i = 0; i < n; i++)
        {
            posy[j][my[j][a[i][j]]] = i;
        }
    }

    for(int i = 0; i < 1000005; i++)
    {
        p[i] = i;
        siz[i] = 1;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
    {
        unite(i * m + j, i * m + posx[i][mx[i][a[i][j]]]);
        unite(i * m + j, posy[j][my[j][a[i][j]]] * m + j);
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
    {
        if(mx[i][a[i][j]] > 1)
            g[get(i * m + j)].push_back(get(i * m + posx[i][mx[i][a[i][j]] - 1]));

        if(my[j][a[i][j]] > 1)
            g[get(i * m + j)].push_back(get(posy[j][my[j][a[i][j]] - 1] * m + j));
    }

    for(int i = 0; i < n * m; i++)
        dfs(i);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << dp[get(i * m + j)] << ' ';

        cout << "\n";
    }
}