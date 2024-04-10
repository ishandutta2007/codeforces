#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

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

        int k = 0;

        for(int i = 0; i < n; i++)
            if(a[i] % 2 == 0)
                k++;

        int ans = 1e18;

        if(k * 2 == n || k * 2 == n - 1)
        {
            int x = 0, y = 1;

            for(int i = 0; i < n; i++)
                if(a[i] % 2 == 0)
                {
                    x += abs(i - y);
                    y += 2;
                }

            ans = min(ans, x);
        }

        k = n - k;

        if(k * 2 == n || k * 2 == n - 1)
        {
            int x = 0, y = 1;

            for(int i = 0; i < n; i++)
                if(a[i] % 2)
                {
                    x += abs(i - y);
                    y += 2;
                }

            ans = min(ans, x);
        }

        if(ans == 1e18)
            cout << "-1\n";
        else cout << ans << "\n";
    }
}