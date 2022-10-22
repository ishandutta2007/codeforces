#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, m, a[35][35], k0[105], k1[105];

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
            for(int j = 0; j < m; j++)
                cin >> a[i][j];

        for(int i = 0; i < 105; i++)
        {
            k0[i] = 0;
            k1[i] = 0;
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
        {
            if(a[i][j] == 0)
                k0[i + j]++;
            else k1[i + j]++;
        }

        int ans = 0;

        for(int i = 0; i < (n + m - 1) / 2; i++)
            ans += min(k0[i] + k0[n + m - 2 - i], k1[i] + k1[n + m - 2 - i]);

        cout << ans << "\n";
    }
}