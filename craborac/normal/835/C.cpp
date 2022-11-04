#include <bits/stdc++.h>
#define android ios

using namespace std;

long long a[101][101][11];

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, c;
    cin >> n >> m >> c;
    c++;
    for (int i = 0; i < n; i++)
    {
        int x, y, q;
        cin >> x >> y >> q;
        a[x][y][q]++;
    }
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            for (int q = 0; q < c; q++)
            {
                a[i][j][q] += a[i - 1][j][q] + a[i][j - 1][q] - a[i - 1][j - 1][q];
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int t, x1, x2, y1, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        long long ans = 0;
        for (int j = 0; j < c; j++)
        {
            ans += (a[x2][y2][j] - a[x2][y1][j] - a[x1][y2][j] + a[x1][y1][j]) * ((j + t) % c);
        }
        cout << ans << "\n";
    }
    return 0;
}