#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n;
char a[55][55], b[55][55], used[105][105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            b[i][j] = '.';

    for(int i = 1; i < 2 * n; i++)
        for(int j = 1; j < 2 * n; j++)
        {
            if(i == n && j == n)
            {
                used[i][j] = 'o';
                continue;
            }

            int dx = i - n, dy = j - n; // x = i, y = j
            int F = 1;

            for(int x = 0; x < n; x++)
                for(int y = 0; y < n; y++)
                {
                    if(a[x][y] == 'o' && x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < n && a[x + dx][y + dy] == '.')
                        F = 0;
                }

            if(F == 0)
                used[i][j] = '.';
            else
            {
                used[i][j] = 'x';

                for(int x = 0; x < n; x++)
                    for(int y = 0; y < n; y++)
                    {
                        if(a[x][y] == 'o' && x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < n)
                            b[x + dx][y + dy] = 'x';
                    }
            }
        }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] == 'x' && b[i][j] == '.')
            {
                cout << "NO";
                return 0;
            }

    cout << "YES\n";

    for(int i = 1; i < 2 * n; i++)
    {
        for(int j = 1; j < 2 * n; j++)
            cout << used[i][j];

        cout << "\n";
    }
}