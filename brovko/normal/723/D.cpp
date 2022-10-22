#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, k, siz, f, c[55][55], cl;
char a[55][55];
vector <pair <int, int> > v;

void dfs(int x, int y)
{
    if(x == n - 1 || x == 0 || y == m - 1 || y == 0)
    {
        f = 1;
    }

    c[x][y] = cl;
    siz++;

    if(x + 1 < n && a[x + 1][y] == '.' && c[x + 1][y] == 0)
        dfs(x + 1, y);

    if(x - 1 >= 0 && a[x - 1][y] == '.' && c[x - 1][y] == 0)
        dfs(x - 1, y);

    if(y + 1 < m && a[x][y + 1] == '.' && c[x][y + 1] == 0)
        dfs(x, y + 1);

    if(y - 1 >= 0 && a[x][y - 1] == '.' && c[x][y - 1] == 0)
        dfs(x, y - 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == '.' && c[i][j] == 0)
            {
                cl++;
                f = 0;
                siz = 0;

                dfs(i, j);

                if(f == 0)
                    v.push_back({siz, cl});
            }
        }

    sort(v.begin(), v.end());
    int ans = 0;

    for(int i = 0; i < v.size() - k; i++)
    {
        ans += v[i].first;

        for(int x = 0; x < n; x++)
            for(int y = 0; y < m; y++)
                if(c[x][y] == v[i].second)
                    a[x][y] = '*';
    }

    cout << ans << "\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << a[i][j];

        cout << "\n";
    }
}