#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> mat[i][j];

    vector<int> h(n * m + 1);
    vector<int> v(n * m + 1);

    for (int i = 0; i < n; ++i)
    {
        int a = 0;
        for (int j = 0; j < m; ++j)
            a = max(a, mat[i][j]);
        h[a] = 1;
    }

    for (int i = 0; i < m; ++i)
    {
        int a = 0;
        for (int j = 0; j < n; ++j)
            a = max(a, mat[j][i]);
        v[a] = 1;
    }

    vector<vector<int>> fin(n, vector<int>(m));
    queue<pair<int, int>> q;

    int x = -1, y = -1;

    for (int u = n * m; u >= 1; --u)
    {
        x += h[u];
        y += v[u];

        if (h[u] || v[u])
        {
            fin[x][y] = u;
        }
        else
        {
            int qx, qy;
            tie(qx, qy) = q.front();
            q.pop();
            fin[qx][qy] = u;
        }

        if (h[u])
            for (int i = y - 1; i >= 0; --i)
                q.push({x, i});

        if (v[u])
            for (int i = x - 1; i >= 0; --i)
                q.push({i, y});
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cout << fin[i][j] << " \n"[j + 1 == m];

    return 0;
}