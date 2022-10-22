#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, k, a[105][105], ps[105][105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
            ps[i + 1][j] = ps[i][j] + a[i][j];
    }

    int s = 0;
    int x = 0;

    for(int j = 0; j < m; j++)
    {
        int y = 0;

        for(int i = 0; i <= n - k; i++)
            if(ps[i + k][j] - ps[i][j] > ps[y + k][j] - ps[y][j])
                y = i;

        for(int i = 0; i < y; i++)
            x += a[i][j];

        s += ps[y + k][j] - ps[y][j];
    }

    cout << s << ' ' << x;
}