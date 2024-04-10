#include <bits/stdc++.h>
//#define int long long
#define x first
#define y second

using namespace std;

int t, n, a[2005], px[2005], dp[2005];

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

        px[0] = 0;

        for(int i = 0; i < n; i++)
            px[i + 1] = (px[i] ^ a[i]);

        if(px[n] == 0)
            cout << "YES\n";
        else
        {
            dp[0] = 1;

            for(int i = 1; i <= n; i++)
            {
                dp[i] = 0;

                int y = 0;

                if(i == n)
                    y = 1;

                for(int j = y; j < i; j++)
                    if(dp[j] == 1 && ((px[i] ^ px[j]) == px[n]))
                        dp[i] = 1;
            }

            if(dp[n])
                cout << "YES\n";
            else cout << "NO\n";
        }
    }
}