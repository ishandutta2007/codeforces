#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t, n, k, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        if(k% 2 == 0)
            k = 2;
        else k = 1;

        while(k--)
        {
            int Max = a[0];

            for(int i = 0; i < n; i++)
                Max = max(Max, a[i]);

            for(int i = 0; i < n; i++)
                a[i] = Max - a[i];
        }

        for(int i = 0; i < n; i++)
            cout << a[i] << ' ';

        cout << "\n";
    }
}