#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int mas[300][300], a[300][300];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == 'W')
            {
                mas[i][j] = 1;
            }
            else
            {
                mas[i][j] = -1;
            }
            a[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (a[i][j] != mas[i][j])
            {
                for (int q = 0; q <= i; q++)
                {
                    for (int w = 0; w <= j; w++)
                    {
                        a[q][w] += mas[i][j] - a[i][j];
                    }
                }
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}