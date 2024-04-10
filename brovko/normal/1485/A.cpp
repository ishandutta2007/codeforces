#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> a >> b;

        int ans = 1e9;

        for(int i = 0; i < 40; i++)
            if(b + i > 1)
            {
                int x = a, y = i;

                while(x)
                {
                    x /= (b + i);
                    y++;
                }

                ans = min(ans, y);
            }

        cout << ans << "\n";
    }
}