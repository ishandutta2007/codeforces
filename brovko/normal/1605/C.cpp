#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, k[1000005][3], p[1000005], last;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < 3; j++)
            {
                k[i + 1][j] = k[i][j];

                if(s[i] - 'a' == j)
                    k[i + 1][j]++;
            }

        last = -1;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'a')
            {
                p[i] = last;
                last = i;
            }
        }

        int ans = 1e18;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'a')
            {
                if(p[i] > -1 && k[i + 1][1] - k[p[i]][1] < 2 && k[i + 1][2] - k[p[i]][2] < 2)
                    ans = min(ans, i - p[i] + 1);

                if(p[i] > -1 && p[p[i]] > -1 && k[i + 1][1] - k[p[p[i]]][1] < 3 && k[i + 1][2] - k[p[p[i]]][2] < 3)
                    ans = min(ans, i - p[p[i]] + 1);
            }
        }

        if(ans < 1e17)
            cout << ans << "\n";
        else cout << "-1\n";
    }
}