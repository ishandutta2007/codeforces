#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

int n, m, w, a[2005][2005], used[2005][2005], d[2005][2005], d0[2005][2005];

bool isin(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void bfs(int i, int j)
{
    d[i][j] = 0;

    queue <pair <int, int> > q;
    q.push({i, j});

    used[i][j] = 1;

    while(!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;

        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};

        for(int z = 0; z < 4; z++)
            if(isin(x + dx[z], y + dy[z]) && a[x + dx[z]][y + dy[z]] > -1 && used[x + dx[z]][y + dy[z]] == 0)
            {
                used[x + dx[z]][y + dy[z]] = 1;
                d[x + dx[z]][y + dy[z]] = d[x][y] + w;

                q.push({x + dx[z], y + dy[z]});
            }

        q.pop();
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> w;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            d[i][j] = 1e18;

    bfs(0, 0);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            d0[i][j] = d[i][j];
            used[i][j] = 0;
            d[i][j] = 1e18;
        }

    bfs(n - 1, m - 1);

    int m1 = 1e18, m2 = 1e18;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] > 0)
            {
                m1 = min(m1, d0[i][j] + a[i][j]);
                m2 = min(m2, d[i][j] + a[i][j]);
            }

    if(min(d[0][0], m1 + m2) >= 1e17)
        cout << -1;
    else
    cout <<  min(d[0][0], m1 + m2);
}