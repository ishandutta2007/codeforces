#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int n, a[505], c[505][505], k[505];

void dfs(int x, int y, int cl)
{
    if(x <= 0 || y <= 0 || x > n || y > x || k[cl] == a[cl] || c[x][y] > 0 || (x == y && x != cl))
        return;

    //cout << x << ' ' << y << ' ' << cl << endl;

    c[x][y] = cl;
    k[cl]++;

    int dx[4] = {0, 1, -1, 0}, dy[4] = {-1, 0, 0, 1};

    for(int i = 0; i < 4; i++)
        dfs(x + dx[i], y + dy[i], cl);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++)
    {
        dfs(i, i, i);

        if(k[i] != a[i])
        {
            cout << -1;
            return 0;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
            cout << a[c[i][j]] << ' ';

        cout << "\n";
    }
}