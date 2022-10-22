#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    t = 1;

    while(t--)
    {
        int n, p;

        cin >> n >> p;

        int a[n];

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);

        int L = 0;

        for(int i = 0; i < n; i++)
            L = max(L, a[i] - i);

        int l = L;
        int R = 1e18;
        L--;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            int f = 0;

            int r = 0;

            for(int i = 0; i < n; i++)
            {
                while(r < n && M + i >= a[r])
                    r++;

                if(r - i >= p)
                    f = 1;
            }

            if(f)
                R = M;
            else L = M;
        }

        cout << R - l << "\n";

        for(int i = l; i < R; i++)
            cout << i << ' ';

        cout << "\n";
    }
}