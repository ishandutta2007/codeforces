#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int x[3], y[3];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];

    int ans = 3;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
    {
        if(i != j && j != k && i != k)
        {
            if(x[i] == x[j] && x[i] == x[k])
                ans = 1;

            if(y[i] == y[j] && y[i] == y[k])
                ans = 1;

            if(y[j] == y[k] && x[i] <= x[j] && x[i] <= x[k])
                ans = min(ans, 2ll);

            if(y[j] == y[k] && x[i] >= x[j] && x[i] >= x[k])
                ans = min(ans, 2ll);

            if(x[j] == x[k] && y[i] <= y[j] && y[i] <= y[k])
                ans = min(ans, 2ll);

            if(x[j] == x[k] && y[i] >= y[j] && y[i] >= y[k])
                ans = min(ans, 2ll);
        }
    }

    cout << ans;
}