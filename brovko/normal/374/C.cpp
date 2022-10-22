#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, dp[1005][1005], used[1005][1005];
char a[1005][1005];

void dfs(int x, int y)
{
    used[x][y] = 1;

    if(dp[x][y] > 1e8)
    {
        cout << "Poor Inna!";
        exit(0);
    }

    dp[x][y] = 1e9;
    int ans = (a[x][y] == 'A');

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for(int z = 0; z < 4; z++)
    {
        int x2 = x + dx[z];
        int y2 = y + dy[z];

        if(x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && (a[x][y] == 'D' && a[x2][y2] == 'I' || a[x][y] == 'I' && a[x2][y2] == 'M' || a[x][y] == 'M' && a[x2][y2] == 'A' || a[x][y] == 'A' && a[x2][y2] == 'D'))
        {
            if(used[x2][y2] == 0)
                dfs(x2, y2);

            ans = max(ans, dp[x2][y2] + (a[x][y] == 'A'));
        }
    }

    dp[x][y] = ans;
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

    int ans = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(used[i][j] == 0)
            {
                dfs(i, j);
                ans = max(ans, dp[i][j] - 1 + (a[i][j] == 'D'));
            }
        }

    if(ans > 1e8)
    {
        cout << "Poor Inna!";
        exit(0);
    }

    if(ans == 0)
        cout << "Poor Dima!";
    else cout << ans;
}