#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

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
        int n, m;
        cin >> n >> m;

        int a[n][m];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];

        int Max = -1e9;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                Max = max(Max, a[i][j]);

        int ans = -1;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(a[i][j] == Max)
                    ans = max(i + 1, n - i) * max(j + 1, m - j);

        cout << ans << "\n";
    }
}