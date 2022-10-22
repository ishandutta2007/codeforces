#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, h, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> h;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int L = 0, R = 2e18;

        while(R - L > 1)
        {
            int M = (L + R) / 2;
            int r = 0, d = 0;

            for(int i = 0; i < n; i++)
            {
                d += a[i] + M - max(a[i], r);
                r = a[i] + M;
            }

            if(d >= h)
                R = M;
            else L = M;
        }

        cout << R << "\n";
    }
}