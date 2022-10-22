#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, n, w, a[100005];

int lg2(int x)
{
    if(x == 1)
        return 0;

    return 1 + lg2(x / 2);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> w;

        int b[30];

        for(int i = 0; i < 30; i++)
            b[i] = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[lg2(a[i])]++;
        }

        int ans = 0;

        while(n > 0)
        {
            ans++;
            int m = w;

            for(int i = 29; i >= 0; i--)
            {
                int k = min(b[i], m / (1ll << i));

                m -= k * (1ll << i);
                n -= k;
                b[i] -= k;
            }
        }

        cout << ans << "\n";
    }
}