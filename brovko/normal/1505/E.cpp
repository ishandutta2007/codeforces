#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
char a[5][5];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    int x = 0, y = 0, ans = 0;

    while(x < n || y < m)
    {
        if(a[x][y] == '*')
            ans++;

        int u = n, v = m;

        for(int i = x; i < n; i++)
            for(int j = y; j < m; j++)
                if(a[i][j] == '*' && make_pair(i + j - x - y, i - x) < make_pair(u + v - x - y, u - x) && i + j > x + y)
                {
                    u = i;
                    v = j;
                }

        x = u;
        y = v;
    }

    cout << ans;
}