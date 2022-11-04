#include <bits/stdc++.h>

using namespace std;

long long a[(int)2e5 + 10], b[(int)2e5 + 10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long x, y;
    int n, m, k;
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> b[j];
    }
    if (n <= k || m <= k)
    {
        cout << -1 << endl;
        return 0;
    }
    long long ans = 0;
    for (int i = 0; i <= k; i++)
    {
        int q = lower_bound(b, b + m, a[i] + x) - b;
        if (q + (k - i) >= m)
        {
            //cout << i << " " << q << endl;
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, b[q + k - i] + y);
    }
    cout << ans << endl;
    return 0;
}