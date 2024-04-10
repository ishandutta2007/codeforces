#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[105];

int f(int x, int k1, int k2)
{
    int ans = 1e9;

    for(int i = 0; i <= k1; i++)
        for(int j = 0; j <= k2; j++)
        {
            int k = (x - i - 2 * j) / 3;

            if(i + 2 * j + 3 * k == x && k >= 0)
                ans = min(ans, k);
        }

    return ans;
}

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

        int ans2 = 1e9;

        for(int k1 = 0; k1 <= 10; k1++)
            for(int k2 = 0; k2 <= 10; k2++)
            {
                int ans = 0;

                for(int i = 0; i < n; i++)
                    ans = max(ans, f(a[i], k1, k2));

                ans2 = min(ans2, k1 + k2 + ans);
            }

        cout << ans2 << "\n";
    }
}