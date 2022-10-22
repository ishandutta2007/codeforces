#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, k[105], h[105];

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
            cin >> k[i];

        for(int i = 0; i < n; i++)
            cin >> h[i];

        int ans = 0, H = 0;

        for(int i = n - 1; i >= 0;)
        {
            H = h[i];
            int j = i;

            while(j >= 0 && H - k[i] + k[j] > 0)
            {
                H = max(H, h[j] + k[i] - k[j]);
                j--;
            }

            i = j;
            ans += H * (H + 1) / 2;
        }

        cout << ans << "\n";
    }
}