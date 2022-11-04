#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

char mas[300][300];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mas[i][j];
        }
    }
    int col[300];
    for (int i = 0; i < 300; i++)
    {
        col[i] = 0;
    }
    int ans = 0;
    for (int i = 0; i + 1 < n; i++)
    {
        for (int j = 0; j + 1 < m; j++)
        {
            col[mas[i][j]]++;
            col[mas[i + 1][j]]++;
            col[mas[i][j + 1]]++;
            col[mas[i + 1][j + 1]]++;
            if (col['a'] == 1 && col['f'] == 1 && col['c'] == 1 && col['e'] == 1)
            {
                ans++;
            }
            for (int q = 0; q < 300; q++)
            {
                col[q] = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}