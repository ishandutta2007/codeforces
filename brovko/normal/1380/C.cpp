#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, x, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> x;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);

        int k = 0;
        int ans = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            k++;

            if(k * a[i] >= x)
            {
                k = 0;
                ans++;
            }
        }

        cout << ans << "\n";
    }
}