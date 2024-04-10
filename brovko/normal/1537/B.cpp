#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;

int t, n, m, i, j;

int dist(int x, int y, int x2, int y2)
{
    return abs(i - x) + abs(x - x2) + abs(x2 - i) + abs(j - y) + abs(y - y2) + abs(y2 - j);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {

        cin >> n >> m >> i >> j;

        int v = 0, Max = -1;

        if(dist(1, 1, 1, m) > Max)
        {
            v = 3;
            Max = dist(1, 1, 1, m);
        }

        if(dist(1, 1, n, m) > Max)
        {
            v = 5;
            Max = dist(1, 1, n, m);
        }

        if(dist(1, 1, n, 1) > Max)
        {
            v = 9;
            Max = dist(1, 1, n, 1);
        }

        if(dist(1, m, n, m) > Max)
        {
            v = 6;
            Max = dist(1, m, n, m);
        }

        if(dist(1, m, n, 1) > Max)
        {
            v = 10;
            Max = dist(1, m, n, 1);
        }

        if(dist(n, m, n, 1) > Max)
        {
            v = 12;
            Max = dist(n, m, n, 1);
        }

        if(v & 1)
            cout << 1 << ' ' << 1 << ' ';

        if(v & 2)
            cout << 1 << ' ' << m << ' ';

        if(v & 4)
            cout << n << ' ' << m << ' ';

        if(v & 8)
            cout << n << ' ' << 1 << ' ';
    }
}