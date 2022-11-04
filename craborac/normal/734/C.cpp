#include <bits/stdc++.h>

using namespace std;

long long a[(int)2e5 + 10];
long long b[(int)2e5 + 10];
long long c[(int)2e5 + 10];
long long d[(int)2e5 + 10];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    int m, k;
    cin >> n >> m >> k;
    long long x, s;
    cin >> x >> s;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < k; i++)
        cin >> c[i];
    for (int i = 0; i < k; i++)
        cin >> d[i];
    long long ans = n * x;
    for (int i = 0; i < k; i++)
    {
        if (s >= d[i])
            ans = min(ans, (n - c[i]) * x);
    }
    for (int i = 0; i < m; i++)
    {
        if (s >= b[i])
        {
            ans = min(ans, n * a[i]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (s >= b[i])
        {
            int l = -1, r = k;
            while (r - l > 1)
            {
                int mm = (l + r) / 2;
                if (d[mm] + b[i] <= s)
                    l = mm;
                else
                    r = mm;
            }
            if (l >= 0)
                n -= c[l];
            ans = min(ans, max(n, 0ll) * a[i]);
            if (l >= 0)
                n += c[l];
        }
    }
    cout << ans << endl;
    return 0;
}