#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int t, l, r, m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> l >> r >> m;

        int f = 0;

        for(int a = l; a <= r; a++)
        {
            int n = max(1ll, m / a);

            int d = m - n * a;

            if(d <= r - l && d >= l - r && f == 0)
            {
                f = 1;

                int b;

                if(d > 0)
                    b = r;
                else b = l;

                int c = b - d;

                cout << a << ' ' << b << ' ' << c << "\n";
            }

            n++;
            d -= a;

            if(d <= r - l && d >= l - r && f == 0)
            {
                f = 1;

                int b;

                if(d > 0)
                    b = r;
                else b = l;

                int c = b - d;

                cout << a << ' ' << b << ' ' << c << "\n";
            }
        }
    }
}