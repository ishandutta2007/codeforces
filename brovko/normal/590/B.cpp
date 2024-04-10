#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int X1, Y1, X2, Y2, t, vmax, vx, vy, wx, wy;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> X1 >> Y1 >> X2 >> Y2 >> vmax >> t >> vx >> vy >> wx >> wy;

    ld L = 0, R = 1e18;

    while(R - L > 1e-9)
    {
        ld M = (L + R) / 2;
        ld x = 0, y = 0;

        if(M > t)
        {
            x = vx * t + wx * (M - t);
            y = vy * t + wy * (M - t);
        }
        else
        {
            x = vx * M;
            y = vy * M;
        }

        if((X1 + x - X2) * (X1 + x - X2) + (Y1 + y - Y2) * (Y1 + y - Y2) <= (vmax * M) * (vmax * M))
            R = M;
        else L = M;
    }

    cout << setprecision(20) << R;
}