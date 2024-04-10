#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <int> ps(n + 1);

        for(int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + a[i];

        if(k <= n)
        {
            int ans = 0;

            for(int i = k; i <= n; i++)
                ans = max(ans, ps[i] - ps[i - k]);

            cout << ans + k * (k - 1) / 2 << "\n";
        }
        else
        {
            int ans = 0;

            for(int i = 0; i < n; i++)
                ans += a[i];

            ans += (k - 1 + k - n) * n / 2;

            cout << ans << "\n";
        }
    }
}