#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t, n, m;
char a[105][105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        int ans = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                {
                    cin >> a[i][j];

                    if(i == n - 1 && a[i][j] == 'D')
                        ans++;

                    if(j == m - 1 && a[i][j] == 'R')
                        ans++;
                }

        cout << ans << "\n";
    }
}