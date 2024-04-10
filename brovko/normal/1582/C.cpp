#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[100005];
string s, p;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> s;
        int ans = 1e18;

        for(char c = 'a'; c <= 'z'; c++)
        {
            p = "";

            for(int i = 0; i <= n; i++)
                a[i] = 0;

            int y = 0;

            for(int i = 0; i < n; i++)
            {
                if(s[i] == c)
                    a[y]++;
                else
                {
                    p += s[i];
                    y++;
                }
            }

            int F = 1;

            for(int i = 0; i < y; i++)
                if(p[i] != p[y - 1 - i])
                    F = 0;

            int k = y;

            for(int i = 0; i <= y; i++)
                k += min(a[i], a[y - i]);

            if(F)
                ans = min(ans, n - k);
        }

        if(ans > 1e17)
            cout << "-1\n";
        else cout << ans << "\n";
    }
}