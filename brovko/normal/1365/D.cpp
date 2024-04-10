#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, m, used[55][55];
char a[55][55];

void dfs(int i, int j)
{
    if(a[i][j] == '#')
        return;

    used[i][j] = 1;

    if(i > 0 && used[i - 1][j] == 0 && a[i - 1][j] != '#')
        dfs(i - 1, j);

    if(i < n - 1 && used[i + 1][j] == 0 && a[i + 1][j] != '#')
        dfs(i + 1, j);

    if(j > 0 && used[i][j - 1] == 0 && a[i][j - 1] != '#')
        dfs(i, j - 1);

    if(j < m - 1 && used[i][j + 1] == 0 && a[i][j + 1] != '#')
        dfs(i, j + 1);
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
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin >> a[i][j];

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(a[i][j] == 'B')
            {
                if(i > 0 && a[i - 1][j] == '.')
                    a[i - 1][j] = '#';
                if(i < n - 1 && a[i + 1][j] == '.')
                    a[i + 1][j] = '#';

                if(j > 0 && a[i][j - 1] == '.')
                    a[i][j - 1] = '#';
                if(j < m - 1 && a[i][j + 1] == '.')
                    a[i][j + 1] = '#';
            }

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                used[i][j] = 0;

        dfs(n - 1, m - 1);
        int f = 1;

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(a[i][j] == 'G' && used[i][j] == 0)
                    f = 0;
                if(a[i][j] == 'B' && used[i][j] == 1)
                    f = 0;
            }

        if(f)
            cout << "Yes\n";
        else cout << "No\n";
    }
}