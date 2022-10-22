#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, x[1005], y[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x[0] >> y[0] >> x[1] >> y[1];

    int d;

    if(x[1] > x[0])
        d = 1;

    if(y[1] < y[0])
        d = 2;

    if(x[1] < x[0])
        d = 3;

    if(y[1] > y[0])
        d = 4;

    int ans = 0;

    for(int i = 2; i <= n + 1; i++)
    {
        if(i <= n)
            cin >> x[i] >> y[i];
        else
        {
            x[i] = x[1];
            y[i] = y[1];
        }

        int p;

        if(x[i] > x[i - 1])
            p = 1;

        if(y[i] < y[i - 1])
            p = 2;

        if(x[i] < x[i - 1])
            p = 3;

        if(y[i] > y[i - 1])
            p = 4;

        if(d == p % 4 + 1)
            ans++;

        d = p;
    }

    cout << ans;
}