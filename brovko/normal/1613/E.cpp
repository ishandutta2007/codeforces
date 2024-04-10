#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, m;

bool isin(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool good(int x, int y, char** a, int** used)
{
    int k = 0, dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0};

    for(int i = 0; i < 4; i++)
        if(isin(x + dx[i], y + dy[i]) && used[x + dx[i]][y + dy[i]] == 0 && a[x + dx[i]][y + dy[i]] == '.')
            k++;

    return (k <= 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        char** a = new char* [n];

        for(int i = 0; i < n; i++)
            a[i] = new char [m];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];

        int** used = new int* [n];

        for(int i = 0; i < n; i++)
            used[i] = new int [m];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                used[i][j] = 0;

        queue <pair <int, int> > q;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(a[i][j] == 'L')
                {
                    used[i][j] = 1;
                    q.push({i, j});
                }

        while(!q.empty())
        {
            pair <int, int> p = q.front();
            q.pop();

            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};

            for(int i = 0; i < 4; i++)
            {
                int x2 = p.x + dx[i];
                int y2 = p.y + dy[i];

                if(isin(x2, y2) && used[x2][y2] == 0 && a[x2][y2] == '.' && good(x2, y2, a, used))
                {
                    used[x2][y2] = 1;
                    q.push({x2, y2});
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                if(a[i][j] == '.' && used[i][j])
                    cout << '+';
                else cout << a[i][j];

            cout << "\n";
        }
    }
}