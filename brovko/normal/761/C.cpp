#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, d[55][3];
string s[55];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> s[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            d[i][j] = 1e9;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int x = min(j, m - j);

            if(s[i][j] >= '0' && s[i][j] <= '9')
                d[i][0] = min(d[i][0], x);
            else

            if(s[i][j] >= 'a' && s[i][j] <= 'z')
                d[i][1] = min(d[i][1], x);

            else d[i][2] = min(d[i][2], x);
        }
    }

    int ans = 1e9;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
            {
                if(i != j && i != k && j != k)
                    ans = min(ans, d[i][0] + d[j][1] + d[k][2]);
            }

    cout << ans;
}