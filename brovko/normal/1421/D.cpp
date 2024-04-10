#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, x, y, c1, c2, c3, c4, c5, c6;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> x >> y >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
        swap(x, y);

        int X = 0, Y = y - x, Z = 0;

        if(x >= 0)
            Z = c1 * x;
        else Z = c4 * -x;

        if(Y >= 0)
            Z += c6 * Y;
        else Z += c3 * -Y;

        int ans = Z;

        X = x - y, Y = 0, Z = 0;

        if(y >= 0)
            Z = c1 * y;
        else Z = c4 * -y;

        if(X >= 0)
            Z += c2 * X;
        else Z += c5 * -X;

        ans = min(ans, Z);

        Z = 0;

        if(x >= 0)
            Z += c2 * x;
        else Z += c5 * -x;

        if(y >= 0)
            Z += c6 * y;
        else Z += c3 * -y;

        ans = min(ans, Z);
        cout << ans << "\n";
    }
}