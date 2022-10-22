#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, k, a[100005];

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

        int ans = -1e18;

        for(int i = max(0ll, n - 1000); i < n; i++)
            for(int j = max(0ll, n - 1000); j < n; j++)
                if(i < j)
                    ans = max(ans, (i + 1) * (j + 1) - k * (a[i] | a[j]));

        cout << ans << "\n";
    }
}