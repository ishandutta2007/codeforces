#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, a[200005], used[200005];

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

        sort(a, a + n);

        for(int i = 0; i < n; i++)
            if(used[a[i]])
                used[a[i] + 1] = 1;
            else used[a[i]] = 1;

        int ans = 0;

        for(int i = 0; i <= 2 * n + 1; i++)
            if(used[i])
                ans++;

        cout << ans << "\n";

        for(int i = 0; i <= 2 * n + 1; i++)
            used[i] = 0;
    }
}