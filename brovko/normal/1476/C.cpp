#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, n, c[100005], a[100005], b[100005];

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
            cin >> c[i];

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        int ans = 0, s = c[n - 1];

        for(int i = n - 2; i >= 0; i--)
        {
            ans = max(ans, abs(a[i + 1] - b[i + 1]) + 1 + s);

            if(a[i + 1] == b[i + 1])
                s = c[i];
            else s = max(c[i], s + c[i] - abs(a[i + 1] - b[i + 1]) + 1);
        }

        cout << ans << "\n";
    }
}