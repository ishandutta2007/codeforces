#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 goerohgerigegoihr
#define y0 peowjfefwepojfewe

using namespace std;

int t, n, a[10005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int s = 0;

        for(int i = 0; i < n; i++)
            s += a[i];

        int x = s / n;

        if(s % n)
            cout << "-1\n";
        else
        {
            cout << 3 * n - 3 << "\n";

            for(int i = 1; i < n; i++)
            {
                int y = ((i + 1) - (a[i] % (i + 1))) % (i + 1);

                cout << "1 " << i + 1 << ' ' << y << "\n";
                cout << i + 1 << ' ' << "1 " << (a[i] + y) / (i + 1) << "\n";
            }

            for(int i = 1; i < n; i++)
                cout << "1 " << i + 1 << ' ' << x << "\n";
        }
    }
}