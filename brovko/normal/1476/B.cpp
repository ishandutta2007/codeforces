#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, n, k, p[105];

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
            cin >> p[i];

        int s = p[0], ans = 0;

        for(int i = 1; i < n; i++)
        {
            ans = max(ans, (p[i] * 100 + k - 1) / k - s);
            s += p[i];
        }

        cout << ans << "\n";
    }
}