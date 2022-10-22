#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair

using namespace std;

int t, n, m, a[300005], b[300005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < m; i++)
            cin >> b[i];

        sort(a, a + n);

        int ans = 0;

        for(int i = 1; i <= n; i++)
            ans += b[min(a[n - i], i) - 1];

        cout << ans << "\n";
    }
}