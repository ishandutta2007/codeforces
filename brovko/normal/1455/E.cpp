#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, x[4], y[4], x1, x2, x3, x4, y1, y2, y3, y4;

ll f(int c)
{
    if(c < 0)
        return 1e18;

    vector <int> v = {x1, x2 - c, x3 - c, x4};
    vector <int> u = {y1, y2, y3 - c, y4 - c};

    sort(v.begin(), v.end());
    sort(u.begin(), u.end());

    return 1ll * (- v[0]) + v[2] + v[3] - v[1] - u[0] + u[2] + u[3] - u[1];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        ll ans = 1e18;

        for(int i = 0; i < 4; i++)
            cin >> x[i] >> y[i];

        for(int i1 = 0; i1 < 4; i1++)
        for(int i2 = 0; i2 < 4; i2++)
        for(int i3 = 0; i3 < 4; i3++)
        for(int i4 = 0; i4 < 4; i4++)
        if((1 << i1) + (1 << i2) + (1 << i3) + (1 << i4) == 15)
        {

            x1 = x[i1];
            y1 = y[i1];

            x2 = x[i2];
            y2 = y[i2];

            x3 = x[i3];
            y3 = y[i3];

            x4 = x[i4];
            y4 = y[i4];

//                int L = 0, R = 1e9;
//
//                while(R - L > 1)
//                {
//                    int M = (L + R) / 2;
//
//                    if(f(M) < f(M + 1))
//                        R = M;
//                    else L = M;
//                }
//
//                ans = min(ans, min(f(L), f(R)));

                ans = min({ans, f(x2 - x1), f(x2 - x4), f(x3 - x1), f(x3 - x4), f(y3 - y1), f(y3 - y2), f(y4 - y1), f(y4 - y2)});
        }

        cout << ans << "\n";
    }
}