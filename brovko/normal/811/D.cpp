#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, used[105][105], p[105][105], nxt[105][105];
char a[105][105];

vector <int> v;

void dfs(int x, int y)
{
    used[x][y] = 1;

    if(x + 1 < n && a[x + 1][y] != '*' && used[x + 1][y] == 0)
    {
        p[x + 1][y] = 1;
        dfs(x + 1, y);
    }

    if(y + 1 < m && a[x][y + 1] != '*' && used[x][y + 1] == 0)
    {
        p[x][y + 1] = 3;
        dfs(x, y + 1);
    }

    if(x - 1 >= 0 && a[x - 1][y] != '*' && used[x - 1][y] == 0)
    {
        p[x - 1][y] = 2;
        dfs(x - 1, y);
    }

    if(y - 1 >= 0 && a[x][y - 1] != '*' && used[x][y - 1] == 0)
    {
        p[x][y - 1] = 4;
        dfs(x, y - 1);
    }
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

    dfs(0, 0);

    int x = 0;
    int y = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == 'F')
                {
                    x = i;
                    y = j;
                }

    while(x != 0 || y != 0)
    {
        if(p[x][y] == 1)
        {
            v.push_back(2);
            x--;
        }

        if(p[x][y] == 2)
        {
            v.push_back(1);
            x++;
        }

        if(p[x][y] == 3)
        {
            v.push_back(4);
            y--;
        }

        if(p[x][y] == 4)
        {
            v.push_back(3);
            y++;
        }
    }

    int dx = 0;
    int dy = 0;

    for(int i = (int)v.size() - 1; i >= 0; i--)
    {
        if(v[i] == 1)
        {
            if(dx == 2)
                cout << 'D';
            else cout << 'U';
        }

        if(v[i] == 2)
        {
            if(dx == 2)
                cout << 'U';
            else cout << 'D';
        }

        if(v[i] == 3)
        {
            if(dy == 2)
                cout << 'R';
            else cout << 'L';
        }

        if(v[i] == 4)
        {
            if(dy == 2)
                cout << 'L';
            else cout << 'R';
        }

        cout << endl;

        int x1, y1;
        cin >> x1 >> y1;
        x1--;
        y1--;

        if(x1 == x && y1 == y)
        {
            if(v[i] <= 2)
                dx = 2;
            else dy = 2;

            i++;
        }
        else
        {
            x = x1;
            y = y1;
        }
    }
}