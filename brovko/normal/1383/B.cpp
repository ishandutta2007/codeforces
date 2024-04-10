#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int t, n, a[100005];

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

        int x = 0;

        for(int i = 0; i < n; i++)
            x ^= a[i];

        if(x == 0)
            cout << "DRAW\n";
        else
        {
            int Max = 30;

            while(x < (1ll << Max))
                Max--;

            int k0 = 0, k1 = 0;

            for(int i = 0; i < n; i++)
            {
                if((a[i] & (1ll << Max)) > 0)
                    k1++;
                else k0++;
            }

            if(k1 % 4 == 1)
                {
                    cout << "WIN\n";
                }

            else
                {
                    if(k0 % 2)
                        cout << "WIN\n";
                    else cout << "LOSE\n";
                }
        }
    }
}