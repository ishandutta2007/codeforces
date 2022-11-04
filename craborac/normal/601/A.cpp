#include <bits/stdc++.h>

using namespace std;

int dist1[1300], dist2[1300], used1[1300], used2[1300];
int mas[1300][1300];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            mas[i][j] = 0;
        used1[i] = 0;
        used2[i] = 0;
        dist1[i] = 1300;
        dist2[i] = 1300;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        mas[a][b] = 1;
        mas[b][a] = 1;
    }
    dist1[0] = 0;
    dist2[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, v = -1, d1 = 1300, d2 = 1300;
        for (int j = 0; j < n; j++)
        {
            if (used1[j] == 0 && dist1[j] < d1)
            {
                u = j;
                d1 = dist1[j];
            }
            if (used2[j] == 0 && dist2[j] < d2)
            {
                v = j;
                d2 = dist2[j];
            }
        }
        if (u >= 0)
        {
            used1[u] = 1;
            for (int j = 0; j < n; j++)
                if (mas[u][j] == 1)
                    dist1[j] = min(dist1[u] + 1, dist1[j]);
        }
        if (v >= 0)
        {
            used2[v] = 1;
            for (int j = 0; j < n; j++)
                if (mas[v][j] == 0)
                    dist2[j] = min(dist2[v] + 1, dist2[j]);
        }
    }
    int a = max(dist1[n - 1], dist2[n - 1]);
    if (a == 1300)
        a = -1;
    cout << a << endl;
    return 0;
}