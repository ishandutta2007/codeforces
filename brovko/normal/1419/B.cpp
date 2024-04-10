#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, x;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> x;

        int ans = 0, y = 1;

        while(x >= y * (y + 1) / 2)
        {
            x -= y * (y + 1) / 2;
            ans++;
            y = y * 2 + 1;
        }

        cout << ans << "\n";
    }
}