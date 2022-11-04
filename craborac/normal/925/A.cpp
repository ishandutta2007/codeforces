#include <bits/stdc++.h>

using namespace std;

int a[(int)1e5 + 10], b[(int)1e5 + 10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x, y, n, m, v;
    cin >> x >> y >> n >> m >> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y2 < y1)
            swap(y1, y2);
        int c = lower_bound(a, a + n, y1) - a;
        int ans = (int)1e9;
        if (x1 == x2)
            ans = abs(y2 - y1);
        if (c < n)
            ans = min(ans, abs(a[c] - y1) + abs(a[c] - y2) + abs(x1 - x2));
        if (c > 0)
        {
            c--;
            ans = min(ans, abs(a[c] - y1) + abs(a[c] - y2) + abs(x1 - x2));
        }
        c = lower_bound(b, b + m, y2) - b;
        if (c < m)
        {
            ans = min(ans, abs(b[c] - y1) + abs(b[c] - y2) + (abs(x1 - x2) + v - 1) / v);
        }
        if (c > 0)
        {
            c--;
            ans = min(ans, abs(b[c] - y1) + abs(b[c] - y2) + (abs(x1 - x2) + v - 1) / v);
        }
        cout << ans << "\n";
    }
    return 0;
}