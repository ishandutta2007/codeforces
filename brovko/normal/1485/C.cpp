#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, x, y;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> x >> y;

        int ans = 0;

        for(int i = 1; i < min(x, 40000ll); i++)
        {
            ans += i * (min(x / i, y + 1) - min(x / (i + 1), y + 1));
        }

        for(int i = 2; i <= min(40000ll, y + 1); i++)
        {
            if(x / i >= 40000)
                ans += x / i;

            if(i - 2 < x / i)
                ans += i - 2 - x / i;
        }

        cout << ans << "\n";
    }
}