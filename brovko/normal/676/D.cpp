#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, m, dp[1005][1005][4], xt, yt, xm, ym, l[128], r[128], u[128], d[128];
char a[1005][1005];

int f(char c, int x)
{
    if(x == 0)
        return u[c];

    if(x == 1)
        return r[c];

    if(x == 2)
        return d[c];

    if(x == 3)
        return l[c];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    cin >> xt >> yt >> xm >> ym;

    xt--;
    yt--;
    xm--;
    ym--;

    dp[xt][yt][0] = 1;

    queue <pair <int, pair <int, int> > > q;

    q.push({xt, {yt, 0}});

    u['+'] = 1;
    u['|'] = 1;
    u['^'] = 1;
    u['L'] = 1;
    u['R'] = 1;
    u['D'] = 1;

    d['+'] = 1;
    d['|'] = 1;
    d['v'] = 1;
    d['L'] = 1;
    d['U'] = 1;
    d['R'] = 1;

    l['+'] = 1;
    l['-'] = 1;
    l['<'] = 1;
    l['U'] = 1;
    l['R'] = 1;
    l['D'] = 1;

    r['+'] = 1;
    r['-'] = 1;
    r['>'] = 1;
    r['U'] = 1;
    r['L'] = 1;
    r['D'] = 1;

    while(!q.empty())
    {
        pair <int, pair <int, int> > p = q.front();

        int x = p.first;
        int y = p.second.first;
        int z = p.second.second;

        if(x + 1 < n && dp[x + 1][y][z] == 0 && f(a[x][y], (z + 2) % 4) && f(a[x + 1][y], z))
        {
            dp[x + 1][y][z] = dp[x][y][z] + 1;
            q.push({x + 1, {y, z}});
        }

        if(x - 1 >= 0 && dp[x - 1][y][z] == 0 && f(a[x][y], z) && f(a[x - 1][y], (z + 2) % 4))
        {
            dp[x - 1][y][z] = dp[x][y][z] + 1;
            q.push({x - 1, {y, z}});
        }

        if(y + 1 < m && dp[x][y + 1][z] == 0 && f(a[x][y], (z + 1) % 4) && f(a[x][y + 1], (z + 3) % 4))
        {
            dp[x][y + 1][z] = dp[x][y][z] + 1;
            q.push({x, {y + 1, z}});
        }

        if(y - 1 >= 0 && dp[x][y - 1][z] == 0 && f(a[x][y], (z + 3) % 4) && f(a[x][y - 1], (z + 1) % 4))
        {
            dp[x][y - 1][z] = dp[x][y][z] + 1;
            q.push({x, {y - 1, z}});
        }

        if(dp[x][y][(z + 3) % 4] == 0)
        {
            dp[x][y][(z + 3) % 4] = dp[x][y][z] + 1;
            q.push({x, {y, (z + 3) % 4}});
        }

        q.pop();
    }

    int x = 1e18;

    if(dp[xm][ym][0])
        x = min(x, dp[xm][ym][0]);

    if(dp[xm][ym][1])
        x = min(x, dp[xm][ym][1]);

    if(dp[xm][ym][2])
        x = min(x, dp[xm][ym][2]);

    if(dp[xm][ym][3])
        x = min(x, dp[xm][ym][3]);

    if(x == 1e18)
        cout << -1;

    else cout << x - 1;
}