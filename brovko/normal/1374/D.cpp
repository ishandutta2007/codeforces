#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

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

        map <int, int> m;

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(a[i] % k)
            {
                int x = k - a[i] % k;

                if(m[x])
                    x = m[x];

                ans = max(ans, x + 1);

                m[k - a[i] % k] = x + k;
            }
        }

        cout << ans << "\n";
    }
}