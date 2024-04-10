#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        int ans = 0;

        while(n % 6 == 0)
        {
            ans++;
            n /= 6;
        }

        while(n % 3 == 0)
        {
            ans += 2;
            n /= 3;
        }

        if(n == 1)
            cout << ans;
        else cout << -1;

        cout << "\n";
    }
}