#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define li long long

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int Minx = 1e9, Miny = 1e9, Maxx = -1e9, Maxy = -1e9;

    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        Minx = min(Minx, x);
        Miny = min(Miny, y);
        Maxx = max(Maxx, x);
        Maxy = max(Maxy, y);
    }

    int ans = (Maxx - Minx) * (Maxy - Miny);

    if(ans == 0)
        cout << -1;
    else cout << ans;
}