#include <bits/stdc++.h>

using namespace std;

long long a[(int)1e5 + 10], mn[(int)1e5 + 10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    int n;
    cin >> n;
    mn[0] = 1;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i)
        {
            mn[i] = max(mn[i - 1], a[i] + 1);
        }
    }
    for (int i = n - 1; i > 0; i--)
    {
        mn[i - 1] = max(mn[i - 1], mn[i] - 1);
    }
    for (int i = 0; i < n; i++)
    {
        ans += mn[i] - a[i] - 1;
    }
    cout << ans << endl;
    return 0;
}