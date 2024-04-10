#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n][m];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                char c;
                cin >> c;

                a[i][j] = c - '0';
            }

        int ans = -1e9;

        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++)
            {
                int k = a[i][j] + a[i][j - 1] + a[i - 1][j] + a[i - 1][j - 1];

                if(k > 0)
                {
                    k = max(1, k - 1);
                    ans = max(ans, -k);
                }
            }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ans += a[i][j];

        cout << (ans < -1e8 ? 0 : ans + 1) << "\n";
    }
}