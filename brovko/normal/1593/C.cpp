#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, k, a[400005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        for(int i = 0; i < k; i++)
            cin >> a[i];

        sort(a, a + k);

        int s = 0, ans = 0;

        for(int i = k - 1; i >= 0; i--)
        {
            s += n - a[i];

            if(s < n)
                ans++;
        }

        cout << ans << "\n";
    }
}