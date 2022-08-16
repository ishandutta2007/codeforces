#include <iostream>

using namespace std;

char a[1005][1005] = {0};
int comp[1005][1005] = {0}, pics[1000005] = {0};

void bfs(int x, int y, int n, int m, int c)
{
    if (x < 1 or x > n or y < 1 or y > m or comp[x][y])
        return;

    if (a[x][y] == '*')
    {
        ++pics[c];
        return;
    }

    comp[x][y] = c;

    bfs(x-1, y, n, m, c);
    bfs(x+1, y, n, m, c);
    bfs(x, y-1, n, m, c);
    bfs(x, y+1, n, m, c);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    int c = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == '.' and !comp[i][j])
            {
                bfs(i, j, n, m, c);
                ++c;
            }
        }
    }

    while (k--)
    {
        int x, y;
        cin >> x >> y;
        cout << pics[comp[x][y]] << '\n';
    }

    return 0;
}