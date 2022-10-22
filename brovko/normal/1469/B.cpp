#include <bits/stdc++.h>
#define ld long double
#define int long long

using namespace std;

int t, n, m, r[105], b[105], pr[105], pb[105];

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
            cin >> r[i];

        cin >> m;
        for(int i = 0; i < m; i++)
            cin >> b[i];

        pr[0] = 0;
        for(int i = 0; i < n; i++)
            pr[i + 1] = pr[i] + r[i];

        pb[0] = 0;
        for(int i = 0; i < m; i++)
            pb[i + 1] = pb[i] + b[i];

        int ans = 0;

        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                ans = max(ans, pr[i] + pb[j]);

        cout << ans << "\n";
    }
}