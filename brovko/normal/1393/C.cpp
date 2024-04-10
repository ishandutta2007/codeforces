#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t, n, a[100005], b[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        int Max = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[a[i]]++;

            Max = max(Max, b[a[i]]);
        }

        int k = 0;

        for(int i = 0; i < n; i++)
        {
            if(b[a[i]] != Max)
                k++;
        }

        int kMax = 0;

        for(int i = 0; i < n; i++)
        {
            if(b[a[i]] == Max)
            {
                b[a[i]] = 0;
                kMax++;
            }
        }

        cout << k / (Max - 1) + kMax - 1 << "\n";

        for(int i = 0; i < n; i++)
            b[a[i]] = 0;
    }
}