#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 7;
int n, m, q;
int a[N][N];
int w[N][N];
int c[N][N];
int sol[N * N];

int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};

bool valid(int r, int c)
{
        return (1 <= r && 1 <= c && r <= n && c <= m);
}

void dfs(int i, int j, int now)
{
        sol[now] += w[i][j];
        c[i][j] = now;
        for (int k = 0; k < 4; k++)
        {
                int ni = i + dr[k], nj = j + dc[k];
                if (valid(ni, nj) && c[ni][nj] == -1 && a[ni][nj] == 0)
                        dfs(ni, nj, now);
        }
}

int main()
{
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        /// freopen ("input", "r", stdin);

        cin >> n >> m >> q;

        for (int i = 1; i <= n; i++)
        {
                string s;
                cin >> s;
                for (int j = 1; j <= m; j++)
                        if (s[j - 1] == '*')
                                a[i][j] = 1;
                        else
                                a[i][j] = 0;
        }

        for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                        if (a[i][j] == 0)
                        {
                                for (int k = 0; k <= 3; k++)
                                {
                                        int ni = i + dr[k], nj = j + dc[k];
                                        if (valid(ni, nj) && a[ni][nj])
                                                w[i][j]++;
                                }
                        }

        for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                        c[i][j] = -1;

        int now = 0;
        for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                        if (a[i][j] == 0 && c[i][j] == -1)
                        {
                                now++;
                                dfs(i, j, now);
                        }

        while (q--)
        {
                int i, j;
                cin >> i >> j;
                cout << sol[c[i][j]] << "\n";
        }

}