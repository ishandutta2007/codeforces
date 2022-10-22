#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, used[505][505];
char a[505][505];

void dfs(int x, int y)
{
//    cout << x << ' ' << y << endl;

    used[x][y] = 1;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {-1, 1, 0, 0};

    for(int z = 0; z < 4; z++)
    {
        int x2 = x + dx[z], y2 = y + dy[z];

        if(x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && used[x2][y2] == 0 && a[x2][y2] == '.')
            dfs(x2, y2);
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

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    r1--;
    c1--;
    r2--;
    c2--;

    a[r1][c1] = '.';
    dfs(r2, c2);

    if(used[r1][c1] == 0)
    {
        cout << "NO";
        return 0;
    }

    int cnt = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(abs(i - r2) + abs(j - c2) == 1 && a[i][j] == '.')
                cnt++;
        }

    if(a[r2][c2] == 'X' || cnt >= 2 || cnt == 1 && r1 == r2 && c1 == c2)
        cout << "YES";
    else cout << "NO";
}