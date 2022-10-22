#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t, n, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        string s;
        cin >> s;

        int x = 0;

        while(s[x] == '.')
            x++;

        int ans = 1;

        while(true)
        {
            int y = min(n - 1, x + k);

            while(s[y] == '.')
                y--;

            if(y > x)
            {
                x = y;
                ans++;
            }
            else break;
        }

        cout << ans << "\n";
    }
}