#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int m, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> b;

    int ans = 0;

    for(int y = 0; y <= b; y++)
    {
        int x = m * (b - y);

        ans = max(ans, y * (y + 1) / 2 * (x + 1) + x * (x + 1) / 2 * (y + 1));
    }

    cout << ans;
}