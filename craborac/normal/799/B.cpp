#include <bits/stdc++.h>
#define android ios

using namespace std;

int p[(int)2e5 + 10], a[(int)2e5 + 10], b[(int)2e5 + 10];
vector<int> mas[4][4];
int w[4][4];

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        mas[a[i]][b[i]].push_back(p[i]);
    }
    for (int i = 1; i < 4; i++)
        for (int j = 1; j < 4; j++)
            sort(mas[i][j].begin(), mas[i][j].end());
    int m;
    cin >> m;
    for (int q = 0; q < m; q++)
    {
        int c;
        cin >> c;
        long long d = (int)1e9 + 1;
        int x = -1, y = -1;
        for (int i = 1; i < 4; i++)
        {
            if (w[i][c] < mas[i][c].size() && mas[i][c][w[i][c]] < d)
            {
                d = mas[i][c][w[i][c]];
                x = i;
                y = c;
            }
        }
        for (int i = 1; i < 4; i++)
        {
            if (w[c][i] < mas[c][i].size() && mas[c][i][w[c][i]] < d)
            {
                d = mas[c][i][w[c][i]];
                x = c;
                y = i;
            }
        }
        if (d > (int)1e9)
            d = -1;
        cout << d << " ";
        if (x != -1)
            w[x][y]++;
    }
    return 0;
}