#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int x = 0;
    while(a[x] == 0)
        x++;

    int Max = 0;
    for(int i = 0; i < n; i++)
        Max = max(Max, a[i]);

    if(Max >= k)
    {
        cout << 0;
        return 0;
    }

    if(n - x == 2)
    {
        cout << (k - a[n - 1] + a[n - 2] - 1) / a[n - 2];
        return 0;
    }

    if(n - x == 3)
    {
        int L = 0;
        int R = 1e18;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            ld x = a[n - 1];
            x += (ld)a[n - 2] * M;
            x += (ld)a[n - 3] * M * (M + 1) / 2;

            if(x >= k)
                R = M;
            else L = M;
        }

        cout << R;
        return 0;
    }

    for(int j = 1; j <= 1e9; j++)
    {
        for(int i = x + 1; i < n; i++)
        {
            a[i] += a[i - 1];
            if(a[i] >= k)
            {
                cout << j;
                return 0;
            }
        }
    }
}