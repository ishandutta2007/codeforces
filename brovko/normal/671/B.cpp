#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, k, a[500005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int x = k;

    int l = a[0], r = a[n - 1];

    for(int i = 1; i < n; i++)
    {
        if((a[i] - l) * i <= x)
        {
            x -= (a[i] - l) * i;
            l = a[i];
        }
        else
        {
            l += x / i;
            x = 0;
        }
    }

    x = k;

    for(int i = n - 2; i >= 0; i--)
    {
        if((r - a[i]) * (n - 1 - i) <= x)
        {
            x -= (r - a[i]) * (n - 1 - i);
            r = a[i];
        }
        else
        {
            r -= x / (n - i - 1);
            x = 0;
        }
    }

    int s = 0;

    for(int i = 0; i < n; i++)
        s += a[i];

    cout << max((int)(s % n != 0), r - l);
}