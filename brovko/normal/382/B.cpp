#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int a, b, w, x, c, d[1005][60], up[1005][60];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> w >> x >> c;

    for(int i = 0; i < w; i++)
    {
        if(i >= x)
            up[i][0] = i - x;
        else
        {
            up[i][0] = w - (x - i);
            d[i][0] = 1;
        }
    }

    for(int j = 1; j < 60; j++)
        for(int i = 0; i < w; i++)
        {
            d[i][j] = d[i][j - 1] + d[up[i][j - 1]][j - 1];
            up[i][j] = up[up[i][j - 1]][j - 1];
        }

    int L = -1, R = 1e18;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        int i = b, ans = 0, m = M;

        for(int j = 59; j >= 0; j--)
            if(m >= (1ll << j))
            {
                m -= (1ll << j);
                ans += d[i][j];
                i = up[i][j];
            }

        if(c - M <= a - ans)
            R = M;
        else L = M;
    }

    cout << R;
}