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

        int ans = abs(a - b);

        if(ans == 0)
            cout << "0 0\n";
        else cout << ans << ' ' << min(a % ans, ans - a % ans) << "\n";
    }
}