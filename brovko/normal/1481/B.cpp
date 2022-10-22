#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, k, a[105];

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

        int ans = 0;

        while(k > 0)
        {
            int x = -1;

            for(int i = 1; i < n; i++)
                if(a[i] > a[i - 1] && x == -1)
                    x = i;

            if(x == -1)
            {
                k = 0;
                ans = -1;
            }
            else
            {
                int y = 1;
                a[x - 1] += y;
                k -= y;

                if(k <= 0)
                    ans = x;
            }
        }

        cout << ans << "\n";
    }
}