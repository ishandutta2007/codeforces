#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, x, a[5005], s[5005], suf[5005];

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

        for(int i = 1; i <= n; i++)
            s[i] = -1e9;

        for(int i = 0; i < n; i++)
        {
            int s2 = 0;

            for(int j = i; j < n; j++)
            {
                s2 += a[j];
                s[j - i + 1] = max(s[j - i + 1], s2);
            }
        }

        suf[n] = s[n];

        for(int i = n - 1; i >= 1; i--)
            suf[i] = max(suf[i + 1], s[i]);

        int ans = max(0, suf[1]);
        cout << ans << ' ';

        for(int k = 1; k <= n; k++)
        {
            ans = max(ans, suf[k] + x * k);
            cout << ans << ' ';
        }

        cout << "\n";
    }
}