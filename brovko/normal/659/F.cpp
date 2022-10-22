#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, m, k, a[1005][1005], px[1005][1005], py[1005][1005], siz[1005][1005], used[1005][1005], ans[1005][1005], K;
vector <pair <int, pair <int, int> > > v;

pair <int, int> get(int x, int y)
{
    if(px[x][y] == x && py[x][y] == y)
        return {x, y};

    pair <int, int> p = get(px[x][y], py[x][y]);

    px[x][y] = p.first;
    py[x][y] = p.second;

    return p;
}

void unite(int x1, int y1, int x2, int y2)
{
    pair <int, int> p = get(x1, y1);

    x1 = p.first;
    y1 = p.second;

    p = get(x2, y2);

    x2 = p.first;
    y2 = p.second;

    if(x1 == x2 && y1 == y2)
        return;

    if(siz[x1][y1] > siz[x2][y2])
    {
        swap(x1, x2);
        swap(y1, y2);
    }

    px[x1][y1] = x2;
    py[x1][y1] = y2;

    siz[x2][y2] += siz[x1][y1];
}

void dfs(int x, int y, int val)
{
    used[x][y] = 0;

    if(K == 0)
        return;

    ans[x][y] = val;

    K--;

    if(x > 0 && used[x - 1][y] == 1)
        dfs(x - 1, y, val);

    if(x < n - 1 && used[x + 1][y] == 1)
        dfs(x + 1, y, val);

    if(y > 0 && used[x][y - 1] == 1)
        dfs(x, y - 1, val);

    if(y < m - 1 && used[x][y + 1] == 1)
        dfs(x, y + 1, val);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
    {
        cin >> a[i][j];

        v.push_back({a[i][j], {i, j}});

        px[i][j] = i;
        py[i][j] = j;

        siz[i][j] = 1;
    }

    sort(v.rbegin(), v.rend());

    for(auto to:v)
    {
        int x = to.first;
        int y = to.second.first;
        int z = to.second.second;

        used[y][z] = 1;

        if(y > 0 && used[y - 1][z] == 1)
            unite(y, z, y - 1, z);

        if(z > 0 && used[y][z - 1] == 1)
            unite(y, z, y, z - 1);

        if(y < n - 1 && used[y + 1][z] == 1)
            unite(y, z, y + 1, z);

        if(z < m - 1 && used[y][z + 1] == 1)
            {
                unite(y, z, y, z + 1);
            }

        if(siz[get(y, z).first][get(y, z).second] >= k / x && k % x == 0)
        {
            cout << "YES\n";

            K = k / x;
            dfs(y, z, x);

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                    cout << ans[i][j] << ' ';

                cout << "\n";
            }

            return 0;
        }
    }

    cout << "NO";
}