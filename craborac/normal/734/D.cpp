#include <bits/stdc++.h>

using namespace std;

int mn[8];
char a[8];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int x, y;
    cin >> n >> x >> y;
    fill(mn, mn + 8, (int)2e9 + 1);
    fill(a, a + 4, 'B');
    fill(a + 4, a + 8, 'R');
    for (int i = 0; i < n; i++)
    {
        char c;
        int q, w;
        cin >> c >> q >> w;
        if (q == x)
        {
            if (w > y)
            {
                if (w - y < mn[0])
                {
                    mn[0] = w - y;
                    a[0] = c;
                }
            }
            else
            {
                if (y - w < mn[1])
                {
                    mn[1] = y - w;
                    a[1] = c;
                }
            }
        }
        else if (w == y)
        {
            if (q > x)
            {
                if (q - x < mn[2])
                {
                    mn[2] = q - x;
                    a[2] = c;
                }
            }
            else
            {
                if (x - q < mn[3])
                {
                    mn[3] = x - q;
                    a[3] = c;
                }
            }
        }
        else if (q - x == w - y)
        {
            if (q > x)
            {
                if (q - x < mn[4])
                {
                    mn[4] = q - x;
                    a[4] = c;
                }
            }
            else
            {
                if (x - q < mn[5])
                {
                    mn[5] = x - q;
                    a[5] = c;
                }
            }
        }
        else if (q - x == y - w)
        {
            if (q > x)
            {
                if (q - x < mn[6])
                {
                    mn[6] = q - x;
                    a[6] = c;
                }
            }
            else
            {
                if (x - q < mn[7])
                {
                    mn[7] = x - q;
                    a[7] = c;
                }
            }
        }
    }
    if (a[0] != 'B' || a[1] != 'B' || a[2] != 'B' || a[3] != 'B' || a[4] != 'R' || a[5] != 'R' || a[6] != 'R' || a[7] != 'R')
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}