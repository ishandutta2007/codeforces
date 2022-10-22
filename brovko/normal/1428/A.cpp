#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, a, b, c, d;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> a >> b >> c >> d;

        int ans = abs(a - c) + abs(b - d);

        if(a != c && b != d)
            ans += 2;

        cout << ans << "\n";
    }


}