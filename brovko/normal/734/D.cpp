#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, x, y, a[500005], b[500005], f[8];
char c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 8; i++)
        f[i] = -9e18;

    cin >> n >> x >> y;

    for(int i = 0; i < n; i++)
    {
        cin >> c >> a[i] >> b[i];

        if(a[i] == x && b[i] > y && abs(b[i] - y) < abs(f[0]))
        {
            f[0] = abs(b[i] - y);
            if(c == 'B')
                f[0] = -f[0];
        }

        if(a[i] == x && b[i] < y && abs(y - b[i]) < abs(f[1]))
        {
            f[1] = abs(y - b[i]);
            if(c == 'B')
                f[1] = -f[1];
        }

        if(b[i] == y && a[i] > x && abs(a[i] - x) < abs(f[2]))
        {
            f[2] = abs(a[i] - x);
            if(c == 'B')
                f[2] = -f[2];
        }

        if(b[i] == y && a[i] < x && abs(x - a[i]) < abs(f[3]))
        {
            f[3] = abs(x - a[i]);
            if(c == 'B')
                f[3] = -f[3];
        }

        if(b[i] - y == a[i] - x && a[i] > x && abs(a[i] - x) < abs(f[4]))
        {
            f[4] = abs(a[i] - x);
            if(c == 'R')
                f[4] = -f[4];
        }

        if(b[i] - y == a[i] - x && a[i] < x && abs(x - a[i]) < abs(f[5]))
        {
            f[5] = abs(x - a[i]);
            if(c == 'R')
                f[5] = -f[5];
        }

        if(b[i] - y == x - a[i] && a[i] > x && abs(a[i] - x) < abs(f[6]))
        {
            f[6] = abs(a[i] - x);
            if(c == 'R')
                f[6] = -f[6];
        }

        if(b[i] - y == x - a[i] && a[i] < x && abs(x - a[i]) < abs(f[7]))
        {
            f[7] = abs(x - a[i]);
            if(c == 'R')
                f[7] = -f[7];
        }
    }

    for(int i = 0; i < 8; i++)
    {
        if(f[i] >= 0)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}